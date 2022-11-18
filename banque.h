#ifndef MACHI_KORO_BANQUE_H
#define MACHI_KORO_BANQUE_H
#include "compte.h"
#include "joueur.h"
class Banque {
private :
    Banque(Joueur** joueur);
    ~Banque();
    Compte* comptes;
    friend class Jeu;
    void echange(class Joueur& j1, class Joueur& j2, int montant);
    void credit (Joueur& j1, Joueur& j2, int montant);
    void prelevement(class Joueur& j, int montant);

};

#endif //MACHI_KORO_BANQUE_H
