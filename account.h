#pragma once
//#ifndef MACHI_KORO_COMPTE_H
//#define MACHI_KORO_COMPTE_H
#include "iostream"

class Account {
    friend class Bank;
    size_t balance;
    void add(size_t amount);
public:
    Account();
    const size_t& getSolde() const;
};

//#endif //MACHI_KORO_COMPTE_H
