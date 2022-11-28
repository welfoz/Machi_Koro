#pragma once
#include "cardColor.h"

class WheatField : public Blue {
public:
    WheatField() : Blue(nullptr, 1, "Wheat Field", 1, "You get 1 coin from the bank, on anyone's turn.",10) {
        BaseCard::setIcon(getIconByName("wheat"));
        size_t* actNumber = new size_t[1];
        actNumber[0] = 1;

        EstablishmentCard::setActivationNumbers(actNumber);
    };
    void activation(Player& p) override {};
};

class Ranch : public Blue {
public:
    Ranch() : Blue(nullptr, 1, "Ranch", 1, "Get one coin from the bank on anyone's turn.", 6) {
        BaseCard::setIcon(getIconByName("cow"));
        size_t* actNumber = new size_t[1];
        actNumber[0] = 2;

        EstablishmentCard::setActivationNumbers(actNumber);
    };
    void activation(Player& p) override {};
};


class Forest : public Blue {
public:
    Forest() : Blue(nullptr, 1, "Forest", 3, "Get 1 coin from the bank, on anyone's turn.", 6) {
        BaseCard::setIcon(getIconByName("gear"));
        size_t* actNumber = new size_t[1];
        actNumber[0] = 5;

        EstablishmentCard::setActivationNumbers(actNumber);
    };
    void activation(Player& p) override {};
};


class Mine : public Blue {
public:
    Mine() : Blue(nullptr, 1, "Mine", 6, "Get 5 coins from the bank, on anyone's turn.", 6) {
        BaseCard::setIcon(getIconByName("gear"));
        size_t* actNumber = new size_t[1];
        actNumber[0] = 9;

        EstablishmentCard::setActivationNumbers(actNumber);
    };
    void activation(Player& p) override {};
};


class AppleOrchard : public Blue {
public:
    AppleOrchard() : Blue(nullptr, 1, "wheat", 3, "Get 3 coins from the bank on anyone's turn.", 6) {
        BaseCard::setIcon(getIconByName("appleOrchard"));
        size_t* actNumber = new size_t[1];
        actNumber[0] = 10;

        EstablishmentCard::setActivationNumbers(actNumber);
    };
    void activation(Player& p) override {};
};




class Bakery : public Green {
public:
    Bakery() : Green(nullptr, 2, "Bakery", 1, "The player with the card gets one coin from the bank.", 10) {
        BaseCard::setIcon(getIconByName("bread"));
        size_t* actNumber = new size_t[2];
        actNumber[0] = 2;
        actNumber[1] = 3;


        EstablishmentCard::setActivationNumbers(actNumber);
    };
    void activation(Player& p) override {};
};


class ConvenienceStore : public Green {
public:
    ConvenienceStore() : Green(nullptr, 1, "Convenience Store", 2, "The player with the card gets 3 coins from the bank.", 6) {
        BaseCard::setIcon(getIconByName("bread"));
        size_t* actNumber = new size_t[1];
        actNumber[0] = 4;

        EstablishmentCard::setActivationNumbers(actNumber);
    };
    void activation(Player& p) override {};
};


class CheeseFactory : public Green {
public:
    CheeseFactory() : Green(nullptr, 1, "Bakery", 5, "Get 3 coins from the bank for each \"CowIcon\" establishment that you own, on your turn only.", 6) {
        BaseCard::setIcon(getIconByName("factory"));
        size_t* actNumber = new size_t[1];
        actNumber[0] = 7;

        EstablishmentCard::setActivationNumbers(actNumber);
    };
    void activation(Player& p) override {};
};


class FurnitureFactory : public Green {
public:
    FurnitureFactory() : Green(nullptr, 1, "Furniture Factory", 3, "Get 3 coins from the bank for each \"GearIcon\" establishment that you own, on your turn only.", 6) {
        BaseCard::setIcon(getIconByName("factory"));
        size_t* actNumber = new size_t[1];
        actNumber[0] = 8;

        EstablishmentCard::setActivationNumbers(actNumber);
    };
    void activation(Player& p) override {};
};


class FruitVegetableMarket : public Green {
public:
    FruitVegetableMarket() : Green(nullptr, 2, "Fruit and Vegetable Market", 2, "Get 3 coins from the bank for each \"WheatIcon\" establishment that you own, on your turn only.", 6) {
        BaseCard::setIcon(getIconByName("fruit"));
        size_t* actNumber = new size_t[2];
        actNumber[0] = 11;
        actNumber[1] = 12;

        EstablishmentCard::setActivationNumbers(actNumber);
    };
    void activation(Player& p) override {};
};


class Cafe : public Red {
public:
    Cafe() : Red(nullptr, 1, "Café", 2, "Get 1 coin from the player who rolled the dice.", 6) {
        BaseCard::setIcon(getIconByName("cup"));
        size_t* actNumber = new size_t[1];
        actNumber[0] = 3;


        EstablishmentCard::setActivationNumbers(actNumber);
    };
    void activation(Player& p) override {};
};


class FamilyRestaurant : public Red {
public:
    FamilyRestaurant() : Red(nullptr, 2, "Family Restaurant", 3, "Get 2 coins from the player who rolled the dice.", 6) {
        BaseCard::setIcon(getIconByName("cup"));
        size_t* actNumber = new size_t[2];
        actNumber[0] = 9;
        actNumber[1] = 10;


        EstablishmentCard::setActivationNumbers(actNumber);
    };
    void activation(Player& p) override {};
};

class Stadium : public Purple {
public:
    Stadium() : Purple(nullptr, 1, "Stadium", 6, "Get 2 coins from all players, on your turn only.", 4) {
        BaseCard::setIcon(getIconByName("major"));
        size_t* actNumber = new size_t[1];
        actNumber[0] = 6;


        EstablishmentCard::setActivationNumbers(actNumber);
    };
    void activation(Player& p) override {};
};


class TVStation : public Purple {
public:
    TVStation() : Purple(nullptr, 1, "TV Stadium", 7, "Take 5 coins from any one player, on your turn only.", 6) {
        BaseCard::setIcon(getIconByName("major"));
        size_t* actNumber = new size_t[1];
        actNumber[0] = 6;


        EstablishmentCard::setActivationNumbers(actNumber);
    };
    void activation(Player& p) override {};
};


class BusinessCenter : public Purple {
public:
    BusinessCenter() : Purple(nullptr, 1, "Business Center", 8,"Trade One Non \"MajorIcon\" establishment with another player, on your turn only.", 4) {
        BaseCard::setIcon(getIconByName("major"));
        size_t *actNumber = new size_t[1];
        actNumber[0] = 6;


        EstablishmentCard::setActivationNumbers(actNumber);
    };

    void activation(Player &p) override {};
};