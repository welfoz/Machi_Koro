#include "../game/game.h"

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
    cout << "[BANK] Traded " << actual_amount << " from " << Game::getInstance().getPlayer(idGiver).getUsername() << " to " << Game::getInstance().getPlayer(idReceiver).getUsername() <<"\n";
}

void Bank::credit(size_t idReceiver, int amount){
    accounts[idReceiver]->add(amount);
    cout << "[BANK] Credited " << amount << " to " << Game::getInstance().getPlayer(idReceiver).getUsername() << "\n";
}
void Bank::debit(size_t idGiver, int amount){
    if (accounts[idGiver]->getSolde()>=amount) {
        accounts[idGiver]->add(-amount);
    }
    else accounts[idGiver]->add(-accounts[idGiver]->getSolde());
    cout << "[BANK] Debited " << amount << " to " << Game::getInstance().getPlayer(idGiver).getUsername() << "\n";
}