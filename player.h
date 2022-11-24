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
    Monument* monuments;
    int nbMonument;
    void acheterCarte(BaseCard& carte);
    void activateRedCards(size_t diceNumber);
    void activateBlueCards(size_t diceNumber);
    void activateGreenCards(size_t diceNumber);
    void activatePurpleCards(size_t diceNumber);
public:
    Player(): username("a"), id(0), monuments(nullptr), nbMonument(0) {}
    
    ;
    const int& nbDiceChosen() const;

};
