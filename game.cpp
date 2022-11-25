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

void Game::createEstablishmentCards() {
	cards.push_back(new WheatField());
    
    for (size_t i; i<6; i++) cards.push_back(new WheatField());
    // for (size_t i; i<6; i++) cards.push_back(new Ranch());
    // for (size_t i; i<6; i++) cards.push_back(new Forest());
    // for (size_t i; i<6; i++) cards.push_back(new Mine());
    // for (size_t i; i<6; i++) cards.push_back(new AppleOrchard());
    // for (size_t i; i<6; i++) cards.push_back(new Bakery());
    // for (size_t i; i<6; i++) cards.push_back(new ConvenienceStore());
    // for (size_t i; i<6; i++) cards.push_back(new CheeseFactory());
    // for (size_t i; i<6; i++) cards.push_back(new FurnitureFactory());
    // for (size_t i; i<6; i++) cards.push_back(new Fruit&VegetableMarket());
    // for (size_t i; i<6; i++) cards.push_back(new Café());
    // for (size_t i; i<6; i++) cards.push_back(new FamilyRestaurant());
    // for (size_t i; i<6; i++) cards.push_back(new Stadium());
    // for (size_t i; i<6; i++) cards.push_back(new TVStation());
    // for (size_t i; i<6; i++) cards.push_back(new BusinessCenter());
};

void Game::createMonumentCards() {
    monuments.push_back(new Monument("Train Station", 4, "You may roll 1 or 2 dice."));
    monuments.push_back(new Monument("Shopping Mall", 10, "Each of your ☕ and 🍞 establishments earns +1 coin."));
    monuments.push_back(new Monument("Amusement Park", 16, "If you roll doubles, take another turn after this one."));
    monuments.push_back(new Monument("Radio Tower", 22, "Once every turn, you can choose to re-roll your dice."));
}

void Game::createBoard() {
    board = new Board(cards);
};

void Game::createIcons() {
    icons.push_back(new Icon("wheat", "wheat.png", Type::primaryIndustry));
    icons.push_back(new Icon("cow", "cow.png", Type::primaryIndustry));
    icons.push_back(new Icon("gear", "gear.png", Type::primaryIndustry));
    icons.push_back(new Icon("bread", "bread.png", Type::secondaryIndustry));
    icons.push_back(new Icon("factory", "factory.png", Type::secondaryIndustry));
    icons.push_back(new Icon("fruit", "fruit.png", Type::secondaryIndustry));
    icons.push_back(new Icon("cup", "cup.png", Type::restaurants));
    icons.push_back(new Icon("major", "major.png", Type::majorEstablishment));
};

vector<EstablishmentCard*> Game::getPlayerStarterCards() {
    vector<EstablishmentCard*> starterCards;
    try {
		starterCards.push_back(getCardByName("Wheat Field"));
        // starterCards.push_back(getCardByName("Bakery"));
    } 
    catch (string error) {
        cout << error;
    }
    return starterCards;
}

EstablishmentCard* Game::getCardByName(string name) const {
    auto it = find_if(cards.begin(), cards.end(), [&name](const EstablishmentCard* obj) {return obj->getName() == name;});
	if (it != cards.end()) {
        //found the name!
        return *it;
    }
    string error = "error getCardByName, didn't find : " + name + "\n";
    throw error;
}
const size_t Game::getNbDiceChosen(Player& p) { // est appelé par le jeu seulement si le joueur posède station
    if (!p.getMonument("Train Station")) return 1;
    size_t n=0;
    while (n>2 || n<1){
        cout<<"How many dice do you chose to roll ?\n"<<endl;
        cin>>n;
        if (n>2 || n<1) cout<<"Please select a number between 1 and 2\n"<<endl;
    }
    return n;
}

Game::~Game() {
    for (std::vector<EstablishmentCard*>::iterator it = cards.begin() ; it != cards.end(); ++it) delete *it;
    for (std::vector<Monument*>::iterator it = monuments.begin() ; it != monuments.end(); ++it) delete *it;
    delete board;
    for (size_t i = 0; i<10; i++) delete players[i];
    delete bank;
    for (std::vector<const Icon*>::iterator it = icons.begin() ; it != icons.end(); ++it) delete *it;
    Game::getInstance()->freeInstance();
};

void Game::match(){
    size_t id = 0;
    while (!winner) turn(players[id]);
    cout << "The game is over!!\nThe winner is "<< winner->getUsername();
};

void Game::turn(Player* player){
    cout << "\n\n------ Player : " << player->getUsername() << " - Money = " << bank->accounts[player->getId()]->getSolde() << "------\n\n";
    cout << "Monuments:\n";
    player->printMonuments();
    cout << "Establishments:\n";
    player->printCards();
};