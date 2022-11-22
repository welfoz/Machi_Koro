#ifndef MACHI_KORO_JOUEUR_H
#define MACHI_KORO_JOUEUR_H
#include "carte.h"
#include "compte.h"
#include <string>
#include <vector>
using namespace std;

class Joueur{
    friend class Jeu;
    string username;
    int numero;
    vector<Carte*> cartes;
    Carte* monuments;
    int nbDes;
    int nbMonument;
    void acheterCarte(Carte& carte);
    void activateRedCards(size_t nombreTire);
    void activateBlueCards(size_t nombreTire);
    void activateGreenCards(size_t nombreTire);
    void activatePurpleCards(size_t nombreTire);
public:
    const int& getNbDes() const;
    const int& getChoixNbDes() const;


};

#endif //MACHI_KORO_JOUEUR_H
