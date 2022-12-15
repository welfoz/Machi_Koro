#include "marinaBoard.h"

MarinaBoard::MarinaBoard(vector<EstablishmentCard*> cards){
     for (auto it = cards.begin(); it != cards.end(); it++) {
        for (size_t i = 0; i < cards[it - cards.begin()]->getQuantity(); i++) pile.push_back(*it);
    }
    std::random_device rd; 
    auto rng = std::default_random_engine { rd() };
    std::shuffle(std::begin(pile), std::end(pile), rng);
    checkNumberOfDecks();
}

// TO REFRACTOR CONTROLLER
//void MarinaBoard::printBoard(){
//    checkNumberOfDecks();
//    Board::printBoard();
//}

void MarinaBoard::checkNumberOfDecks() {
    while ((pile.size() > 0) && (cardsDecks.size() < 10))
    {
        addCard(pile.back());
        pile.pop_back();
    }
    
}

void MarinaBoard::removeCard(EstablishmentCard* card){
	auto search = cardsDecks.find(card);
    if ( search != cardsDecks.end()) {
        if (cardsDecks.at(card) == 1) cardsDecks.erase(card);
        else cardsDecks.at(card)--;
    }
    else
    {
        //ERREUR
        throw("ERROR : There's no card to remove here.");
    }
}