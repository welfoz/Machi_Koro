#include <vector>
#include "account.h"
#include "../players/player.h"

class Bank {
private :
    vector<Account*> accounts;
    friend class Game;
    size_t nbPlayers;
    Bank(size_t nb);
    ~Bank(){ for (size_t i=0;i<nbPlayers;i++) delete accounts[i];}
    void trade(size_t idReceiver, size_t idGiver, int amount);
    void credit(size_t idReceiver, int amount);
    void debit(size_t idGiver, int amount);
};
