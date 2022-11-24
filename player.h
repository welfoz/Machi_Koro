#pragma once
#include <string>
#include <map>
#include "monument.h"
#include "establishmentCard.h"
#include <iostream>
#include <vector>

// need to comment it if we want to use EstablishmentCard methods
//class EstablishmentCard;

using namespace std;

class Player{
    friend class Game;
    string username;
    size_t id;
    map<EstablishmentCard*, size_t> cardsCounter;
    map<Monument*, bool> monuments;
    void purchaseCard(EstablishmentCard* card);
    const int& nbDiceChosen() const;
    void activateRedCards(size_t diceNumber);
    void activateBlueCards(size_t diceNumber);
    void activateGreenCards(size_t diceNumber);
    void activatePurpleCards(size_t diceNumber);
public:
    Player(string name, size_t id, vector<Monument*> monuments, vector<EstablishmentCard*> cards);

    const Monument& getMonument(string name) const;
    const string& getUsername() const {
        return username;
    };
    const size_t& getId() const;

    void printCards() const;
};
