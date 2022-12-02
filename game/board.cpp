#include "board.h"
#include "../formatter.h"

Board::Board(vector<EstablishmentCard*> cards) {
    for (auto it = cards.begin(); it != cards.end(); it++) {
        cardsDecks.insert({ *it, cards[it - cards.begin()]->getQuantity() });
    }
};

Board::~Board(){};

void Board::printBoard()
{
	cout <<"\nBoard's cards: \n";
    vector<pair<string, unsigned int>> headerNames;
    headerNames = {
        {" Name", 31},
        {"Price", 5},
        {"Activation Nb", 13},
        {"Quantity", 8},
        {"Type" , 20},
        {"Icon", 8},
        {"Effect", 0}
	};
    cout << Formatter::formatHeader(headerNames);
    for (auto it = cardsDecks.begin(); it != cardsDecks.end(); it++) {

        // get all activation numbers
        string activationNumbers;
        size_t* actNumbers = it->first->getActivationNumbers();
        for (unsigned int i = 0; i < it->first->getNumberActivation(); i++) {
            activationNumbers += std::to_string(*actNumbers) + ' ';
            actNumbers++;
        }

        cout << " " << Formatter::format(it->first->getName(), headerNames[0].second - 1) << Formatter::format(std::to_string(it->first->getPrice()), headerNames[1].second) << Formatter::format(activationNumbers, headerNames[2].second);
        cout << Formatter::format(std::to_string(it->second), headerNames[3].second) << Formatter::format(BaseCard::typeToString(it->first->getType()), headerNames[4].second) << Formatter::format(it->first->getIcon()->getName(), headerNames[5].second) << it->first->getEffetDescription() << "\n";

    }
};


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
