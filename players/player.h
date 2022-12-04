#pragma once
#include <string>
#include <map>
#include "../cards/establishmentCard.h"
#include "../cards/monument.h"
#include <iostream>
#include "ostream"
#include <vector>
// need to comment it if we want to use EstablishmentCard methods
class FurnitureFactory;
class FruitVegetableMarket;
class CheeseFactory;
using namespace std;

class Player{
    friend class FurnitureFactory;
    friend class FruitVegetableMarket;
    friend class CheeseFactory;
    friend class Game;
    string username;
    size_t id;
    map<EstablishmentCard*,size_t> cardsCounter;
    map<Monument*,bool>monuments;
    bool isPlaying;
    void purchaseMonument(Monument* card);
    void purchaseEstablishment(EstablishmentCard* card);
    void activateRedCards(size_t diceNumber);
    void activateBlueCards(size_t diceNumber);
    void activateGreenCards(size_t diceNumber);
    void activatePurpleCards(size_t diceNumber);
public:
    bool getMonument(string name) const;
    Player(string name, size_t id, vector<Monument*> monuments, vector<EstablishmentCard*> cards, bool iP=false);
    const string& getUsername() const {return username;};
    const size_t& getId() const;
    void printCards() const;
    void printMonuments() const;
};
