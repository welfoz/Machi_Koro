#pragma once
#include "game.h"

class Marina: public Game {
public:
	Marina() : Game() {};

	void createCards() override;
	void createBoard() override;
	void createIcons() override;
	void turn(Player* player) override;
	virtual void createMonuments() override;
};