#pragma once
#include "iostream"

class Account {
    friend class Bank;
    size_t balance;
    void add(size_t amount);
public:
    Account() : balance(3){};
    const size_t& getSolde() const {return balance;}
};
