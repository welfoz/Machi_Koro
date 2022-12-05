#include "greenValleyExtension.h"


GreenValley& GreenValley::getInstance() {
    if (instance == nullptr)
        instance = new Marina;
    return dynamic_cast<GreenValley&>(*instance);
}

void GreenValley::createEstablishmentCards(){
    Game::createEstablishmentCards();
    //new marina cards to add here
}

void GreenValley::createMonumentCards(){
    monuments.push_back(new Monument("City Hall", 16, "Immediatly before buying establishments, if you have 0 coins, get 1 from the bank."));
    Game::createMonumentCards();
}

void GreenValley::createPlayer(string name, size_t id){
    players[id] = new Player(name, id, monuments, getPlayerStarterCards());
    players[id]->purchaseMonument(getMonumentByName("City Hall"));
}

void GreenValley::createBoard(){
    //need to change the Board constructor and the createBoard of Game
}

void GreenValley::createIcons(){
    Game::createIcons();
    //add the new icons here
}

void GreenValley::turn(Player* player){
    cout << "Marina turn \n\n";
    Game::turn(player);
}
