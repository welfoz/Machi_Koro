#include "control.h"
#include "../../extensions/Deluxe/deluxeExtension.h"
#include "../Qt/viewSet.h"

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

Controller::Controller(Interface* interface) : interface(interface) {
    if (interface == nullptr) {
        throw "ERROR: interface need to be defined to create a Controller";
    }
    instance = this;
    game = new Game();
};

 
void Controller::createAll() {
    //ViewSet* viewSet = new ViewSet;
    //viewSet->show();
    // For Qt : initialize the set

    interface->printWelcomingMessage();

    // create cards before players because players needs them to be created
    getGame()->createIcons();
    getGame()->createMonumentCards();
    getGame()->createEstablishmentCards();

    bool stop = false;
	while (!stop && getGame()->canAddNewPlayer()) {
        bool isAi=false;
        if (game->nbPlayers>1) isAi = interface->confirmationDialog("What type of player do you want to add ?","AI","Human"); //le premier joueur ne peut être une IA
		interface->printBasicMessage("\nEnter the name of the player number " + std::to_string(getGame()->nbPlayers + 1) + " : ");

		try {
			getGame()->createPlayer(interface->getInputText(), getGame()->nbPlayers,isAi);
		}
        catch (std::invalid_argument& error) {
            interface->printError(error);
            continue;
        }
		catch (std::out_of_range& error) {
            // get out of the while loop
            break;
		}

		if (!interface->confirmationDialog("Do you want to add another player", "Yes", "No")) {
			if (!getGame()->isMinimumNumbersOfPlayersReached()) {
				interface->printBasicMessage("The minimum number of player is : " + std::to_string(game->getMinimumNumerbOfPlayers()) + "\nPlease add more.\n");
            }
            else {
				stop = true;
            }
		}
	}
    if (!getGame()->canAddNewPlayer()) {
		interface->printBasicMessage("Limit of " + std::to_string(game->getMaximumNumerbOfPlayers()) + " players reached\n");
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
        interface->printBasicMessage("How many dice do you chose to roll ?\n");
        n = interface->getInputNumber(1,2);
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

    interface->init();

    size_t turnCounter = 1;
    getGame()->idCurrentPlayer = 0;
    while (getGame()->winner==nullptr) {
		interface->printTurnCounter(turnCounter);
        turn(getGame()->players[getGame()->idCurrentPlayer]);

        getGame()->idCurrentPlayer=(getGame()->idCurrentPlayer+1)%getGame()->nbPlayers;
        if (getGame()->idCurrentPlayer==1) turnCounter++;
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
    if (player->getMonument("Radio Tower")){
        if (interface->confirmationDialog("Do you want to re-roll the dice(s) ? ", "Yes", "No"),player->isAi()) {
            for (size_t i = 0; i < nb; i++) {
                throws[i] = game->dice.throwDice();
            }
            interface->printDices(throws, nb);
        }
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
    int choix = interface->getInputNumber(1,3);

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

            vector<string> context;
            for (auto it : game->board->getCards()) if (it.first->getPrice()<=game->getBank()->getAccount(player->getId())->getSolde()) context.push_back(it.first->getName());

            choice = interface->getInputText(context);

            try
            {
                card = getGame()->getCardByName(choice);
                getGame()->purchaseOneEstablismentCard(player, card);
            }
            catch(const std::exception& e)
            {
                interface->printError(e);

                if (interface->confirmationDialog("Do you want to change your action ?",  "Yes", "No")) {
                    action(player);
                    break;
                }

                card = nullptr;
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

            vector<string> context;
            for (auto it : game->monuments) if (!player->getMonument(it->getName()) && (it->getPrice()<=game->getBank()->getAccount(player->getId())->getSolde())) context.push_back(it->getName()); // to tell th AI what can be written

            choice = interface->getInputText(context);

            try {
				monument = getGame()->getMonumentByName(choice);
                game->purchaseOneMonument(player, monument);

            } catch (const std::exception &e) {
                interface->printError(e);

                if (interface->confirmationDialog("Do you want to change your action ?",  "Yes", "No")) {
                    action(player);
                    break;
                }

                monument = nullptr;
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

void Controller::tradeTwoEstablishmentCards(Player* p1, Player* p2, EstablishmentCard* card1, EstablishmentCard* card2) {
    game->tradeCards(p1, p2, card1, card2);
    interface->printBasicMessage(p1->getUsername() + " has taken " + card1->getName() + " from " + p2->getUsername() + " and gave " + card2->getName() + " in exchange.\n");
}
