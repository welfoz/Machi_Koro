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
    size_t id;
    map<Monument*,bool>monuments;
protected:
    map<EstablishmentCard*,size_t> cardsCounter;
    string username;
public:
    bool isPlaying;
    void purchaseMonument(Monument* card);
    void removeMonument(Monument* card);
    void purchaseEstablishment(EstablishmentCard* card);
    void removeEstablishment(EstablishmentCard* card);
    virtual vector<EstablishmentCard*> activateRedCards(size_t diceNumber);
    virtual void activateBlueCards(size_t diceNumber);
    virtual vector<EstablishmentCard*> activateGreenCards(size_t diceNumber);
    virtual void activatePurpleCards(size_t diceNumber);
    // getters
    bool getMonument(string name) const;
    const map<Monument*, bool>& getMonuments() const {return monuments;};
    const map<EstablishmentCard*,size_t>& getCards() {return cardsCounter;}
    const size_t getNbMonumentsActivated() const;
    Player(string name, size_t id, vector<Monument*> monuments, vector<EstablishmentCard*> cards, bool iP=false);
    const string& getUsername() const {return username;};
    const size_t& getId() const;
    virtual void printCards() const;
    void printMonuments() const;
    size_t cheapestMonumentAvailablePrice() const;
};
