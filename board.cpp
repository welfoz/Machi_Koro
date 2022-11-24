#include "board.h"

Board::Board(vector<EstablishmentCard*> cards) {
    for (auto it = cards.begin(); it != cards.end(); it++) {
        cardsDecks.insert({ *it, cards[it - cards.begin()]->getQuantity() });
    }
};

Board::~Board(){};
// BaseCard& Board::removeCard(BaseCard& card){};
// BaseCard& Board::addCard(BaseCard& card){};
void Board::printBoard(){};
