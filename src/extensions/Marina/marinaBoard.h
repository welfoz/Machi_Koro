#pragma once
#include "../../game/board.h"
#include <random>
#include <algorithm>

class MarinaBoard : public Board {
private:
    vector<EstablishmentCard*> pile;
public:
    MarinaBoard(vector<EstablishmentCard*> cards);
    void checkNumberOfDecks();
    void removeCard(EstablishmentCard* card);
};