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

Game::Game(Interface::Option type) : board(nullptr), bank(nullptr), dice(Dice()), winner(nullptr), players(), nbPlayers(0), idCurrentPlayer(0), interface(Interface::createInterfaceFromOption(type)) {
    instance = this;
};

 
void Game::createAll() {
    interface->printWelcomingMessage();

    // create cards before players because players needs them to be created
    createIcons();
    createMonumentCards();
    createEstablishmentCards();

    // create all players
    // ask number of players and their names
    unsigned int cpt = 0;
    bool stop = false;
    vector<string> names;
    while (cpt <= 10 && !stop) {
	    
        interface->printBasicMessage("NEW PLAYER!!\nEnter the name of the player number " + std::to_string(cpt + 1) + " : ");

        string name = interface->getInputText();
        while (find_if(names.begin(),names.end(),[&name](string s){return s==name;})!=names.end()){
            interface->printBasicMessage("Error : name already used\n");
            interface->printBasicMessage("Enter the name of the player number " + std::to_string(cpt + 1) + '\n');
            name = interface->getInputText();
        }
        names.push_back(name);

		createPlayer(name, cpt);

        if (!interface->confirmationDialog("Do you want to add another player", "Yes", "No")) {
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
        interface->printBasicMessage(error);
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
    throw invalid_argument(error);
}

 
const size_t Game::getNbDiceChosen(Player& p) { // est appelé par le jeu seulement si le joueur posède station
    if (!p.getMonument("Train Station")) return 1;
    size_t n=0;
    while (n>2 || n<1){
        interface->printBasicMessage("How many dice do you chose to roll ?\n");
        n = interface->getInputNumber();
        if (n>2 || n<1) interface->printBasicMessage("Please select a number between 1 and 2\n");
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
    interface->printBasicMessage("game deleted :)");
    delete interface;
};

 
void Game::match(){
    createAll();

    size_t turnCounter = 1;
    idCurrentPlayer = 0;
    while (winner==nullptr) {
		interface->printTurnCounter(turnCounter);
        turn(players[idCurrentPlayer]);
        idCurrentPlayer=(idCurrentPlayer+1)%nbPlayers;
        turnCounter++;
        };

	interface->printBasicMessage("\n\n\n\n\n\nIT'S OVER!!!\n\nThe winner is...\n" + winner->getUsername() + " 🎉🎉🎉\n\n\nThank you for playing Machi Koro!\n\n");
};

 
void Game::turn(Player* player){
    if (winner!= nullptr) return;

    interface->printPlayerInformation(player);
    interface->printMonuments(player);
    interface->printCards(player);

    const size_t nb = getNbDiceChosen(*player);

    size_t* throws = this->throwDices(nb);

    throws = this->activateRadioTower(player, nb, throws);

    this->setDiceValue(nb, throws);

    activation(player, this->diceValue);

    interface->printBalances(players);

    action(player);

    this->activateAmusementPark(player, nb, throws);
};

size_t* Game::throwDices(size_t nb) const {
    size_t* throws = new size_t[nb];
    for (size_t i=0;i<nb;i++) {
        throws[i]=dice.throwDice();
        interface->printDice(i + 1, throws[i]);
    }
    return throws;
}

size_t* Game::activateRadioTower(Player* player, size_t nb, size_t* throws) const{
    if (player->getMonument("Radio Tower") && interface->confirmationDialog("Do you want to re-roll the dice(s) ? ", "Yes", "No")) {
		for (size_t i = 0; i < nb; i++) {
			throws[i] = dice.throwDice();
			interface->printDice(i + 1, throws[i]);
		}
    }
    return throws;
}

void Game::activateAmusementPark(Player* player, size_t nb, size_t* throws) {
    if (nb==2 && throws[0]==throws[1] && player->getMonument("Amusement Park") && !player->isPlaying) {
        player->isPlaying=true;
        turn(player);
        player->isPlaying=false;
    }
}

void Game::setDiceValue(size_t nb, size_t* throws) {
    size_t diceValue = 0;
    for (size_t i=0;i<nb;i++) diceValue+=throws[i];
    this->diceValue = diceValue;
}

void Game::action(Player* player){
    
    interface->printBasicMessage( "\nWhat do you want to do? (1 = Buy an establishment, 2 = Build a monument, 3 = Nothing!)\n");
    int choix = interface->getInputNumber();

    switch (choix){
    case 1:
    {
        if (!isPlayerAbleToPayEstablishmentCard(player)) {
            action(player);
            break;
        }

        interface->printBoard();

        // interface
        // click on card
        string choice;
        EstablishmentCard* card = nullptr;
        while (card == nullptr){
            interface->printBasicMessage( "Enter the name of the card you want to buy : ");
            choice = interface->getInputText();
            try
            {
                card = getCardByName(choice);
                if (card->getPrice() > bank->getAccount(player->getId())->getSolde()){
                    throw invalid_argument("You don't have enough money to buy this card.\n");
                }
                if (board->getCard(card) == 0) {
                    throw invalid_argument("There is no available card for this stack.\n");
                }

                player->purchaseEstablishment(card);
                board->removeCard(card);
                bank->debit(player->getId(), card->getPrice());
                interface->printCards(player);
            }
            catch(const std::exception& e)
            {
                interface->printError(e);
                interface->printBasicMessage( "Select an available card.\n");

                card = nullptr;
            }

            if (interface->confirmationDialog("Do you want to change your action ?", "Yes", "No")) {
                if (card != nullptr) {
					player->removeEstablishment(card);
					board->addCard(card);
					bank->credit(player->getId(), card->getPrice());
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
        if (!isPlayerAbleToPayMonument(player)) {
            action(player);
            break;
        }

        interface->printMonuments(player);

        string choice;
        Monument* monument = nullptr;
        while (monument == nullptr) {
            interface->printBasicMessage("Enter the name of the monument you want to buy : ");
            choice = interface->getInputText();
            try {
                monument = getMonumentByName(choice);
                if (monument->getPrice() > bank->getAccount(player->getId())->getSolde()) {
                    throw invalid_argument("You don't have enough money to buy this card.\n");
                }
                if (player->getMonument(choice)) {
                    throw invalid_argument("You already built this monument.\n");
                }

                player->purchaseMonument(monument);
                bank->debit(player->getId(), monument->getPrice());
                interface->printMonuments(player);
            } catch (const std::exception &e) {
                interface->printError(e);
                interface->printBasicMessage("Select an available card.\n");

                monument = nullptr;
            }

            if (interface->confirmationDialog("Do you want to change your action ?",  "Yes", "No")) {
                if (monument != nullptr) {
					player->removeMonument(monument);
					bank->credit(player->getId(), monument->getPrice());
					interface->printPlayerInformation(player);
					interface->printMonuments(player);
					interface->printCards(player);
                }
                action(player);
                break;
            }
        }
        if (isWinner(player)) winner=player;
        break;
    }
    default:
        break;
    } 
};


bool Game::isPlayerAbleToPayEstablishmentCard(Player* player) {
        if (bank->getAccount(player->getId())->getSolde() < board->cheapestAvailableCardPrice()){
            interface->printBasicMessage("\nYou don't have enough money...\n");
            return false;
        }
        else if (board->cheapestAvailableCardPrice()<0){ // important de laisser <0 car il y a une carte dont le prix est 0
            interface->printBasicMessage("\nNo card left on the board\n");
            return false;
        }
        return true;
}

bool Game::isPlayerAbleToPayMonument(Player* player) {
        if (bank->getAccount(player->getId())->getSolde() < player->cheapestMonumentAvailablePrice()){
            interface->printBasicMessage("\nYou don't have enough money...\n");
            return false;
        }
        else if (player->cheapestMonumentAvailablePrice()==0){
            interface->printBasicMessage("\nNo monument left to buy\n");
            return false;
        }
        return true;
}

// blue cards can be activated at everyone turn 
// green cards can only be activated by the player playing
// anti clockwise
void Game::activationGreenAndBlueCards(Player* p,size_t n) {
    for (size_t i = p->getId() + this->nbPlayers; i > p->getId(); i--){
        unsigned int index = i % this->nbPlayers;
        if (players[index] == p) {
			vector<EstablishmentCard*> activatedCards = players[index]->activateGreenCards(n);
            this->activateShoppingMall(p, activatedCards);
        }
        players[index]->activateBlueCards(n);
    }
}

// red cards can only be activated another that the one is playing
void Game::activationRedCards(Player* p, size_t n) {
    for (size_t i = p->getId() + this->nbPlayers; i > p->getId(); i--){
        unsigned int index = i % this->nbPlayers;
        if (players[index] != p) {
			vector<EstablishmentCard*> activatedCards = players[index]->activateRedCards(n);
            this->activateShoppingMall(p, activatedCards);
        }
    }
}

void Game::activateShoppingMall(Player* p, vector<EstablishmentCard*> cards) {
    if (!p->getMonument("Shopping Mall")) {
        return;
    }
    for (auto it : cards) {
        if (it->getIcon()->getName() == "bread" || it->getIcon()->getName() == "cup") {
            // no need to handle the case when Type::majorEstablishment and Type::primaryIndustry
            // because they never have bread or cup icon
            switch (it->getType()) {
			case (Type::restaurants):
				this->getBank()->trade(p->getId(), getIdCurrentPlayer(), 1);
                break;
			case(Type::secondaryIndustry):
			    this->getBank()->credit(p->getId(), 1);
                break;
			default:
				break;
            }
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
    p1->removeEstablishment(cardP1);
    p1->purchaseEstablishment(cardP2);
    p2->removeEstablishment(cardP2);
    interface->printBasicMessage(p1->getUsername() + " has taken " + cardP2->getName() + " from " + p2->getUsername() + " and gave " + cardP1->getName() + " in exchange.\n");
}

Player* Game::getPlayerByName(std::string name) const {
    for (size_t i=0; i<nbPlayers;i++){
        if (players[i]->getUsername()==name) return players[i];
    }
    string error = "error getPlayerByName, didn't find : " + name + "\n";
    throw error;
}

bool Game::isWinner(Player *player) const {
    for (auto it = player->getMonuments().begin(); it != player->getMonuments().end(); it++) {
        if (!it->second) return false;
    }
    return true;
}
