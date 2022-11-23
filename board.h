#pragma once

#ifndef MACHI_KORO_PAQUET_H
#define MACHI_KORO_PAQUET_H
#include <map>
class BaseCard;
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

#endif //MACHI_KORO_PAQUET_H
