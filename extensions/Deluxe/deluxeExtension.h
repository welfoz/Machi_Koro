#pragma once
#include "../Marina/marinaExtension.h"
#include "../Marina/marinaExtensionCards.h"
#include "greenValleyExtensionCards.h"
#include <list>

class Deluxe : public Marina {
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
};