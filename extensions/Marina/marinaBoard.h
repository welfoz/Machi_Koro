#pragma once
#include "../../game/board.h"
#include <random>
#include <algorithm>

class MarinaBoard : public Board {
private:
    vector<EstablishmentCard*> pile;
public:
    MarinaBoard(vector<EstablishmentCard*> cards) : pile(cards){
        auto rd = std::random_device {}; 
        auto rng = std::default_random_engine { rd() };
        std::shuffle(std::begin(pile), std::end(pile), rng);
        checkNumberOfDecks();
    };
    void printBoard();
    void checkNumberOfDecks();
};