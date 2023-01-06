#include "board.h"

Board::Board(vector<EstablishmentCard*> cards) {
    for (auto it = cards.begin(); it != cards.end(); it++) {
        cardsDecks.insert({ *it, cards[it - cards.begin()]->getQuantity() });
    }
};

// Regarde l'emplacement de la carte dans le Board et ajoute +1
void Board::addCard(EstablishmentCard* card) {
    if (cardsDecks.count(card))
        cardsDecks.at(card)++;
    else cardsDecks.insert({card, 1});
}

void Board::removeCard(EstablishmentCard* card) {
	auto search = cardsDecks.find(card);
    if (search != cardsDecks.end()) {
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

bool Board::isAnyCardLeftToBuy() const {
    if (cheapestAvailableCardPrice() < 0) { // important de laisser <0 car il y a une carte dont le prix est 0
        return false;
    }
    return true;
}
