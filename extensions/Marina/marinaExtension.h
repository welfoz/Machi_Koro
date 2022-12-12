#pragma once
#include "../../game/game.h"
#include "marinaBoard.h"

class Marina: public Game {
protected:
    void createEstablishmentCards() override;
    void createMonumentCards() override;
    void createPlayer(string name, size_t id) override;
    void createBoard() override;
    void createIcons() override;
    void turn(Player* player) override;
public:
    static Marina& getInstance();
    Marina() : Game() {};
};