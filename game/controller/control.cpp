#include "control.h"

Controller& Controller::getInstance(Interface* interface)
{
    if (instance == nullptr)
        instance = new Controller(interface);
    return *instance;
}

void Controller::freeInstance()
{
    delete instance;
    instance = nullptr;
}

Controller* Controller::instance = nullptr;

Controller::Controller(Interface* interface) {
    proxy = new Proxy(interface);
    instance = this;
    game = new Game();
};
 
void Controller::createAll() {
    //ViewSet* viewSet = new ViewSet;
    //viewSet->show();
    // For Qt : initialize the set

    proxy->getInterface(true)->printWelcomingMessage();

    // create cards before players because players needs them to be created
    getGame()->createIcons();
    getGame()->createMonumentCards();
    getGame()->createEstablishmentCards();

    bool stop = false;
    bool isAi;
	while (!stop && getGame()->canAddNewPlayer()) {
        isAi = proxy->getInterface(true)->confirmationDialog("What type of player do you want to add ?","AI","Human");
        proxy->getInterface(true)->printBasicMessage("\nEnter the name of the player number " + std::to_string(getGame()->nbPlayers + 1) + " : ");
        string name=proxy->getInterface(true)->getInputText();
		try {
			getGame()->createPlayer(name, getGame()->nbPlayers,isAi);
		}
        catch (std::invalid_argument& error) {
            proxy->getInterface(true)->printError(error);
            continue;
        }
		catch (std::out_of_range& error) {
            // get out of the while loop
            break;
		}
        proxy->getInterface(true)->printBasicMessage( name+ " added!\n");
		if (!proxy->getInterface(true)->confirmationDialog("Do you want to add another player", "Yes", "No")) {
			if (!getGame()->isMinimumNumbersOfPlayersReached()) {
                proxy->getInterface(true)->printBasicMessage("The minimum number of player is : " + std::to_string(game->getMinimumNumerbOfPlayers()) + "\nPlease add more.\n");
            }
            else {
				stop = true;
            }
		}
	}
    if (!getGame()->canAddNewPlayer()) {
        proxy->getInterface(true)->printBasicMessage("Limit of " + std::to_string(game->getMaximumNumerbOfPlayers()) + " players reached\n");
    }

	getGame()->createBank(getGame()->nbPlayers);
	getGame()->createBoard();


    //viewSet->setSet();
    //For Qt : print the board on the set
};

// gui: pop up and btns
const size_t Controller::getNbDiceChosen(Player& p) { // est appelé par le jeu seulement si le joueur posède station
    if (!p.getMonument("Train Station")) return 1;
    size_t n=0;
    while (n>2 || n<1){
        proxy->getInterface()->printBasicMessage("How many dice do you chose to roll ?\n");
        n = proxy->getInterface()->getInputNumber(1,2);
        if (n>2 || n<1) proxy->getInterface()->printBasicMessage("Please select a number between 1 and 2\n");
    }
    return n;
}

Controller::~Controller() {
    delete game;
    proxy->getInterface()->printBasicMessage("game deleted :)");
    delete proxy;
}; 

void Controller::match(){
    createAll();

    proxy->getInterface()->init();

    size_t turnCounter = 1;
    getGame()->idCurrentPlayer = 0;
    while (winner==nullptr) {
        proxy->getInterface()->printTurnCounter(turnCounter);
        turn(getGame()->players[getGame()->idCurrentPlayer]);

        getGame()->idCurrentPlayer=(getGame()->idCurrentPlayer+1)%getGame()->nbPlayers;
        if (getGame()->idCurrentPlayer==0) turnCounter++;
	};

    proxy->getInterface()->printBasicMessage("\n\n\n\n\n\nIT'S OVER!!!\n\nThe winner is...\n" + winner->getUsername() + " 🎉🎉🎉\n\n\nThank you for playing Machi Koro!\n\n");
};

// we ll not print cards in gui neither player information
void Controller::turn(Player* player){
    if (winner!= nullptr) return;

    proxy->getInterface()->printPlayerInformation(player);
    proxy->getInterface()->printMonuments(player);
    proxy->getInterface()->printCards(player);

    const size_t nb = getNbDiceChosen(*player);

    size_t* throws = getGame()->throwDices(nb);
    proxy->getInterface()->printDices(throws, nb);

    throws = activateRadioTower(player, nb, throws);

    getGame()->setDiceValue(nb, throws);

    vector<EstablishmentCard*> activatedGreenCards = getGame()->players[player->getId()]->activatedGreenCards(getGame()->diceValue);
    vector<EstablishmentCard*> activatedRedCards = getGame()->players[player->getId()]->activatedRedCards(getGame()->diceValue);

    getGame()->activation(player, game->diceValue);

    activateShoppingMall(player, activatedGreenCards);
    activateShoppingMall(player, activatedRedCards);

    proxy->getInterface()->printBalances(getGame()->players);

    action(player);

    activateAmusementPark(player, nb, throws);
};

size_t* Controller::activateRadioTower(Player* player, size_t nb, size_t* throws) const{
    if (player->getMonument("Radio Tower")){
        if (proxy->getInterface()->confirmationDialog("Do you want to re-roll the dice(s) ? ", "Yes", "No"),player->isAi()) {
            for (size_t i = 0; i < nb; i++) {
                throws[i] = game->dice.throwDice();
            }
            proxy->getInterface()->printDices(throws, nb);
        }
    }
    return throws;
}

