#pragma once
#include "account.h"
#include "player.h"

//class Player;
class Bank {
private :
    Account* accounts[];
    friend class Game;
    Bank(size_t nbPlayers);
    ~Bank();
    void trade(Player& idReceiver, Player& idGiver, int amount);
    void credit(Player& idReceiver, int amount);
    void debit(Player& idGiver, int amount);
};
