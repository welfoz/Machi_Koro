#pragma once
#include <string>
#include <map>
#include "../cards/establishmentCard.h"
#include "../cards/monument.h"
#include <iostream>
#include "ostream"
#include <vector>
#include <algorithm>
// need to comment it if we want to use EstablishmentCard methods
using namespace std;

class Player{
private:
    string username;
    size_t id;
    map<EstablishmentCard*,size_t> cardsCounter;
    map<Monument*,bool>monuments;
public:
    bool isPlaying;
    void purchaseMonument(Monument* card);
    void removeMonument(Monument* card);
    void purchaseEstablishment(EstablishmentCard* card);
    void removeEstablishment(EstablishmentCard* card);
    void activateRedCards(size_t diceNumber);
    void activateBlueCards(size_t diceNumber);
    void activateGreenCards(size_t diceNumber);
    void activatePurpleCards(size_t diceNumber);
    bool getMonument(string name) const;
    const map<Monument*, bool> getMonuments() const {
        return monuments;
    };
    const map<EstablishmentCard*,size_t>& getCards() {return cardsCounter;}
    Player(string name, size_t id, vector<Monument*> monuments, vector<EstablishmentCard*> cards, bool iP=false);
    const string& getUsername() const {return username;};
    const size_t& getId() const;
    void printCards() const;
    void printMonuments() const;
    size_t cheapestMonumentAvailablePrice() const;
};
