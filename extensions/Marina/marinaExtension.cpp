#include "marinaExtension.h"
#include "marinaExtensionCards.h"
#include "../../game/controller/control.h"

void Marina::createEstablishmentCards(){
    // base cards with some additional quantities -> pas dans les règles françaises
	// cards.push_back(new WheatField(7));
	// cards.push_back(new Ranch(6));
	// cards.push_back(new Forest(6));
	// cards.push_back(new Mine(6));
	// cards.push_back(new AppleOrchard(6));
	// cards.push_back(new Bakery(7));
	// cards.push_back(new ConvenienceStore(6));
	// cards.push_back(new CheeseFactory(6));
	// cards.push_back(new FurnitureFactory(6));
	// cards.push_back(new FruitVegetableMarket(6));
	// cards.push_back(new Cafe(6));
	// cards.push_back(new FamilyRestaurant(6));
	// cards.push_back(new Stadium(5));
	// cards.push_back(new TVStation(5));
	// cards.push_back(new BusinessCenter(5));
    Game::createEstablishmentCards();

    // new HE cards
    cards.push_back(new FlowerGarden(6));
    cards.push_back(new MackerelBoat(6));
    cards.push_back(new TunaBoat(6));
    cards.push_back(new FlowerShop(6));
    cards.push_back(new FoodWarehouse(6));
    cards.push_back(new SushiBar(6));
    cards.push_back(new PizzaJoint(6));
    cards.push_back(new HamburgerStand(6));
    cards.push_back(new Publisher(4)); //5 dans le wikifan
    cards.push_back(new TaxOffice(4)); //5 dans le wikifan
}

void Marina::createMonumentCards(){
    monuments.push_back(new Monument("City Hall", 0, "Immediatly before buying establishments, if you have 0 coins, get 1 from the bank."));
    monuments.push_back(new Monument("Harbor", 2, "If the dice total is 10 or more, you may add 2 to the total, on your turn only."));
    monuments.push_back(new Monument("Airport", 30, "If you build nothing on your turn, you get 10 coins from the bank."));
    Game::createMonumentCards();
}

void Marina::createPlayer(string name, size_t id){
    if (!canAddNewPlayer()) {
        throw out_of_range("limit_players_reached");
    }

    for (unsigned int i = 0; i < this->nbPlayers; i++) {
        if (players[i]->getUsername() == name) {
			throw invalid_argument("two_players_homonyme");
        }
    }
    players[id] = new Player(name, id, monuments, getPlayerStarterCards());
    players[id]->purchaseMonument(getMonumentByName("City Hall"));

    this->nbPlayers += 1;
}

void Marina::createBoard(){
    board = new MarinaBoard(cards);
}

void Marina::createIcons(){
    Game::createIcons();
    icons.push_back(new Icon("boat", "boat.png", Type::primaryIndustry));
}
