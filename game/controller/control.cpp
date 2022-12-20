#include "control.h"
#include "../../extensions/Deluxe/deluxeExtension.h"

Controller& Controller::getInstance()
{
    if (instance == nullptr)
        instance = new Controller;
    return *instance;
}

void Controller::freeInstance()
{
    delete instance;
    instance = nullptr;
}

Controller* Controller::instance = nullptr;

Controller::Controller(Interface::Option type) : interface(Interface::createInterfaceFromOption(type)) {
    instance = this;
    game = new Game();
};

 
void Controller::createAll() {
    interface->printWelcomingMessage();

    // create cards before players because players needs them to be created
    getGame()->createIcons();
    getGame()->createMonumentCards();
    getGame()->createEstablishmentCards();

    bool stop = false;
	while (!stop && getGame()->canAddNewPlayer()) {

		interface->printBasicMessage("\nEnter the name of the player number " + std::to_string(getGame()->nbPlayers + 1) + " : ");

		try {
			getGame()->createPlayer(interface->getInputText(), getGame()->nbPlayers);
		}
        catch (std::invalid_argument& error) {
            interface->printBasicMessage("Error : name already used\n");
            continue;
        }
		catch (std::out_of_range& error) {
            // get out of the while loop
            break;
		}

		if (!interface->confirmationDialog("Do you want to add another player", "Yes", "No")) {
			stop = true;
		}
	}
    if (!getGame()->canAddNewPlayer()) {
		interface->printBasicMessage("Limit of 10 players reached\n");
    }

	getGame()->createBank(getGame()->nbPlayers);
	getGame()->createBoard();
};

// gui: pop up and btns
const size_t Controller::getNbDiceChosen(Player& p) { // est appelé par le jeu seulement si le joueur posède station
    if (!p.getMonument("Train Station")) return 1;
    size_t n=0;
    while (n>2 || n<1){
        interface->printBasicMessage("How many dice do you chose to roll ?\n");
        n = interface->getInputNumber();
        if (n>2 || n<1) interface->printBasicMessage("Please select a number between 1 and 2\n");
    }
    return n;
}

Controller::~Controller() {
    delete game;
    interface->printBasicMessage("game deleted :)");
    delete interface;
}; 

void Controller::match(){
    createAll();

    size_t turnCounter = 1;
    getGame()->idCurrentPlayer = 0;
    while (getGame()->winner==nullptr) {
		interface->printTurnCounter(turnCounter);
        turn(getGame()->players[getGame()->idCurrentPlayer]);

        getGame()->idCurrentPlayer=(getGame()->idCurrentPlayer+1)%getGame()->nbPlayers;
        turnCounter++;
	};

	interface->printBasicMessage("\n\n\n\n\n\nIT'S OVER!!!\n\nThe winner is...\n" + getGame()->winner->getUsername() + " 🎉🎉🎉\n\n\nThank you for playing Machi Koro!\n\n");
};

// we ll not print cards in gui neither player information
void Controller::turn(Player* player){
    if (getGame()->winner!= nullptr) return;

    interface->printPlayerInformation(player);
    interface->printMonuments(player);
    interface->printCards(player);

    const size_t nb = getNbDiceChosen(*player);

    size_t* throws = getGame()->throwDices(nb);
    interface->printDices(throws, nb);

    throws = activateRadioTower(player, nb, throws);

    getGame()->setDiceValue(nb, throws);

    getGame()->activation(player, game->diceValue);

    interface->printBalances(getGame()->players);

    action(player);

    activateAmusementPark(player, nb, throws);
};

size_t* Controller::activateRadioTower(Player* player, size_t nb, size_t* throws) const{
    if (player->getMonument("Radio Tower") && interface->confirmationDialog("Do you want to re-roll the dice(s) ? ", "Yes", "No")) {
		for (size_t i = 0; i < nb; i++) {
			throws[i] = game->dice.throwDice();
		}
        interface->printDices(throws, nb);
    }
    return throws;
}

void Controller::activateAmusementPark(Player* player, size_t nb, size_t* throws) {
    if (nb==2 && throws[0]==throws[1] && player->getMonument("Amusement Park") && !player->isPlaying) {
        player->isPlaying=true;
        turn(player);
        player->isPlaying=false;
    }
}

