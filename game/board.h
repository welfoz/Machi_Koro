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
    size_t cheapestAvailableCardPrice() const;
    const size_t& getCard(EstablishmentCard* card) const {
        return cardsDecks.at(card);
    }
    const map<EstablishmentCard*, size_t>& getCards() const {
        return cardsDecks;
    }
};
