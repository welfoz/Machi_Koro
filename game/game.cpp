#include "game.h"

Game& Game::getInstance()
{
    if (instance == nullptr)
        instance = new Game;
    return *instance;
}

void Game::freeInstance()
{
    delete instance;
    instance = nullptr;
}

Game* Game::instance = nullptr;

Game::Game() : board(nullptr), bank(nullptr), dice(Dice()), winner(nullptr), players(), nbPlayers(0){
    instance = this;
};

void Game::createAll() {
    cout << "You're going to start a Machi Koro part\n";
    // create cards before players because players needs them to be created
    createIcons();
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
    this->nbPlayers = cpt;
    createBank(cpt);
    createBoard();

};

void Game::createPlayer(string name, size_t id) {
    players[id] = new Player(name, id, monuments, getPlayerStarterCards());
};

void Game::createBank(size_t nbOfPlayers) {
    bank = new Bank(nbOfPlayers);
};

void Game::createEstablishmentCards() {
	cards.push_back(new WheatField(6));
	cards.push_back(new Ranch(6));
	cards.push_back(new Forest(6));
	cards.push_back(new Mine(6));
	cards.push_back(new AppleOrchard(6));
	cards.push_back(new Bakery(6));
	cards.push_back(new ConvenienceStore(6));
	cards.push_back(new CheeseFactory(6));
	cards.push_back(new FurnitureFactory(6));
	cards.push_back(new FruitVegetableMarket(6));
	cards.push_back(new Cafe(6));
	cards.push_back(new FamilyRestaurant(6));
	cards.push_back(new Stadium(4));
	cards.push_back(new TVStation(4));
	cards.push_back(new BusinessCenter(4));
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
    icons.push_back(new Icon("major", "major.png", Type::landmark));
};

vector<EstablishmentCard*> Game::getPlayerStarterCards() {
    vector<EstablishmentCard*> starterCards;
    try {
		starterCards.push_back(getCardByName("Wheat Field"));
        starterCards.push_back(getCardByName("Bakery"));
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

Monument* Game::getMonumentByName(string name) const {
    auto it = find_if(monuments.begin(), monuments.end(), [&name](const Monument* obj) {return obj->getName() == name;});
	if (it != monuments.end()) {
        //found the name!
        return *it;
    }
    string error = "error getMonumentByName, didn't find : " + name + "\n";
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
    for (size_t i = 0; i<this->nbPlayers; i++) delete players[i];
    for (std::vector<EstablishmentCard*>::iterator it = cards.begin() ; it != cards.end(); ++it) delete *it;
    for (std::vector<Monument*>::iterator it = monuments.begin() ; it != monuments.end(); ++it) delete *it;
    delete board;
    delete bank;
    for (std::vector<const Icon*>::iterator it = icons.begin() ; it != icons.end(); ++it) delete *it;
    std::cout << "game deleted :)";
};

void Game::match(){
    createAll();
    size_t id = 0;
    while (!winner) {
        turn(players[id]);
        if (id == nbPlayers-1) id = 0;
        else id++;
        };
    cout << "The game is over!!\nThe winner is "<< winner->getUsername();
};

void Game::turn(Player* player){
    cout << "\n\n------ Player : " << player->getUsername() << " - Money = " << bank->accounts[player->getId()]->getSolde() << "------\n\n";
    player->printMonuments();
    player->printCards();
    action(player);



};

void Game::action(Player* player){
    cout << "Action? (1=buy an establishment, 2=build a monument, 3=nothing)\n";
    int choix;
    cin >> choix;
    switch (choix){
    case 1:
    {
        //show available and buyable establishments
        //select one
        EstablishmentCard* card = getCardByName("Wheat Field");
        player->purchaseEstablishment(card);
        bank->debit(player->getId(), card->getPrice());
        break;
    }
    case 2:
    {
        //show available and buyable monuments
        //select one
        Monument* monument = getMonumentByName("Radio Tower");
        player->purchaseMonument(monument);
        bank->debit(player->getId(), monument->getPrice());
        break;
    }
    case 99:
        winner = player;
    default:
        break;
    } 
};

// blue cards can be activated at everyone turn 
// green cards can only be activated by the player playing
// sens contraire aiguilles montre ?
// need to change the loop

void Game::activationGreenAndBlueCards(Player* p,size_t n) {
    for (size_t i = 0; i < nbPlayers - 1; i++){
        if (players[i] == p) {
			players[i]->activateGreenCards(n);
        }
        players[i]->activateBlueCards(n);
    }
}

// red cards can only be activated another that the one is playing
void Game::activationRedCards(Player* p, size_t n) {
    for (size_t i = 0; i < nbPlayers - 1; i++) {
        if (players[i] != p) {
			players[i]->activateRedCards(n);
        }
    }
}

// purple cards can only be activated by the player playing
void Game::activationPurpleCards(Player* p, size_t n) {
    p->activatePurpleCards(n);
}

void Game::activation(Player* p, size_t diceNumber) {
    // order of activation:
    // red 
    // green & blue  
    // purple
    activationRedCards(p, diceNumber);
    activationGreenAndBlueCards(p, diceNumber);
    activationPurpleCards(p, diceNumber);
}

