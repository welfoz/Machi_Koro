
#include "game.h"

Game* Game::getInstance()
{
    if (instance == nullptr)
        instance = new Game;
    return instance;
}

void Game::freeInstance()
{
    delete instance;
    instance = nullptr;
}

Game* Game::instance = nullptr;

Game::Game() : dice(Dice()), board(nullptr), bank(nullptr), winner(nullptr) {
};

void Game::createAll() {
    cout << "You're going to start a Machi Koro part\n";

    // create cards before players because players needs them to be created
    createMonumentCards();
    createEstablishmentCards();

    // create all players
    // ask number of players and their names
    unsigned int cpt = 0;
    string name;
    bool stop = false;
    string stopAnswer;
    while (cpt <= 10 && !stop) {
		cout << "Enter the name of the player number " << cpt + 1 << '\n';
        cin >> name;
		createPlayer(name, cpt);
        cout << "\n";
        cout << "Do you want to add another player ? (Y/N)";
        cin >> stopAnswer;
        if (stopAnswer == "n" || stopAnswer == "N") {
            stop = true;
        }
		cpt++;
    }

    createBank(cpt);

    createBoard();

    createIcons();
};

void Game::createPlayer(string name, size_t id) {
    players[id] = new Player(name, id, monuments, getPlayerStarterCards());
};

void Game::createBank(size_t nbOfPlayers) {
    bank = new Bank(nbOfPlayers);
};

// need to add all cards
void Game::createEstablishmentCards() {
	cards.push_back(new WheatField());
};

// need to add all monuments
void Game::createMonumentCards() {
    monuments.push_back(new Monument("monumentName", 9, "desc"));
}

void Game::createBoard() {
    board = new Board(cards);
};

// need to add all icons
void Game::createIcons() {
    icons.push_back(new Icon("wheat", "wheat.png", Type::primaryIndustry));
};

// need to add the real cards
vector<EstablishmentCard*> Game::getPlayerStarterCards() {
    vector<EstablishmentCard*> starterCards;
    try {
		starterCards.push_back(getCardByName("WheatField"));
		starterCards.push_back(getCardByName("WheatField"));
		starterCards.push_back(getCardByName("WheatField"));
		starterCards.push_back(getCardByName("WheatField"));
		starterCards.push_back(getCardByName("WheatField"));
    } 
    catch (string error) {
        cout << error;
    }
    return starterCards;
}

EstablishmentCard* Game::getCardByName(string name) const {
    auto it = find_if(cards.begin(), cards.end(), [&name](const EstablishmentCard* obj) {return obj->getName() == name; });
	if (it != cards.end()) {
        //found the name!
        return *it;
    }
    string error = "error getCardByName, didn't find : " + name + "\n";
    throw error;
}
const size_t Game::getNbDiceChosen(Player& p) { // est appelé par le jeu seulement si le joueur posède station
    if (!p.getMonument("Station")) return 1;
    size_t n=0;
    while (n>2 || n<1){
        cout<<"How many dice do you chose to roll ?\n"<<endl;
        cin>>n;
        if (n>2 || n<1) cout<<"Please select a number between 1 and 2\n"<<endl;
    }
    return n;
}

void Game::turn(Player* player) {}

Game::~Game() {};