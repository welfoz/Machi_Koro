#pragma once
#include "bank.h"
#include "player.h"

void Bank::trade(size_t idReceiver, size_t idGiver, int amount){
    accounts[idGiver]-=amount;
    accounts[idReceiver]+=amount;
}

void Bank::credit(size_t idReceiver, int amount){
    accounts[idReceiver]+=amount;
}
void Bank::debit(size_t idGiver, int amount){
    accounts[idGiver]-=amount;
}