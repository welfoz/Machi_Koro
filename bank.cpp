#pragma once
#include "bank.h"
#include "player.h"

void Bank::trade(size_t idReceiver, size_t idGiver, int amount){
    if (accounts[idGiver]->getSolde()>=amount) accounts[idGiver]->add(-amount);
    else accounts[idGiver]->add(-accounts[idGiver]->getSolde());
    accounts[idReceiver]+=amount;
}

void Bank::credit(size_t idReceiver, int amount){
    accounts[idReceiver]+=amount;
}
void Bank::debit(size_t idGiver, int amount){
    accounts[idGiver]-=amount;
}