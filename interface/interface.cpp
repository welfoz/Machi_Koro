#include "interface.h"
#include "../game/game.h"

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
bool Cli::isPlayerWantsToContinue(string message, string firstOption, string secondOption) {
	string stopAnswer = "";
	//while ((stopAnswer != "Y") && (stopAnswer != "y") && (stopAnswer != "N") && (stopAnswer != "n")) {
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
	cout << "\n\n-------------------------- Player : " << player->getUsername() << " - Money = " << Game::getInstance().getBank()->getAccount(player->getId())->getSolde() << " --------------------------\n\n";
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


void Cli::printDice(size_t diceNumber, size_t diceValue) const {
	cout << "\nDice n°" << diceNumber << ": " << diceValue << endl;
}

void Cli::printBalances(Player** players) const {
    cout << "\nPlayer's balance after activation: \n";
    for (size_t i = 0; i < Game::getInstance().getNbPlayers(); i++) {
        cout << "   " << players[i]->getUsername() << " : " << Game::getInstance().getBank()->getAccount(players[i]->getId())->getSolde() << "\n";
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
    for (auto it = Game::getInstance().getBoard()->getCards().begin(); it != Game::getInstance().getBoard()->getCards().end(); it++) {
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
            p2 = Game::getInstance().getPlayerByName(name);
            if (p2 != player) loop = false;
            else cout << "Impossible" << endl;
        } catch (string error) {
            cout << error << endl;
        }
    }
	return p2;
}

EstablishmentCard* Cli::selectOneEstablishmentCardFromPlayer(Player* player, string message) const {
    cout << player->getUsername() + "'s cards";
    printCards(player);

    string choosenCard;
    EstablishmentCard *takenCardPtr;
    bool loop = true;
    while (loop) {// we ask the user which card he want to take from that player
        try {
            cout << message << endl;
            fflush(stdin);
            getline(cin, choosenCard);
            takenCardPtr = player->getCardByName(choosenCard);
            if (takenCardPtr->getType() != Type::majorEstablishment) loop = false;
            else cout << "Untradable card" << endl;
        } catch (std::exception &error) {
            cout << error.what() << endl;
        }
    }
    return takenCardPtr;
};

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
