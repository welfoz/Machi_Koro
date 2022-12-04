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
    cout << "\n\n";
    cout << "███    ███  █████   ██████ ██   ██ ██     ██   ██  ██████  ██████   ██████  \n";
    cout << "████  ████ ██   ██ ██      ██   ██ ██     ██  ██  ██    ██ ██   ██ ██    ██ \n";
    cout << "██ ████ ██ ███████ ██      ███████ ██     █████   ██    ██ ██████  ██    ██ \n";
    cout << "██  ██  ██ ██   ██ ██      ██   ██ ██     ██  ██  ██    ██ ██   ██ ██    ██ \n";
    cout << "██      ██ ██   ██  ██████ ██   ██ ██     ██   ██  ██████  ██   ██  ██████  \n";
                                                                                   
    cout << ".   .__. _,  ,           .__. _,  _, \n";
    cout << "|   |  |'_) /|     ___   [__]'_) '_) \n";
    cout << "|___|__|/_. .|.          |  |/_. /_. \n\n";
                                                                                                                                                                                                                                                         
    cout << "Made with ❤️  by MICHEL Fabien - BROSSARD Felix - TAVERNE Jules - CORTY Pol - LEMERLE Xavier\n\n";

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
    vector<string> names;
    while (cpt <= 10 && !stop) {
		cout << "NEW PLAYER!!\nEnter the name of the player number " << cpt + 1 << " : ";
        cin >> name;
        while (find_if(names.begin(),names.end(),[&name](string s){return s==name;})!=names.end()){
            cout<<"Error : name already used"<<endl;
            cout << "Enter the name of the player number " << cpt + 1 << '\n';
            cin >> name;
        }
        names.push_back(name);
		createPlayer(name, cpt);
        while ((stopAnswer != "Y") and (stopAnswer != "y") and (stopAnswer != "N") and (stopAnswer != "n")){
            cout << "Do you want to add another player? (Y/N)";
            cin >> stopAnswer;
        }
        if (stopAnswer == "n" || stopAnswer == "N") {
            stop = true;
        }
        stopAnswer = "";
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
    throw invalid_argument(error);
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
        cout<<"How many dice do you chose to roll ?"<<endl;
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
    idCurrentPlayer = 0;
    while (!winner) {
        cout << "\n\n-------------------------------------------------------------------------------";
        cout << "\n------------------------------- Turn number : " << idCurrentPlayer/nbPlayers + 1 << " -------------------------------\n";
        turn(players[idCurrentPlayer % this->nbPlayers]);
        idCurrentPlayer++;
        };
    cout << "\n\n\n\n\n\nIT'S OVER!!!\n\nThe winner is...\n"<< winner->getUsername() << " 🎉🎉🎉\n";
    cout << "\n\nThank you for playing Machi Koro!\n\n";
};

void Game::turn(Player* player){
    cout << "\n\n-------------------------- Player : " << player->getUsername() << " - Money = " << bank->accounts[player->getId()]->getSolde() << " --------------------------\n\n";
    player->printMonuments();
    player->printCards();
    size_t nb=getNbDiceChosen(*player);
    size_t throws[nb];
    for (size_t i=0;i<nb;i++) {
        throws[i]=dice.throwDice();
        cout<<"\nDice n°"<<i+1<<": "<<throws[i]<<endl;
    }
    if (player->getMonument("Radio Tower")){
        string choice;
        cout<<"Do you want to re-roll the dice(s) ? (Y/N)"<<endl;
        cin>>choice;
        if (choice=="Y" || choice=="y"){
            for (size_t i=0;i<nb;i++) throws[i]=dice.throwDice();
            for (size_t i=0;i<nb;i++) {
                throws[i]=dice.throwDice();
                cout<<"\nValue of dice number "<<i+1<<" : "<<throws[i]<<endl;
            }
        }
    }
    size_t diceValue=0;
    for (size_t i=0;i<nb;i++) diceValue+=throws[i];

    activationRedCards(player,diceValue);
    activationGreenAndBlueCards(player,diceValue);
    activationPurpleCards(player,diceValue);

    cout<<"\nPlayer's balance after activation: " << bank->accounts[player->getId()]->getSolde() << "\n\n";
    action(player);
    if (nb==2 && throws[0]==throws[1] && player->getMonument("Amusement Park") && !player->isPlaying) {
        player->isPlaying=true;
        turn(player);
        player->isPlaying=false;
    }
};

void Game::action(Player* player){
    cout << "What do you want to do? (1 = Buy an establishment, 2 = Build a monument, 3 = Nothing!)\n";
    int choix;
    cin >> choix;
    switch (choix){
    case 1:
    {
        board->printBoard();
        string choice;
        EstablishmentCard* card = nullptr;
        while (card == nullptr){
            cout << "Enter the name of the card you want to buy : ";
            cin.ignore();
            getline(cin, choice);
            try
            {
                card = getCardByName(choice);
                if (card->getPrice() > bank->accounts[player->getId()]->getSolde()){
                    throw invalid_argument("You don't have enough money to buy this card.\n");
                }
                if (board->cardsDecks.at(card) == 0){
                    throw invalid_argument("There is no avaible card for this stack.\n");
                }
                player->purchaseEstablishment(card);
                board->removeCard(card);
                bank->debit(player->getId(), card->getPrice());
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                cout << "Select an available card.\n";
                card = nullptr;
            }
        }
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
// anti clockwise
void Game::activationGreenAndBlueCards(Player* p,size_t n) {
    for (size_t i = p->getId() + this->nbPlayers; i > p->getId(); i--){
        unsigned int index = i % this->nbPlayers;
        if (players[index] == p) {
			players[index]->activateGreenCards(n);
        }
        players[index]->activateBlueCards(n);
    }
}

// red cards can only be activated another that the one is playing
void Game::activationRedCards(Player* p, size_t n) {
    for (size_t i = p->getId() + this->nbPlayers; i > p->getId(); i--){
        unsigned int index = i % this->nbPlayers;
        if (players[index] != p) {
			players[index]->activateRedCards(n);
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
void Game::tradeCards(Player* p1, Player* p2, EstablishmentCard *cardP1, EstablishmentCard *cardP2) {
    p2->purchaseEstablishment(cardP1);
    p1->cardsCounter[cardP1]--;
    p1->purchaseEstablishment(cardP2);
    p2->cardsCounter[cardP2]--;
    cout<<p1->getUsername()<<" has taken "<<cardP2->getName()<<" from "<<p2->getUsername()<<" and gave "<<cardP1->getName()<<" in exchange."<<endl;
}
Player* Game::getPlayerByName(std::string name) const {
    for (size_t i=0; i<nbPlayers;i++){
        if (players[i]->getUsername()==name) return players[i];
    }
    string error = "error getPlayerByName, didn't find : " + name + "\n";
    throw error;
}