void Controller::activateShoppingMall(Player* p, vector<EstablishmentCard*> cards) {
    if (!p->getMonument("Shopping Mall")) {
        return;
    }
    for (auto it : cards) {
        if (it->getIcon()->getName() == "bread" || it->getIcon()->getName() == "cup") {
            // no need to handle the case when Type::majorEstablishment and Type::primaryIndustry
            // because they never have bread or cup icon
            switch (it->getType()) {
            case (Type::restaurants):
                this->getGame()->getBank()->trade(p->getId(), p->getId(), 1);
                break;
            case(Type::secondaryIndustry):
                this->getGame()->getBank()->credit(p->getId(), 1);
                break;
            default:
                break;
            }
        }
    }
}

void Controller::activateAmusementPark(Player* player, size_t nb, size_t* throws) {
    if (nb==2 && throws[0]==throws[1] && player->getMonument("Amusement Park") && !player->isPlaying) {
        player->isPlaying=true;
        turn(player);
        player->isPlaying=false;
    }
}

bool Controller::isWinner(Player *player) const {
    for (auto it = player->getMonuments().begin(); it != player->getMonuments().end(); it++) {
        if (!it->second) return false;
    }
    return true;
}

void Controller::action(Player* player){

    proxy->getInterface()->printBasicMessage( "\nWhat do you want to do? (1 = Buy an establishment, 2 = Build a monument, 3 = Nothing!)\n");
    int choix = proxy->getInterface()->getInputNumber(1,3);

    switch (choix){
    case 1:
    {
        if (!getGame()->board->isAnyCardLeftToBuy()) {
            proxy->getInterface()->printBasicMessage("\nNo card left on the board\n");
            action(player);
            break;
        }
        if (!getGame()->isPlayerAbleToPayEstablishmentCard(player)) {
            proxy->getInterface()->printBasicMessage("\nYou don't have enough money...\n");
            action(player);
            break;
        }

        proxy->getInterface()->printBoard();

        // gui: click on card
        string choice;
        EstablishmentCard* card = nullptr;
        while (card == nullptr){
            // reflexion: do we need another function called askForCardToBuy ?
            proxy->getInterface()->printBasicMessage( "Enter the name of the card you want to buy : ");

            vector<string> context;
            for (auto it : game->board->getCards()) if (it.first->getPrice()<=game->getBank()->getAccount(player->getId())->getSolde()) context.push_back(it.first->getName());

            choice = proxy->getInterface()->getInputText(context);

            try
            {
                card = getGame()->getCardByName(choice);
                getGame()->purchaseOneEstablismentCard(player, card);
            }
            catch(const std::exception& e)
            {
                proxy->getInterface()->printError(e);

                if (proxy->getInterface()->confirmationDialog("Do you want to change your action ?",  "Yes", "No")) {
                    action(player);
                    break;
                }

                card = nullptr;
                continue;
            }

            proxy->getInterface()->printCards(player);

            if (proxy->getInterface()->confirmationDialog("Do you want to change your action ?", "Yes", "No")) {
                if (card != nullptr) {
                    getGame()->undoPurchaseOneEstablismentCard(player, card);

                    proxy->getInterface()->printPlayerInformation(player);
                    proxy->getInterface()->printMonuments(player);
                    proxy->getInterface()->printCards(player);
                }
                action(player);
                break;
            }
        }
        break;
    }
    case 2:
    {
        if (!player->isAnyMonumentLeftToBuy()) {
            proxy->getInterface()->printBasicMessage("\nNo monument left on the board\n");
            action(player);
            break;
        }
        if (!getGame()->isPlayerAbleToPayMonument(player)) {
            proxy->getInterface()->printBasicMessage("\nYou don't have enough money...\n");
            action(player);
            break;
        }

        proxy->getInterface()->printMonuments(player);

        string choice;
        Monument* monument = nullptr;
        while (monument == nullptr) {

            // same as card
            // new method interface askForOneMonument()
            proxy->getInterface()->printBasicMessage("Enter the name of the monument you want to buy : ");

            vector<string> context;
            for (auto it : game->monuments) if (!player->getMonument(it->getName()) && (it->getPrice()<=game->getBank()->getAccount(player->getId())->getSolde())) context.push_back(it->getName()); // to tell th AI what can be written

            choice = proxy->getInterface()->getInputText(context);

            try {
				monument = getGame()->getMonumentByName(choice);
                game->purchaseOneMonument(player, monument);

            } catch (const std::exception &e) {
                proxy->getInterface()->printError(e);

                if (proxy->getInterface()->confirmationDialog("Do you want to change your action ?",  "Yes", "No")) {
                    action(player);
                    break;
                }

                monument = nullptr;
                continue;
            }

            proxy->getInterface()->printMonuments(player);

            if (proxy->getInterface()->confirmationDialog("Do you want to change your action ?",  "Yes", "No")) {
                if (monument != nullptr) {
                    game->undoPurchaseOneMonument(player, monument);

                    proxy->getInterface()->printPlayerInformation(player);
                    proxy->getInterface()->printMonuments(player);
                    proxy->getInterface()->printCards(player);
                }
                action(player);
                break;
            }
        }
        if (isWinner(player)) winner = player;
        break;
    }
    default:
        break;
    } 
};

void Controller::tradeTwoEstablishmentCards(Player* p1, Player* p2, EstablishmentCard* card1, EstablishmentCard* card2) {
    game->tradeCards(p1, p2, card1, card2);
    proxy->getInterface()->printBasicMessage(p1->getUsername() + " has taken " + card1->getName() + " from " + p2->getUsername() + " and gave " + card2->getName() + " in exchange.\n");
}

Interface* Controller::getInterface(bool gameCreation) {
    return proxy->getInterface(gameCreation);
}
