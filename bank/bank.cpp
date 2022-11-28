#include "bank.h"
#include "../players/player.h"

Bank::Bank(size_t nb) : nbPlayers(nb){
    for (size_t i=0; i<nb; i++) accounts.push_back(new Account);
};

void Bank::trade(size_t idReceiver, size_t idGiver, int amount){
    size_t actual_amount;
    if (accounts[idGiver]->getSolde()>=amount) {
        accounts[idGiver]->add(-amount);
        actual_amount=amount;
    }
    else {
        actual_amount=accounts[idGiver]->getSolde();
        accounts[idGiver]->add(-accounts[idGiver]->getSolde());
    }
    accounts[idReceiver]->add(actual_amount);
}

void Bank::credit(size_t idReceiver, int amount){
    accounts[idReceiver]->add(amount);
}
void Bank::debit(size_t idGiver, int amount){
    if (accounts[idGiver]->getSolde()>=amount) {
        accounts[idGiver]->add(-amount);
    }
    else accounts[idGiver]->add(-accounts[idGiver]->getSolde());
}