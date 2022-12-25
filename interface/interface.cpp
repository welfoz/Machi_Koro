#include <QInputDialog>
#include <QComboBox>
#include "interface.h"
#include "../game/game.h"
#include "../game/controller/control.h"
#include "../Qt/viewMessage.h"
#include "../Qt/viewSetting.h"

Interface* Interface::createInterfaceFromOption(Option type)
{
    switch (type) {
	case Option::cli:
		return new Cli();
    case Option::gui:
        return new Gui();
    case Option::cliGreenValley:
		return new GreenValleyCli();
	default:
		throw "sa mere";
    }
}

void Cli::printWelcomingMessage() {
    cout<< "\n\n";
    cout << "███    ███  █████   ██████ ██   ██ ██     ██   ██  ██████  ██████   ██████  \n";
    cout << "████  ████ ██   ██ ██      ██   ██ ██     ██  ██  ██    ██ ██   ██ ██    ██ \n";
    cout << "██ ████ ██ ███████ ██      ███████ ██     █████   ██    ██ ██████  ██    ██ \n";
    cout << "██  ██  ██ ██   ██ ██      ██   ██ ██     ██  ██  ██    ██ ██   ██ ██    ██ \n";
    cout << "██      ██ ██   ██  ██████ ██   ██ ██     ██   ██  ██████  ██   ██  ██████  \n";

    cout << ".   .__. _,  ,           .__. _,  _, \n";
    cout << "|   |  |'_) /|     ___   [__]'_) '_) \n";
    cout << "|___|__|/_. .|.          |  |/_. /_. \n\n";

    cout << "Made with ❤️  by MICHEL Fabien - BROSSARD Felix - TAVERNE Jules - CORTY Pol - LEMERLE Xavier\n\n";
}

string Cli::getInputText() const {
	string text;
	getline(cin, text);
	return text;
}

// be careful! firstOption and secondOption HAS to be UTF-8. No accent.
bool Cli::confirmationDialog(string message, string firstOption, string secondOption) {
	string stopAnswer = "";
	while (Formatter::toLower(stopAnswer) != Formatter::toLower(firstOption) && Formatter::toLower(stopAnswer) != Formatter::toLower(secondOption)) {
		cout << message << " (" << firstOption << " | " << secondOption << ") : ";
		cin >> stopAnswer;
		cin.ignore();
	}
	if (Formatter::toLower(stopAnswer) == Formatter::toLower(secondOption)) {
		return false;
	}
	return true;
}

void Cli::printBasicMessage(string message) {
	cout << message;
}

size_t Cli::getInputNumber() {
	size_t number;
	cin >> number;
	cin.ignore();
	return number;
}

void Cli::printTurnCounter(size_t turnCounter) {
	cout << "\n\n-------------------------------------------------------------------------------";
	cout << "\n------------------------------- Turn number : " << turnCounter << " -------------------------------\n";
}

void Cli::printPlayerInformation(Player* player) const {
	cout << "\n\n-------------------------- Player : " << player->getUsername() << " - Money = " << Controller::getInstance().getGame()->getBank()->getAccount(player->getId())->getSolde() << " --------------------------\n\n";
}

void Cli::printMonuments(Player* player) const {
	cout << "\n" << player->getUsername() << "'s monuments: \n";
	vector<pair<string, unsigned int>> headerNames;
	headerNames = {
		{" Name", 31},
		{"Activated", 9},
		{"Price", 5},
		{"Type" , 20},
		{"Icon", 8},
		{"Effect", 50}
	};
	cout << Formatter::formatHeader(headerNames);
	for (auto it = player->getMonuments().begin(); it != player->getMonuments().end(); it++) {
		cout << " " << Formatter::format(it->first->getName(), headerNames[0].second - 1) << Formatter::format(std::to_string(it->second), headerNames[1].second) << Formatter::format(std::to_string(it->first->getPrice()), headerNames[2].second);
		cout << Formatter::format(BaseCard::typeToString(it->first->getType()), headerNames[3].second);
		cout << Formatter::format(it->first->getIcon()->getName(), headerNames[4].second);
		cout << it->first->getEffetDescription() << "\n";
	}
}

void Cli::printCards(Player* player) const {
	cout << "\n" << player->getUsername() << "'s cards: \n";
	vector<pair<string, unsigned int>> headerNames;
	headerNames = {
		{" Name", 31},
		{"Price", 5},
		{"Activation Nb", 13},
		{"Quantity", 8},
		{"Type" , 20},
		{"Icon", 8},
		{"Effect", 60}
	};
    cout << Formatter::formatHeader(headerNames);
	for (auto it = player->getCards().begin(); it != player->getCards().end(); it++) {
        if (it->second>0){
            // get all activation numbers
            string activationNumbers;
            size_t* actNumbers = it->first->getActivationNumbers();
            for (unsigned int i = 0; i < it->first->getNumberActivation(); i++) {
                activationNumbers += std::to_string(*actNumbers) + ' ';
                actNumbers++;
            }

            cout << " " << Formatter::format(it->first->getName(), headerNames[0].second - 1) << Formatter::format(std::to_string(it->first->getPrice()), headerNames[1].second) << Formatter::format(activationNumbers, headerNames[2].second);
            cout << Formatter::format(std::to_string(it->second), headerNames[3].second) << Formatter::format(BaseCard::typeToString(it->first->getType()), headerNames[4].second) << Formatter::format(it->first->getIcon()->getName(), headerNames[5].second) << it->first->getEffetDescription() << "\n";
        }

	}
}


