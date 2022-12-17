#pragma once
#ifndef MACHI_KORO_DELUXEEXTENSION_H
#define MACHI_KORO_DELUXEEXTENSION_H
#include "../Marina/marinaExtension.h"
#include "greenValleyExtension.h"
#include <list>

class Deluxe : public Marina, public GreenValley {
	void createEstablishmentCards() override;
    void createMonumentCards() override;
	void createBoard() override;
	void createIcons() override;
    void createPlayer(string name, size_t id) override;
    template<typename t> void remove_duplicates(std::vector<t> vector);
    PlayerGreenValley& getPlayer(size_t id) const override;
public:
    Deluxe(){};
};
#endif