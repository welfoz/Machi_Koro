#include "board.h"
#include "../formatter/formatter.h"

Board::Board(vector<EstablishmentCard*> cards) {
    for (auto it = cards.begin(); it != cards.end(); it++) {
        cardsDecks.insert({ *it, cards[it - cards.begin()]->getQuantity() });
    }
};

Board::~Board(){};

// Regarde l'emplacement de la carte dans le Board et ajoute +1
void Board::addCard(EstablishmentCard* card) {
    cardsDecks.at(card)++;
}

void Board::removeCard(EstablishmentCard* card) {
    if (cardsDecks.at(card) != 0) {
        cardsDecks.at(card)--;
    }
    else
    {
        //ERREUR
        throw("ERROR : There's no card to remove here.");
    }
}

size_t Board::cheapestAvailableCardPrice() const {
    auto it=std::find_if(cardsDecks.begin(),cardsDecks.end(),[](pair<EstablishmentCard*,size_t> it) {return it.second!=0;});
    size_t min=-1;
    if (it!=cardsDecks.end()){
        min=it->first->getPrice();
        for (;it!=cardsDecks.end();it++){
            if (it->first->getPrice()<min && it->second>0) min=it->first->getPrice();
        }
    }
    return min;
}

