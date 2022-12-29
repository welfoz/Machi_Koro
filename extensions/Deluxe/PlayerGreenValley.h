#pragma once
#include "../../players/player.h"
#include "../../formatter/formatter.h"

class PlayerGreenValley : public Player {
private:
    map<EstablishmentCard*, bool> closed;
public :
    PlayerGreenValley(string name, size_t id, vector<Monument*> monuments, vector<EstablishmentCard*> cards,bool isAi, map<EstablishmentCard*,bool>closed={},bool iP=false) : Player(name,id,monuments,cards,isAi,iP),  closed(closed){};
    bool isClosed(EstablishmentCard* card);
    void close(EstablishmentCard* card);
    void open(EstablishmentCard* card);
    void activateBlueCards(size_t diceNumber) override;
    vector<EstablishmentCard *> activateGreenCards(size_t diceNumber) override;
    vector<EstablishmentCard *> activateRedCards(size_t diceNumber) override;
    void activatePurpleCards(size_t diceNumber) override;
    const map<EstablishmentCard*, bool>& getClosedCards() const {return closed;}
};
