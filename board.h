#pragma once
#include <map>
#include "baseCard.h"
using namespace std;

class Board
{
private:
    friend class Game;
    map<BaseCard&, size_t> cardsCounter;
public:
    Board();
    ~Board();
    BaseCard& removeCard(BaseCard& card);
    BaseCard& addCard(BaseCard& card);
    void printBoard();
};
