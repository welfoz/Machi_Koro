#pragma once
#include "../game/game.h"
#include <list>

class Deluxe : public Game {
	// exemple: {card address, [1 if closed else 0, number of remaining turn closed]}
	map<EstablishmentCard*, list<size_t>> closures;
public:
	Deluxe();

	bool isClosed(EstablishmentCard&);
	void closeCard(EstablishmentCard& c, size_t nbTurns);

	void createEstablishmentCards() override;
    void createMonumentCards() override;
	void createBoard() override;
	void createIcons() override;
	void turn(Player* player) override;
};