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
    void printBoard();
    size_t cheapestAvailableCardPrice() const;
    const size_t& getCard(EstablishmentCard* card) const {
        return cardsDecks.at(card);
    }
};
