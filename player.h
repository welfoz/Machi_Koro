#pragma once
#include <string>
#include <map>
#include "establishmentCard.h"
#include "monument.h"
#include <iostream>

using namespace std;

class Player{
    friend class Jeu;
    string username;
    int id;
    map<EstablishmentCard*,size_t> cardsCounter;
    int nbMonument;
    Monument* monuments[];
    void purchaseCard(BaseCard& carte);
    const int& nbDiceChosen() const;
    void activateRedCards(size_t diceNumber);
    void activateBlueCards(size_t diceNumber);
    void activateGreenCards(size_t diceNumber);
    void activatePurpleCards(size_t diceNumber);
public:
    const Monument& getMonument(string name) const;
    const string& getUsername() const;
    const size_t& getId() const;
;
    Player(): username("a"), id(0), monuments(), nbMonument(0) {};
};
