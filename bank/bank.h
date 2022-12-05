
#include "account.h"
#include "../players/player.h"
#include <vector>

class Bank {
private :
    vector<Account*> accounts;
    size_t nbPlayers;
public :
    Bank(size_t nbPlayers);
    ~Bank(){ for (auto it=accounts.begin();it!=accounts.end();it++) delete *it;}
    void trade(size_t idReceiver, size_t idGiver, int amount);
    void credit(size_t idReceiver, int amount);
    void debit(size_t idGiver, int amount);
    const Account* getAccount(size_t id) const {return accounts[id];}
};
