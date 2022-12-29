#pragma once
#include "../Marina/marinaExtension.h"
#include "greenValleyExtension.h"
#include <list>

class Deluxe : public Marina, public GreenValley {
	void createEstablishmentCards() override;
    void createMonumentCards() override;
	void createBoard() override;
	void createIcons() override;
    void createPlayer(string name, size_t id, bool isAi) override;
    template<typename t> void removeDuplicates(std::vector<t>& vtr);
    PlayerGreenValley& getPlayer(size_t id) const override;
public:
    Deluxe(){};
};