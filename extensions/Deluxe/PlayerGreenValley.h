//
// Created by jules on 10/12/2022.
//
#pragma once
#ifndef MACHI_KORO_PLAYERGREENVALLEY_H
#define MACHI_KORO_PLAYERGREENVALLEY_H
#include "../../players/player.h"
#include "../../formatter/formatter.h"

class PlayerGreenValley : public Player {
private:
    map<EstablishmentCard*, bool> closed;
public :
    PlayerGreenValley(string name, size_t id, vector<Monument*> monuments, vector<EstablishmentCard*> cards, map<EstablishmentCard*,bool>closed={}, bool iP=false) : Player(name,id,monuments,cards,iP),  closed(closed){};
    bool isClosed(EstablishmentCard* card);
    void close(EstablishmentCard* card);
    void open(EstablishmentCard* card);
    void activateBlueCards(size_t diceNumber) override;
    vector<EstablishmentCard *> activateGreenCards(size_t diceNumber) override;
    vector<EstablishmentCard *> activateRedCards(size_t diceNumber) override;
    void activatePurpleCards(size_t diceNumber) override;
    const map<EstablishmentCard*, bool>& getClosedCards() const {return closed;}
    void purchaseEstablishment(EstablishmentCard* card);
};


#endif //MACHI_KORO_PLAYERGREENVALLEY_H
