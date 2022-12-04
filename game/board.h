#pragma once
#include <map>
#include "../cards/baseCard.h"
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;


//using std::map;
#include "../cards/establishmentCard.h"
class Board
{
private:
    friend class Game;
    map<EstablishmentCard*, size_t> cardsDecks;
public:
    Board(vector<EstablishmentCard*> cards);

    ~Board();
    void removeCard(EstablishmentCard* card);
    void addCard(EstablishmentCard* card);
    void printBoard();
};
