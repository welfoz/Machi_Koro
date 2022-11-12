#ifndef MACHI_KORO_JOUEUR_H
#define MACHI_KORO_JOUEUR_H
#include "compte.h";
#include <string>
using namespace std;

class Joueur{
    friend class Jeu;
    string username;
    int numero;
    class Compte* compte;
    class Carte** cartes;
    class Carte* monuments;
    int nbDes;
    int nbMonument;
    void acheterCarte(Carte& carte);
public:
    const int& getNbDes() const;
    const int& getChoixNbDes() const;
};

#endif //MACHI_KORO_JOUEUR_H
