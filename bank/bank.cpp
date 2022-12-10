#include "bank.h"
#include "../players/player.h"

Bank::Bank(size_t nbPlayers) : nbPlayers(nbPlayers){
    for (size_t i=0;i<nbPlayers;i++) accounts.push_back(new Account);
}

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
    string name1 =Game::getInstance().getPlayer(idGiver).getUsername();
    string name2 =Game::getInstance().getPlayer(idReceiver).getUsername();
    cout<<name2<<" received "<<actual_amount<<" coin(s) from"<<name1<<endl;
}

void Bank::credit(size_t idReceiver, int amount){
    accounts[idReceiver]->add(amount);
    cout<<Game::getInstance().getPlayer(idReceiver).getUsername()<<" received "<<amount<<" coin(s) from the bank"<<endl;
}
void Bank::debit(size_t idGiver, int amount){
    if (accounts[idGiver]->getSolde()>=amount) {
        accounts[idGiver]->add(-amount);
    }
    else accounts[idGiver]->add(-accounts[idGiver]->getSolde());
    cout<<Game::getInstance().getPlayer(idGiver).getUsername()<<" gave "<<amount<<" coin(s) to the bank"<<endl;
}