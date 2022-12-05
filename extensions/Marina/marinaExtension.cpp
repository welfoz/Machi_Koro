#include "marinaExtension.h"

Marina& Marina::getInstance() {
		if (instance == nullptr)
			instance = new Marina;
		return dynamic_cast<Marina&>(*instance);
}

void Marina::createEstablishmentCards(){
    Game::createEstablishmentCards();
    //new marina cards to add here
}

void Marina::createMonumentCards(){
    monuments.push_back(new Monument("City Hall", 16, "Immediatly before buying establishments, if you have 0 coins, get 1 from the bank."));
    Game::createMonumentCards();
}

void Marina::createPlayer(string name, size_t id){
    players[id] = new Player(name, id, monuments, getPlayerStarterCards());
    players[id]->purchaseMonument(getMonumentByName("City Hall"));
}

void Marina::createBoard(){
    //need to change the Board constructor and the createBoard of Game
}

void Marina::createIcons(){
    Game::createIcons();
    //add the new icons here
}

void Marina::turn(Player* player){
    cout << "Marina turn \n\n";
    Game::turn(player);
}