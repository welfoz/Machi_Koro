//
// Created by jules on 05/12/2022.
//

#ifndef MACHI_KORO_GREENVALLEYEXTENSIONCARDS_H
#define MACHI_KORO_GREENVALLEYEXTENSIONCARDS_H


#pragma once
#include "greenValleyExtension.h"
#include "../../cards/cardColor.h"
#include <list>
#include "../../players/player.h"
#include "PlayerGreenValley.h"
#include "cmath"
class CornField : public Blue {
public:
    CornField() : Blue(nullptr, 2, "Corn Field", 2, "On anyone's turn : If you have less than 2 landmarks built, get 1 coin from the bank", 6) {
        BaseCard::setIcon(getIconByName("wheat"));
        size_t* actNumber = new size_t[2];
        actNumber[0] = 3;
        actNumber[1] = 4;
        EstablishmentCard::setActivationNumbers(actNumber);
    }
    void activation(Player& p) override ;
};

class Vineyard : public Blue {
public:
    Vineyard() : Blue(nullptr, 1, "Vineyard", 3, "On anyone's turn : Get 3 coins from the bank", 6) {
        BaseCard::setIcon(getIconByName("wheat"));
        size_t* actNumber = new size_t[1];
        actNumber[0] = 7;
        EstablishmentCard::setActivationNumbers(actNumber);
    }
    void activation(Player& p) override ;
};

class GeneralStore : public Green {
public:
    GeneralStore() : Green(nullptr, 1, "General Store", 0, "If you have less than 2 constructed landmarks, get 2 coins from the bank (your turn only)", 6) {
        BaseCard::setIcon(getIconByName("bread"));
        size_t* actNumber = new size_t[1];
        actNumber[0] = 2;
        EstablishmentCard::setActivationNumbers(actNumber);
    }
    void activation(Player& p) override ;
};

class MovingCompany : public Green {
public:
    MovingCompany() : Green(nullptr, 2, "Moving Company", 2, "You must give a non - Major Establishment building that you own to another player.When you do, get 4 coins from the bank (your turn only)", 6) {
        BaseCard::setIcon(getIconByName("suitcase"));
        size_t* actNumber = new size_t[2];
        actNumber[0] = 9;
        actNumber[1] = 10;
        EstablishmentCard::setActivationNumbers(actNumber);
    }
    void activation(Player& p) override ;
};

class LoanOffice : public Green {
public:
    LoanOffice() : Green(nullptr, 2, "Loan Office", 0, "When you construct this building, get 5 coins from the bank. When this building is activated, pay 2 coins to the bank (your turn only)", 6) {
        BaseCard::setIcon(getIconByName("suitcase"));
        size_t* actNumber = new size_t[2];
        actNumber[0] = 5;
        actNumber[1] = 6;
        EstablishmentCard::setActivationNumbers(actNumber);
    }
    void activation(Player& p) override;
};

class Winery : public Green {
public:
    Winery() : Green(nullptr, 1, "Winery", 3, "Get 6 coins for each Vineyard you own. Then, close this building for renovation (your turn only)", 6) {
        BaseCard::setIcon(getIconByName("factory"));
        size_t* actNumber = new size_t[1];
        actNumber[0] = 9;
        EstablishmentCard::setActivationNumbers(actNumber);
    }
    void activation(Player& p) override;
};

class DemolitionCompany : public Green {
public:
    DemolitionCompany() : Green(nullptr, 1, "Demolition Company", 2, "If possible, you must demolish one of your constructed landmarks by turning it back over to its unconstructed side. When you do get 8 coins from the bank", 6) {
        BaseCard::setIcon(getIconByName("suitcase"));
        size_t* actNumber = new size_t[1];
        actNumber[0] = 4;
        EstablishmentCard::setActivationNumbers(actNumber);
    }
    void activation(Player& p) override ;
};

class SodaBottlingPlant : public Green {
public:
    SodaBottlingPlant() : Green(nullptr, 1, "Soda Bottling Plant", 5, "Get 1 coin from the bank for every cup owned by all players (your turn only)", 6) {
        BaseCard::setIcon(getIconByName("factory"));
        size_t* actNumber = new size_t[1];
        actNumber[0] = 11;
        EstablishmentCard::setActivationNumbers(actNumber);
    }
    void activation(Player& p) override;
};

class FrenchRestaurant : public Red {
public:
    FrenchRestaurant() : Red(nullptr, 1, "French Restaurant", 3, "If the player who rolled this number has 2 or more constructed landmarks, get 5 coins from the player who rolled the dice", 6) {
        BaseCard::setIcon(getIconByName("cup"));
        size_t* actNumber = new size_t[1];
        actNumber[0] = 5;
        EstablishmentCard::setActivationNumbers(actNumber);
    }
    void activation(Player& p) override;
};

class MembersOnlyClub : public Red {
public:
    MembersOnlyClub() : Red(nullptr, 3, "Member's Ony Club", 4, "If the player who rolled this number has 3 or more constructed landmarks, get all of their coins", 6) {
        BaseCard::setIcon(getIconByName("cup"));
        size_t* actNumber = new size_t[3];
        actNumber[0] = 12;
        actNumber[1] = 13;
        actNumber[2] = 14;
        EstablishmentCard::setActivationNumbers(actNumber);
    }
    void activation(Player& p) override;
};

class Park : public Purple {
public:
    Park() : Purple(nullptr, 3, "Park", 3, "Redistribute all players' coins evenly among all players, on your turn only. If there is an uneven amount of coins, take coins from the bank to make up the difference", 5) {
        BaseCard::setIcon(getIconByName("major"));
        size_t* actNumber = new size_t[3];
        actNumber[0] = 11;
        actNumber[1] = 12;
        actNumber[2] = 13;
        EstablishmentCard::setActivationNumbers(actNumber);
    }
    void activation(Player& p) override ;
};

class RenovationCompany : public Purple {
public:
    RenovationCompany() : Purple(nullptr, 1, "Renovation Company", 4, "Choose a non-major building. All buildings owned by any player of that type are closed for renovations. Get 1 coin from each player for each of their buildings closed for renovation (your turn only)", 5) {
        BaseCard::setIcon(getIconByName("major"));
        size_t* actNumber = new size_t[1];
        actNumber[0] = 8;
        EstablishmentCard::setActivationNumbers(actNumber);
    }
    void activation(Player& p) override;
};

class TechStartup : public Purple {
    map<Player*,size_t> investments;
public:
    TechStartup() : Purple(nullptr, 1, "Tech Startup", 1, "At the end of each of your turns, you may place 1 coin on this card. The total placed here is your investment. When activated, get an amount equal to your investment from all player (your turn only)", 5), investments({}) {
        BaseCard::setIcon(getIconByName("major"));
        size_t* actNumber = new size_t[1];
        actNumber[0] = 10;
        EstablishmentCard::setActivationNumbers(actNumber);
    }
    const map<Player*, size_t> getInvestment() {return investments;}
    void invest(Player* player,size_t amount) {investments[player]++;}
    void activation(Player& p) override;
};

class InternationalExhibitHall : public Purple {
public:
    InternationalExhibitHall() : Purple(nullptr, 1, "International Exhibit Hall", 7, "You may choose to activate another of your non-major establishments in place of this one. If you do, return this card to the market (your turn only)", 5) {
        BaseCard::setIcon(getIconByName("major"));
        size_t* actNumber = new size_t[1];
        actNumber[0] = 10;
        EstablishmentCard::setActivationNumbers(actNumber);
    }
    void activation(Player& p) override;
};


#endif //MACHI_KORO_GREENVALLEYEXTENSIONCARDS_H
