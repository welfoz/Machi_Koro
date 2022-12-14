#include "game.h"

Game::Game() : board(nullptr), bank(nullptr), dice(Dice()), winner(nullptr), players(), nbPlayers(0), idCurrentPlayer(0) {
    //instance = game;
};

bool Game::canAddNewPlayer() const {
    if (this->nbPlayers >= 10) {
        return false;
    }
    return true;
}

void Game::createPlayer(string name, size_t id) {
    // toute la partie logique de createPlayer se trouve ici
    // avant de créer un nouveau player
    // verifier limite 10
    // verifier homonymes

    if (!canAddNewPlayer()) {
        throw out_of_range("limit_players_reached");
    }

    for (unsigned int i = 0; i < this->nbPlayers; i++) {
        if (players[i]->getUsername() == name) {
			throw invalid_argument("two_players_homonyme");
        }
    }
    players[id] = new Player(name, id, monuments, getPlayerStarterCards());

    this->nbPlayers += 1;
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
    monuments.push_back(new Monument("Amusement Park", 16, "If you roll doubles, take another turn after game one."));
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
	starterCards.push_back(getCardByName("Wheat Field"));
	starterCards.push_back(getCardByName("Bakery"));
	return starterCards;
}

EstablishmentCard* Game::getCardByName(string name) const {
    auto it = find_if(cards.begin(), cards.end(), [&name](const EstablishmentCard* obj) {return obj->getName() == name;});
	if (it != cards.end()) {
        //found the name!
        return *it;
    }
    throw invalid_argument("error getCardByName, didn't find : " + name + "\n");
}

Monument* Game::getMonumentByName(string name) const {
    auto it = find_if(monuments.begin(), monuments.end(), [&name](const Monument* obj) {return obj->getName() == name;});
	if (it != monuments.end()) {
        //found the name!
        return *it;
    }
    throw invalid_argument("error getMonumentByName, didn't find : " + name + "\n");
}

Game::~Game() {
    for (size_t i = 0; i<this->nbPlayers; i++) delete players[i];
    for (std::vector<EstablishmentCard*>::iterator it = cards.begin() ; it != cards.end(); ++it) delete *it;
    for (std::vector<Monument*>::iterator it = monuments.begin() ; it != monuments.end(); ++it) delete *it;
    delete board;
    delete bank;
    for (std::vector<const Icon*>::iterator it = icons.begin() ; it != icons.end(); ++it) delete *it;
    //interface->printBasicMessage("game deleted :)");
    //delete interface;
};

size_t* Game::throwDices(size_t nb) const {
    size_t* throws = new size_t[nb];
    for (size_t i=0;i<nb;i++) {
        throws[i]=dice.throwDice();
    }
    return throws;
}

size_t Game::setDiceValue(size_t nb, size_t* throws) {
    size_t diceValue = 0;
    for (size_t i=0;i<nb;i++) diceValue+=throws[i];
    this->diceValue = diceValue;
}

bool Game::isPlayerAbleToPayEstablishmentCard(Player* player) {
        if (bank->getAccount(player->getId())->getSolde() < board->cheapestAvailableCardPrice()){
            return false;
        }
        return true;
}

bool Game::isPlayerAbleToPayMonument(Player* player) {
	if (bank->getAccount(player->getId())->getSolde() < player->cheapestMonumentAvailablePrice()) {
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
            activateShoppingMall(p, activatedCards);
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
    //interface->printBasicMessage(p1->getUsername() + " has taken " + cardP2->getName() + " from " + p2->getUsername() + " and gave " + cardP1->getName() + " in exchange.\n");
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