void Cli::printDices(size_t* throws, size_t nb) const {
	for (unsigned int i = 0; i < nb; i++) {
		cout << "\nDice n°" << i + 1 << ": " << *throws << endl;
		throws++;
	}
}

void Cli::printBalances(Player** players) const {
    cout << "\nPlayer's balance after activation: \n";
    for (size_t i = 0; i < Controller::getInstance().getGame()->getNbPlayers(); i++) {
        cout << "   " << players[i]->getUsername() << " : " << Controller::getInstance().getGame()->getBank()->getAccount(players[i]->getId())->getSolde() << "\n";
    }
}


void Cli::printBoard() const {
	cout <<"\nBoard's cards: \n";
    vector<pair<string, unsigned int>> headerNames;
    headerNames = {
        {" Name", 31},
        {"Price", 5},
        {"Activation Nb", 13},
        {"Quantity", 8},
        {"Type" , 20},
        {"Icon", 8},
        {"Effect", 60}
	};
    cout << Formatter::formatHeader(headerNames);
    for (auto it = Controller::getInstance().getGame()->getBoard()->getCards().begin(); it != Controller::getInstance().getGame()->getBoard()->getCards().end(); it++) {
        // get all activation numbers
        string activationNumbers;
        size_t* actNumbers = it->first->getActivationNumbers();
        for (size_t i = 0; i < it->first->getNumberActivation(); i++) {
            activationNumbers += std::to_string(*actNumbers) + ' ';
            actNumbers++;
        }

        cout << " " << Formatter::format(it->first->getName(), headerNames[0].second - 1) << Formatter::format(std::to_string(it->first->getPrice()), headerNames[1].second) << Formatter::format(activationNumbers, headerNames[2].second);
        cout << Formatter::format(std::to_string(it->second), headerNames[3].second) << Formatter::format(BaseCard::typeToString(it->first->getType()), headerNames[4].second) << Formatter::format(it->first->getIcon()->getName(), headerNames[5].second) << it->first->getEffetDescription() << "\n";

    }
};


string Cli::selectOneCard() const {
	return getInputText();
};


void Cli::printError(const std::exception& message) const {
	std::cerr << message.what() << "\n";
};

Player* Cli::selectOnePlayerDifferentFromTheCurrentOne(Player* player) const {
    string name;
    bool loop = true;
    Player *p2;
    while (loop) {
        try {
            cout << "\nType the name of the player you want to trade a card with :" << endl;
			name = getInputText();
            p2 = Controller::getInstance().getGame()->getPlayerByName(name);
            if (p2 != player) loop = false;
            else cout << "Impossible" << endl;
        } catch (string error) {
            cout << error << endl;
        }
    }
	return p2;
}

EstablishmentCard* Cli::selectOneEstablishmentCardFromPlayer(Player* target, string message) const {// je vois pas le but de "decider"
    cout << target->getUsername() + "'s cards";
    printCards(target);
    string choosenCard;
    EstablishmentCard *takenCardPtr;
    bool loop = true;
    while (loop) {// we ask the user which card he want to take from that target
        try {
            cout << message << endl;
            fflush(stdin);
            getline(cin, choosenCard);
            takenCardPtr = target->getCardByName(choosenCard);
            if (takenCardPtr->getType() != Type::majorEstablishment) loop = false;
            else cout << "Untradable card" << endl;
        } catch (std::exception &error) {
            cout << error.what() << endl;
        }
    }
    return takenCardPtr;
};

Monument* Cli::selectMonumentCardFromCurrentPlayer(Player *player, std::string message) const {
    if (player->getNbMonumentsActivated()==0) return nullptr;
    printMonuments(player);
    
    string monument;
    Monument* monumentPtr;
    bool loop = true;
    while (loop) {// we ask the user which monument he wants to demolish
        try {
            cout << message << endl;
            cin.ignore();
            getline(cin, monument);
            monumentPtr = Controller::getInstance().getGame()->getMonumentByName(monument);
            if (player->getMonument(monument)) loop = false;
            else cout << "You haven't built this monument" << endl;
		} catch (const std::exception& e) {
			printError(e);
        }
    }
    return monumentPtr;
}

