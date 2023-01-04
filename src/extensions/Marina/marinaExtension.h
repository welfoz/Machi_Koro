#pragma once
#include "../../game/game.h"
#include "marinaBoard.h"

class Marina: public virtual Game {
protected:
    void createEstablishmentCards() override;
    void createMonumentCards() override;
    void createPlayer(string name, size_t id, bool isAi) override;
    void createBoard() override;
    void createIcons() override;
public:
    Marina() : Game() {
		this->numberOfPlayersMax = 5;
    };
};