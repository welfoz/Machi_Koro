#pragma once
#include "../../game/game.h"
#include "greenValleyExtensionCards.h"
#include "PlayerGreenValley.h"
class GreenValley : public Game {
    PlayerGreenValley* players[10];
    void createEstablishmentCards() override;
    //monuments remain the same as standard edition
    void createPlayer(string name, size_t id) override;
    //board remain the same as standard edition
    void createIcons() override;
    void turn(Player* player) override;
    void action(Player* player) override;
public :
    static GreenValley& getInstance();
    PlayerGreenValley& getPlayer(size_t id) const override { return *players[id];}
};
