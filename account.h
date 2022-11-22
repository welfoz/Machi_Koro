#ifndef MACHI_KORO_COMPTE_H
#define MACHI_KORO_COMPTE_H

class Account {
    friend class Bank;
    size_t balance;
    void add(size_t amount);
public:
    const size_t& getSolde() const;
};

#endif //MACHI_KORO_COMPTE_H