void Controller::action(Player* player){
    
    interface->printBasicMessage( "\nWhat do you want to do? (1 = Buy an establishment, 2 = Build a monument, 3 = Nothing!)\n");
    int choix = interface->getInputNumber();

    switch (choix){
    case 1:
    {
        if (!getGame()->board->isAnyCardLeftToBuy()) {
			interface->printBasicMessage("\nNo card left on the board\n");
            action(player);
            break;
        }
        if (!getGame()->isPlayerAbleToPayEstablishmentCard(player)) {
            interface->printBasicMessage("\nYou don't have enough money...\n");
            action(player);
            break;
        }

        interface->printBoard();

        // gui: click on card
        string choice;
        EstablishmentCard* card = nullptr;
        while (card == nullptr){
            // reflexion: do we need another function called askForCardToBuy ?
            interface->printBasicMessage( "Enter the name of the card you want to buy : ");
            choice = interface->getInputText();

            try
            {
                card = getGame()->getCardByName(choice);
                getGame()->purchaseOneEstablismentCard(player, card);
            }
            catch(const std::exception& e)
            {
                interface->printError(e);
                continue;
            }

			interface->printCards(player);

            if (interface->confirmationDialog("Do you want to change your action ?", "Yes", "No")) {
                if (card != nullptr) {
                    getGame()->undoPurchaseOneEstablismentCard(player, card);

					interface->printPlayerInformation(player);
					interface->printMonuments(player);
					interface->printCards(player);
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
			interface->printBasicMessage("\nNo monument left on the board\n");
            action(player);
            break;
        }
        if (!getGame()->isPlayerAbleToPayMonument(player)) {
            interface->printBasicMessage("\nYou don't have enough money...\n");
            action(player);
            break;
        }

        interface->printMonuments(player);

        string choice;
        Monument* monument = nullptr;
        while (monument == nullptr) {
            
            // same as card
            // new method interface askForOneMonument()
            interface->printBasicMessage("Enter the name of the monument you want to buy : ");
            choice = interface->getInputText();

            try {
				monument = getGame()->getMonumentByName(choice);
                game->purchaseOneMonument(player, monument);

            } catch (const std::exception &e) {
                interface->printError(e);
                continue;
            }

			interface->printMonuments(player);

            if (interface->confirmationDialog("Do you want to change your action ?",  "Yes", "No")) {
                if (monument != nullptr) {
                    game->undoPurchaseOneMonument(player, monument);

					interface->printPlayerInformation(player);
					interface->printMonuments(player);
					interface->printCards(player);
                }
                action(player);
                break;
            }
        }
        if (getGame()->isWinner(player)) getGame()->winner=player;
        break;
    }
    default:
        break;
    } 
};

MarinaController::MarinaController() : Controller() {
    delete game;
	game = dynamic_cast<Marina*>(new Marina);
};

MarinaController& MarinaController::getInstance()
{
    if (instance == nullptr)
        instance = new MarinaController;
    return dynamic_cast<MarinaController&>(*instance);
}

void MarinaController::turn(Player* player) {
    if (getGame()->getWinner()!= nullptr) return;

    interface->printPlayerInformation(player);
    interface->printMonuments(player);
    interface->printCards(player);

    activateCityHall(player);

    const size_t nb = getNbDiceChosen(*player);

    size_t* throws = getGame()->throwDices(nb);
    interface->printDices(throws,nb);

    throws = activateRadioTower(player, nb, throws);

    getGame()->setDiceValue(nb,throws);
    getGame()->diceValue= this->activateHarbor(getGame()->diceValue,player);

    getGame()->activation(player, game->diceValue);

    interface->printBalances(game->players);

    map<Monument*,bool> playerMonuments = player->getMonuments();
    map<EstablishmentCard*,size_t> playerCards = player->getCards();

    action(player);

    dynamic_cast<MarinaBoard*>(getGame()->board)->checkNumberOfDecks();

    if (player->getMonuments() == playerMonuments || player->getCards() == playerCards)
        activateAirport(player);

    activateAmusementPark(player, nb, throws);
}


void MarinaController::activateCityHall(Player* player){
    if (Controller::getInstance().getGame()->getBank()->getAccount(player->getId())->getSolde() == 0)
        Controller::getInstance().getGame()->getBank()->credit(player->getId(), 1);
}


size_t MarinaController::activateHarbor(size_t diceValue, Player* player){
    if (diceValue >= 10 && player->getMonument("Harbor") && interface->confirmationDialog("Do you want to add 2 to the dice value ?","Yes","No")) return diceValue + 2;
    else return diceValue;
}

void MarinaController::activateAirport(Player* player){
    if (player->getMonument("Airport")) Controller::getInstance().getGame()->getBank()->credit(player->getId(), 10);
}

GreenValleyController::GreenValleyController() : Controller() {
    delete game;
	game = dynamic_cast<GreenValley*>(new GreenValley);
};

GreenValleyController& GreenValleyController::getInstance(){
    if (instance == nullptr)
        instance = new GreenValleyController();
    return dynamic_cast<GreenValleyController&>(*instance);
}

void GreenValleyController::turn(Player* player) {
    Controller::turn(player);
    hasBoughtLoanOffice(player);
    techStartupInvestment(player);
}
void GreenValleyController::techStartupInvestment(Player* player) {
    auto *techStartup = dynamic_cast<TechStartup *>(game->getCardByName("Tech Startup"));
    if (player->getCards().count(techStartup) && game->getBank()->getAccount(player->getId())->getSolde() >= 1) {
        if (interface->confirmationDialog("Do you want to invest on Tech Startup ?", "Yes", "No")) {
            techStartup->invest(player, 1);
            game->getBank()->debit(player->getId(), 1);
        }

    }
}
void GreenValleyController::hasBoughtLoanOffice(Player *player) {
    auto loanOffice = dynamic_cast<LoanOffice*>(game->getCardByName("Loan Office"));
    if (loanOffice->buyingPlayer==player){
        game->getBank()->credit(player->getId(),5);
        loanOffice->buyingPlayer= nullptr;
    }
}

void Controller::tradeTwoEstablishmentCards(Player* p1, Player* p2, EstablishmentCard* card1, EstablishmentCard* card2) {
    game->tradeCards(p1, p2, card1, card2);
    interface->printBasicMessage(p1->getUsername() + " has taken " + card1->getName() + " from " + p2->getUsername() + " and gave " + card2->getName() + " in exchange.\n");
}

DeluxeController::DeluxeController() : Controller() {
    delete game;
    game = dynamic_cast<Deluxe*>(new Deluxe());
};

DeluxeController& DeluxeController::getInstance(){
    if (instance == nullptr)
        instance = new DeluxeController();
    return dynamic_cast<DeluxeController&>(*instance);
}

void DeluxeController::turn(Player* player){
    MarinaController::turn(player);
    hasBoughtLoanOffice(player);
    techStartupInvestment(player);
}