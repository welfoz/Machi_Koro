//
// Created by jules on 29/12/2022.
//

#include "Proxy.h"

Interface *Proxy::getInterface(bool gameCreation) const {
    Game* game = Controller::getInstance().getGame();
    if (!gameCreation) if (game->getPlayer(game->getIdCurrentPlayer()).isAi()){
        return aiInterface;
    }
    return interface;
}

Proxy::Proxy(Interface *interface) : interface(interface), aiInterface(new Ai(interface)){
    if (interface == nullptr) {
        throw "ERROR: interface need to be defined to create a Controller";
    }
}

Proxy::~Proxy() {
    delete aiInterface;
    delete interface;
};
