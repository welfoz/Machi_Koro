#pragma once
#include <string>
#include <map>
#include "establishmentCard.h"
#include "monument.h"
#include <iostream>
#include "ostream"
#include <vector>

// need to comment it if we want to use EstablishmentCard methods
//class EstablishmentCard;

using namespace std;

class Player{
    friend class Game;
    string username;
    size_t id;
    map<EstablishmentCard*,size_t> cardsCounter;
    map<Monument*,bool>monuments;
    void purchaseMonument(Monument* card);
    void purchaseEstablishment(EstablishmentCard* card);
    void activateRedCards(size_t diceNumber);
    void activateBlueCards(size_t diceNumber);
    void activateGreenCards(size_t diceNumber);
    void activatePurpleCards(size_t diceNumber);
public:
    bool getMonument(string name) const;
    Player(string name, size_t id, vector<Monument*> monuments, vector<EstablishmentCard*> cards);
    const string& getUsername() const { return username;};
    const size_t& getId() const;
    void printCards() const;
};
