#ifndef MACHI_KORO_PLAYER_H
#define MACHI_KORO_PLAYER_H
class Account;
class Monument;
class EstablishmentCard;
class BaseCard;
#include <string>
#include <map>

using namespace std;

class Player{
    friend class Jeu;
    string username;
    int id;
    map<EstablishmentCard*,size_t> cardsCounter;
    Monument* monuments;
    int nbMonument;
    void acheterCarte(BaseCard& carte);
    void activateRedCards(size_t nombreTire);
    void activateBlueCards(size_t nombreTire);
    void activateGreenCards(size_t nombreTire);
    void activatePurpleCards(size_t nombreTire);
public:
    const int& nbDiceChosen() const;

};



#endif //MACHI_KORO_PLAYER_H
