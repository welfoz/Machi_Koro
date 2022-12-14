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
private:
    map<EstablishmentCard*, size_t> cardsDecks;
public:
    Board(vector<EstablishmentCard*> cards);

    ~Board();
    void removeCard(EstablishmentCard* card);
    void addCard(EstablishmentCard* card);
    size_t cheapestAvailableCardPrice() const;
    bool isAnyCardLeftToBuy() const;
    const size_t& getCard(EstablishmentCard* card) const {
        return cardsDecks.at(card);
    }
    const map<EstablishmentCard*, size_t>& getCards() const {
        return cardsDecks;
    }
};
