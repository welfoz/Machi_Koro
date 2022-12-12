#include "marinaBoard.h"

void MarinaBoard::printBoard(){
    checkNumberOfDecks();
    Board::printBoard();
};

void MarinaBoard::checkNumberOfDecks() {
    while ((pile.size() > 0) && (cardsDecks.size() < 10))
    {
        addCard(pile.back());
        pile.pop_back();
    }
    
};