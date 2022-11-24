#include "bank.h"

Bank::Bank(size_t nbPlayers){};
Bank::~Bank(){};
void Bank::trade(Player& idReceiver, Player& idGiver, int amount){};
void Bank::credit(Player& idReceiver, int amount){};
void Bank::debit(Player& idGiver, int amount){};