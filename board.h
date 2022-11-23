#pragma once
#include <map>
#include "baseCard.h"
using namespace std;


//using std::map;
#include "establishmentCard.h"
class Board
{
private:
    friend class Game;
    map<BaseCard*, size_t> cardsDecks;
public:
    Board();
    ~Board();
    BaseCard& removeCard(BaseCard& card);
    BaseCard& addCard(BaseCard& card);
    void printBoard();
};
