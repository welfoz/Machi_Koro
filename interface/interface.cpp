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

string Cli::getInputText(vector<string> context) const {// context give the context to the AI
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

void Cli::printBasicMessage(string message) const {
	cout << message;
}

size_t Cli::getInputNumber(size_t min, size_t max) {
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
}

Player* Cli::selectOnePlayerDifferentFromTheCurrentOne(Player* player) const {
    Player *p2;
    Game* game = Controller::getInstance().getGame();
    string name;
    bool loop = true;
    while (loop) {
        try {
            cout << "\nType the name of the player you want to trade a card with :" << endl;
            name = getInputText();
            p2 = game->getPlayerByName(name);
            if (p2 != player) loop = false;
            else cout << "Impossible" << endl;
        } catch (string error) {
            cout << error << endl;
        }
    }
	return p2;
}

EstablishmentCard* Cli::selectOneEstablishmentCardFromPlayer(Player* target, string message) const {
    cout << target->getUsername() + "'s cards";
    printCards(target);
    EstablishmentCard *takenCardPtr;
    string choosenCard;
    bool loop = true;
    while (loop) {// we ask the user which card he want to take from that target
        try {
            cout << message << endl;
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
    Monument* monumentPtr;
    string monument;
    bool loop = true;
    while (loop) {
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
    EstablishmentCard *chosenCardPtr;
    string chosenCard;
    bool loop = true;
    while (loop) {// we ask the user which card he want to take from that target
        try {
            cout << message << endl;
            fflush(stdin);
            getline(cin, chosenCard);
            chosenCardPtr = Controller::getInstance().getGame()->getCardByName(chosenCard);
            bool owned=false;
            for (size_t i=0;i<game->getNbPlayers() && !owned ;i++){ // we check if at least one player own the chosen card
                if (game->getPlayer(i).getCards().count(chosenCardPtr)) owned =true;
            }
            if (chosenCardPtr->getType() != Type::majorEstablishment && owned) loop = false;
            else cout << "Non-renewable card" << endl;
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
EstablishmentCard* Gui::selectOneCardOwnedByAnyPlayer(string message,bool isAi) const {
	return Controller::getInstance().getGame()->getCardByName(message);
}

size_t AiCli::getInputNumber(size_t min, size_t max) {
    vector<size_t> options;
    for (size_t i=min; i<= max;i++) options.push_back(i);
    size_t number;
    number= getAiChoice(options);
    return number;
}

template<typename t>
t AiCli::getAiChoice(std::vector<t> options, std::vector<t> exceptions) const {
    if (exceptions.size() > 0)
        for (auto it: exceptions)
            if (count(options.begin(), options.end(), it)) std::remove(options.begin(), options.end(), it);
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, options.size() - 1);
    return options[dist(rng)]; // renvoie un élément situé à un index aléatoire entre le début et la fin du vector
}

bool AiCli::confirmationDialog(string message, string firstOption, string secondOption) {
    string stopAnswer="";
    stopAnswer=getAiChoice(vector<string>({firstOption,secondOption}));
    if (Formatter::toLower(stopAnswer) == Formatter::toLower(secondOption)) {
        return false;
    }
    return true;
}

string AiCli::getInputText(vector<string> context) const{
    string text="";
    text=getAiChoice(context);
    printBasicMessage("\n"+text);
    return text;
}

EstablishmentCard *AiCli::selectOneCardOwnedByAnyPlayer(string message) const {
    EstablishmentCard* chosenCardPtr;
    Game* game=Controller::getInstance().getGame();
    vector<EstablishmentCard*> options;
    for (size_t j =0;j<game->getNbPlayers();j++){
        for (auto it : game->getPlayer(j).getCards()) options.push_back(it.first);
    }
    chosenCardPtr= getAiChoice(options);
    return chosenCardPtr;
}

Player *AiCli::selectOnePlayerDifferentFromTheCurrentOne(Player *player) const {
    Player *p2;
    Game* game = Controller::getInstance().getGame();
    p2= getAiChoice(game->getPlayers(),vector<Player*> ({player}));
    return p2;
}

EstablishmentCard *AiCli::selectOneEstablishmentCardFromPlayer(Player *target, string message) const {
    EstablishmentCard *takenCardPtr;
    vector<EstablishmentCard*> options;
    for (auto it : target->getCards()) if (it.first->getType()!=Type::majorEstablishment) options.push_back(it.first);
    takenCardPtr= getAiChoice(options);
    return takenCardPtr;
}

Monument *AiCli::selectMonumentCardFromCurrentPlayer(Player *player, string message) const {
    Monument* monumentPtr;
    vector<Monument*> options;
    for (auto it : player->getMonuments()) if (it.second) options.push_back(it.first);
    monumentPtr= getAiChoice(options);
    return monumentPtr;
}
