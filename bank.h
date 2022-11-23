#pragma once
//#ifndef MACHI_KORO_BANQUE_H
//#define MACHI_KORO_BANQUE_H
#include "account.h"
class Player;
class Bank {
private :
    Account** accounts;
    friend class Game;
    Bank(Player** player);
    ~Bank();
    void trade(Player& idReceiver, Player& idGiver, int amount);
    void credit(Player& idReceiver, int amount);
    void debit(Player& idGiver, int amount);

};

//#endif //MACHI_KORO_BANQUE_H
