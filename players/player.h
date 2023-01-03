#pragma once
#include <string>
#include <map>
#include "../cards/establishmentCard.h"
#include "../cards/monument.h"
#include <iostream>
#include <vector>
#include <algorithm>
// need to comment it if we want to use EstablishmentCard methods
using namespace std;

class Player{
private:
    size_t id;
    map<Monument*,bool>monuments;
    bool aI;
protected:
    map<EstablishmentCard*,size_t> cardsCounter;
    string username;
public:
    bool isPlaying;
    void purchaseMonument(Monument* card);
    void removeMonument(Monument* card);
    virtual void purchaseEstablishment(EstablishmentCard* card);
    void removeEstablishment(EstablishmentCard* card);
    virtual void activateRedCards(size_t diceNumber);
    virtual vector<EstablishmentCard*> activatedRedCards(size_t diceNumber);
    virtual void activateBlueCards(size_t diceNumber);
    virtual vector<EstablishmentCard*> activatedBlueCards(size_t diceNumber);
    virtual void activateGreenCards(size_t diceNumber);
    virtual vector<EstablishmentCard*> activatedGreenCards(size_t diceNumber);
    virtual void activatePurpleCards(size_t diceNumber);
    virtual vector<EstablishmentCard*> activatedPurpleCards(size_t diceNumber);
    // getters
    bool getMonument(string name) const;
    const map<Monument*, bool>& getMonuments() const {return monuments;};
    const map<EstablishmentCard*,size_t>& getCards() {return cardsCounter;}
    const size_t getNbMonumentsActivated() const;
    Player(string name, size_t id, vector<Monument*> monuments, vector<EstablishmentCard*> cards,bool isAi, bool iP=false);
    const string& getUsername() const {return username;};
    const size_t& getId() const;
    size_t cheapestMonumentAvailablePrice() const;
    EstablishmentCard* getCardByName(string name) const;
    bool isAnyMonumentLeftToBuy() const;
    const bool& isAi() const {return aI;}
};
