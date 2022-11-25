#pragma once
#include <map>
#include "baseCard.h"
#include <vector>
using namespace std;


//using std::map;
#include "establishmentCard.h"
class Board
{
private:
    friend class Game;
    map<EstablishmentCard*, const size_t> cardsDecks;
public:
    Board(vector<EstablishmentCard*> cards);

    ~Board();
    void removeCard(EstablishmentCard& card);
    void addCard(EstablishmentCard& card);
    void printBoard();
};