EstablishmentCard* Cli::selectOneCardOwnedByAnyPlayer(string message) const {
    Game* game=Controller::getInstance().getGame();
    for (size_t i=0; i<game->getNbPlayers();i++){
        printCards(&game->getPlayer(i));
    }

    string choosenCard;
    EstablishmentCard *chosenCardPtr;
    bool loop = true;
    while (loop) {// we ask the user which card he want to take from that target
        try {
            cout << message << endl;
            fflush(stdin);
            getline(cin, choosenCard);
            chosenCardPtr = Controller::getInstance().getGame()->getCardByName(choosenCard);
            if (chosenCardPtr->getType() != Type::majorEstablishment) loop = false;
            else cout << "Untradable card" << endl;
        } catch (std::exception &error) {
            cout << error.what() << endl;
        }
    }
    return chosenCardPtr;
}

void GreenValleyCli::printCards(Player* player) const {

    // to access getClosedCards function
    PlayerGreenValley* playerGreenValley = dynamic_cast<PlayerGreenValley*>(player);

    if (playerGreenValley != NULL) {
		cout << "\n" << player->getUsername() << "'s cards: \n";
		vector<pair<string, unsigned int>> headerNames;
		headerNames = {
				{" Name", 31},
				{"Closed", 9},
				{"Price", 5},
				{"Activation Nb", 13},
				{"Quantity", 8},
				{"Type" , 20},
				{"Icon", 8},
				{"Effect", 60}
		};
		cout << Formatter::formatHeader(headerNames);
		for (auto it = player->getCards().begin(); it != player->getCards().end(); it++) {
			if (it->second > 0) {
				// get all activation numbers
				string activationNumbers;
				size_t* actNumbers = it->first->getActivationNumbers();
				for (unsigned int i = 0; i < it->first->getNumberActivation(); i++) {
					activationNumbers += std::to_string(*actNumbers) + ' ';
					actNumbers++;
				}

				cout << " " << Formatter::format(it->first->getName(), headerNames[0].second - 1) << Formatter::format(std::to_string(playerGreenValley->getClosedCards().count(it->first)), headerNames[1].second) << Formatter::format(std::to_string(it->first->getPrice()), headerNames[2].second) << Formatter::format(activationNumbers, headerNames[3].second);
				cout << Formatter::format(std::to_string(it->second), headerNames[4].second) << Formatter::format(BaseCard::typeToString(it->first->getType()), headerNames[5].second) << Formatter::format(it->first->getIcon()->getName(), headerNames[6].second) << it->first->getEffetDescription() << "\n";
			}

		}
	}
    else {
		Cli::printCards(player);
	}

}

void Gui::printWelcomingMessage(){
    ViewMessage* viewMessage = new ViewMessage;
    viewMessage->viewWelcomingMessage();
}

void Gui::printBasicMessage(string message){
    ViewMessage* viewMessage = new ViewMessage;
    viewMessage->viewBasicMessage(QString::fromStdString(message));
}

string Gui::getInputText() const {
    return std::to_string(Controller::getInstance().getGame()->getNbPlayers());
    //Not working, but at least return something correct fro Controller::CreateAll()
}


void Gui::printTurnCounter(size_t turnCounter) {
    ViewMessage* viewMessage = new ViewMessage;
    viewMessage->viewBasicMessage(QString::number(static_cast<int>(turnCounter))
);
}

// WRONG IMPLEMENTATION
// JUST NEED TO RETURN SOMETHING TO COMPILE
EstablishmentCard* Gui::selectOneCardOwnedByAnyPlayer(string message) const {
	return Controller::getInstance().getGame()->getCardByName(message);
}

Interface::Extension Cli::chooseExtension() const {
    cout << "Hello, World!\n";
    cout << "Welcome to Machi Koro! Please choose the extension you want to play to:\n";
    char choice = '0';
    while ((choice != 'B') && (choice != 'M') && (choice != 'G') && (choice != 'D')){
        cout << "Available extensions: Basic (B), Marina (M), Green Valley (G), Deluxe (D).\n";
        cout << "Enter the name of the extension you want to play to (B/M/G/D): \n";
        cin >> choice;
        cin.ignore();
    }
    switch (choice)
    {
    case 'B':
        return Extension::Base;
    case 'M':{
        return Extension::Marina;
    }
    case 'G':{
        return Extension::GreenValley;
    }
    case 'D':
        return Extension::Deluxe;
    default:
        throw "Error extension not reconized";
        break;
    }
};


Interface::Extension Gui::chooseExtension() const {
    QStringList list = {
        "Base",
        "Marina",
        "Green Valley",
        "Deluxe"
    };

    QInputDialog *dialog = new QInputDialog();
    bool accepted;
    QString choice = dialog->getItem(0, "Choose The Extension", "Extensions:", list, 0, false, &accepted);

    if (accepted && !choice.isEmpty()) {
        if (choice == "Base") {
            return Extension::Base;
        } else if (choice == "Marina"){
            return Extension::Marina;
        } else if (choice == "Green Valley") {
            return Extension::GreenValley;
        } else if (choice == "Deluxe") {
            return Extension::Deluxe;
        }
    }
    throw "error";
}
