#pragma once
#include <string>
#include <map>
#include "establishmentCard.h"
#include "monument.h"
#include <iostream>
#include "ostream"
using namespace std;

class Player{
    friend class Jeu;
    string username;
    int id;
    map<EstablishmentCard*,size_t> cardsCounter;
    map<Monument*,bool>monuments;
    int nbMonument;
    Player(int id,string username, int nbmonument);
    void purchaseMonument(Monument& card);
    void purchaseEstablishment(EstablishmentCard& card);
    const size_t nbDiceChosen() const;
    void activateRedCards(size_t diceNumber);
    void activateBlueCards(size_t diceNumber);
    void activateGreenCards(size_t diceNumber);
    void activatePurpleCards(size_t diceNumber);
public:
    bool getMonument(string name) const;
    const string& getUsername() const;
    const size_t& getId() const;
};
