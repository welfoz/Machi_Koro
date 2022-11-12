#ifndef MACHI_KORO_COMPTE_H
#define MACHI_KORO_COMPTE_H

class Compte {
    friend class Banque;
    int argent;
    void ajoutArgent(int montant);
    void retirerArgent(int montant);
public:
    const int& getArgent() const;
};

#endif //MACHI_KORO_COMPTE_H
