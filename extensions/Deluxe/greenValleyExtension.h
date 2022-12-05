#pragma once
#include "../marina/marinaExtension.h"
#include "../marina/marinaExtensionCards.h"

class GreenValley : public Game {
    void createEstablishmentCards() override;
    void createMonumentCards() override;
    void createPlayer(string name, size_t id) override;
    void createBoard() override;
    void createIcons() override;
    void turn(Player* player) override;
public :
    static GreenValley& getInstance();
    GreenValley() : Game() {};
};
