#pragma once
#include <map>
#include "../cards/baseCard.h"
#include <vector>
#include <iostream>
#include <stdexcept>
#include "../cards/establishmentCard.h"
#include <algorithm>

using namespace std;
class Board
{
protected:
    map<EstablishmentCard*, size_t> cardsDecks;
public:
    Board(vector<EstablishmentCard*> cards);
    Board() = default;
    ~Board() = default;
    virtual void removeCard(EstablishmentCard* card);
    void addCard(EstablishmentCard* card);
    virtual void printBoard();
    size_t cheapestAvailableCardPrice() const;
    const size_t& getCard(EstablishmentCard* card) const {
        return cardsDecks.at(card);
    }
};
