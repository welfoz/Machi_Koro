#pragma once
#include "../game.h"
#include <list>

class GreenValley : public Game {
	map<EstablishmentCard*, list<size_t>> closures;
public:
	GreenValley();

	bool isClosed(EstablishmentCard&);
	void closeCard(EstablishmentCard& c, size_t nbTurns);

	void createCards() override;
	void createBoard() override;
	void turn(Player* player) override;
};