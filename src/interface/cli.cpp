#include "./cli.h"

string Cli::format(string text, unsigned int maxLenght) const {
    string spaces(maxLenght - text.length(), ' ');
    string separator = " | ";
	return text + spaces + separator;
};

string Cli::formatHeader(vector<pair<string, unsigned int>> texts) const {
    string header;
    string separator = " | ";
    string lineSeparator;
    for (auto it = texts.begin(); it != texts.end(); it++) {
        if (it->second == 0) {
            header += it->first;
            lineSeparator += string(20, '-');
        }
        else {
			header += it->first + string(it->second - it->first.length(), ' ') + separator;
            lineSeparator += string(it->second + separator.length(), '-');
        }
    }
    return header + "\n" + lineSeparator + "\n";
}

string Cli::toLower(string text) const {
    std::transform(text.begin(), text.end(), text.begin(),
        [](unsigned char c) { return std::tolower(c); });
    return text;
}

void Cli::printWelcomingMessage() const{
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

string Cli::getInputText(vector<string> context) const {
    string text;
    getline(cin, text);
    return text;
}

// be careful! firstOption and secondOption HAS to be UTF-8. No accent.
bool Cli::confirmationDialog(string message, string firstOption, string secondOption)const {
    string stopAnswer = "";
    while (toLower(stopAnswer) != toLower(firstOption) && toLower(stopAnswer) != toLower(secondOption)) {
        cout << message << " (" << firstOption << " | " << secondOption << ") : ";
        cin >> stopAnswer;
        cin.ignore();
    }
    if (toLower(stopAnswer) == toLower(secondOption)) {
        return false;
    }
    return true;
}

void Cli::printBasicMessage(string message) const{
    cout << message<<endl;
}

size_t Cli::getInputNumber(size_t min, size_t max) const{
    size_t number;
    cin >> number;
    cin.ignore();
    return number;
}

void Cli::printTurnCounter(size_t turnCounter) const{
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
    cout << formatHeader(headerNames);
    for (auto it = player->getMonuments().begin(); it != player->getMonuments().end(); it++) {
        cout << " " << format(it->first->getName(), headerNames[0].second - 1) << format(std::to_string(it->second), headerNames[1].second) << format(std::to_string(it->first->getPrice()), headerNames[2].second);
        cout << format(BaseCard::typeToString(it->first->getType()), headerNames[3].second);
        cout << format(it->first->getIcon()->getName(), headerNames[4].second);
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
    cout << formatHeader(headerNames);
    for (auto it = player->getCards().begin(); it != player->getCards().end(); it++) {
        if (it->second>0){
            // get all activation numbers
            string activationNumbers;
            size_t* actNumbers = it->first->getActivationNumbers();
            for (unsigned int i = 0; i < it->first->getNumberActivation(); i++) {
                activationNumbers += std::to_string(*actNumbers) + ' ';
                actNumbers++;
            }

            cout << " " << format(it->first->getName(), headerNames[0].second - 1) << format(std::to_string(it->first->getPrice()), headerNames[1].second) << format(activationNumbers, headerNames[2].second);
            cout << format(std::to_string(it->second), headerNames[3].second) << format(BaseCard::typeToString(it->first->getType()), headerNames[4].second) << format(it->first->getIcon()->getName(), headerNames[5].second) << it->first->getEffetDescription() << "\n";
        }

    }
}


void Cli::printDices(size_t* throws, size_t nb) const {
    for (unsigned int i = 0; i < nb; i++) {
        cout << "\nDice n°" << i + 1 << ": " << *throws << endl;
        throws++;
    }
}

void Cli::printBalances(Player** players){
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
    cout << formatHeader(headerNames);
    for (auto it = Controller::getInstance().getGame()->getBoard()->getCards().begin(); it != Controller::getInstance().getGame()->getBoard()->getCards().end(); it++) {
        // get all activation numbers
        string activationNumbers;
        size_t* actNumbers = it->first->getActivationNumbers();
        for (size_t i = 0; i < it->first->getNumberActivation(); i++) {
            activationNumbers += std::to_string(*actNumbers) + ' ';
            actNumbers++;
        }

        cout << " " << format(it->first->getName(), headerNames[0].second - 1) << format(std::to_string(it->first->getPrice()), headerNames[1].second) << format(activationNumbers, headerNames[2].second);
        cout << format(std::to_string(it->second), headerNames[3].second) << format(BaseCard::typeToString(it->first->getType()), headerNames[4].second) << format(it->first->getIcon()->getName(), headerNames[5].second) << it->first->getEffetDescription() << "\n";

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
        cout << formatHeader(headerNames);
        for (auto it = player->getCards().begin(); it != player->getCards().end(); it++) {
            if (it->second > 0) {
                // get all activation numbers
                string activationNumbers;
                size_t* actNumbers = it->first->getActivationNumbers();
                for (unsigned int i = 0; i < it->first->getNumberActivation(); i++) {
                    activationNumbers += std::to_string(*actNumbers) + ' ';
                    actNumbers++;
                }

                cout << " " << format(it->first->getName(), headerNames[0].second - 1) << format(std::to_string(playerGreenValley->getClosedCards().count(it->first)), headerNames[1].second) << format(std::to_string(it->first->getPrice()), headerNames[2].second) << format(activationNumbers, headerNames[3].second);
                cout << format(std::to_string(it->second), headerNames[4].second) << format(BaseCard::typeToString(it->first->getType()), headerNames[5].second) << format(it->first->getIcon()->getName(), headerNames[6].second) << it->first->getEffetDescription() << "\n";
            }

        }
    }
    else {
        Cli::printCards(player);
    }

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
}

void Cli::delay() const {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
};

