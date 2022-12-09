#pragma once
#include "../game/game.h"
#include "greenValleyExtensionCards.h"
class GreenValley : public Game {
    void createEstablishmentCards() override;
    //monuments remain the same as standard edition
    void createPlayer(string name, size_t id) override;
    //board remain the same as standard edition
    void createIcons() override;
    void turn(Player* player) override;
    map<EstablishmentCard *, bool> createClosed();
    void action(Player* player) override;
public :
    static GreenValley& getInstance();
};
