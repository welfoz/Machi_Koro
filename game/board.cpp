#include <iostream>
#include <stdexcept>
#include "board.h"

Board::Board(vector<EstablishmentCard*> cards) {
    for (auto it = cards.begin(); it != cards.end(); it++) {
        cardsDecks.insert({ *it, cards[it - cards.begin()]->getQuantity() });
    }
};

Board::~Board(){};
void Board::printBoard(){};


// Regarde l'emplacement de la carte dans le Board et ajoute +1
void Board::addCard(EstablishmentCard& card) {
    cardsDecks.at(&card)++;
}

void Board::removeCard(EstablishmentCard& card) {
    if (cardsDecks.at(&card) != 0) {
        cardsDecks.at(&card)--;
    }
    else
    {
        //ERREUR
        throw("ERROR : There's no card to remove here.");
    }
}
