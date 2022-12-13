#include "marinaBoard.h"

MarinaBoard::MarinaBoard(vector<EstablishmentCard*> cards){
     for (auto it = cards.begin(); it != cards.end(); it++) {
        for (size_t i = 0; i < cards[it - cards.begin()]->getQuantity(); i++) pile.push_back(*it);
    }
    auto rd = std::random_device {}; 
    auto rng = std::default_random_engine { rd() };
    std::shuffle(std::begin(pile), std::end(pile), rng);
    checkNumberOfDecks();
    };

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