//
// Created by jules on 10/12/2022.
//
#include "PlayerGreenValley.h"
vector<EstablishmentCard*> PlayerGreenValley::activateRedCards(size_t diceNumber) {
    vector<EstablishmentCard*> activatedCards = {};
    for(auto it=cardsCounter.begin();it!=cardsCounter.end();it++){
        if(it->first->getType()==Type::restaurants&& it->first->inActivationNumbers(diceNumber))
            if (!isClosed(it->first)){
                for (size_t j = 0; j < it->second; j++)
                {
                    it->first->activation(*this);
                    activatedCards.push_back(it->first);
                }
            }
            else if (isClosed(it->first)) {
                open(it->first);
            }

    }
    return activatedCards;
}

void PlayerGreenValley::activateBlueCards(size_t diceNumber){
    for(auto it=cardsCounter.begin();it!=cardsCounter.end();it++){
        if(it->first->getType()==Type::primaryIndustry&& it->first->inActivationNumbers(diceNumber)){
            if (!isClosed(it->first)) {
                for (size_t j = 0; j < it->second; j++) it->first->activation(*this);
            }
            else if (isClosed(it->first)) {
                open(it->first);
            }
        }
    }
}
vector<EstablishmentCard*> PlayerGreenValley::activateGreenCards(size_t diceNumber){
    vector<EstablishmentCard*> activatedCards = {};
    for(auto it=cardsCounter.begin();it!=cardsCounter.end();it++){
        if(it->first->getType()==Type::secondaryIndustry&& it->first->inActivationNumbers(diceNumber)){
            if (!isClosed(it->first)) {
                for (size_t j = 0; j < it->second; j++) {
                    it->first->activation(*this);
                    activatedCards.push_back(it->first);
                }
            }
            else if (isClosed(it->first)) {
                open(it->first);
            }
        }
    }
    return activatedCards;
}
void PlayerGreenValley::activatePurpleCards(size_t diceNumber){
    for(auto it=cardsCounter.begin();it!=cardsCounter.end();it++){
        if(it->first->getType()==Type::majorEstablishment&& it->first->inActivationNumbers(diceNumber)){
            if (!isClosed(it->first)) {
                for (size_t j = 0; j < it->second; j++) it->first->activation(*this);
            }
            else if (isClosed(it->first)) {
                open(it->first);
            }
        }
    }
}

bool PlayerGreenValley::isClosed(EstablishmentCard *card) {
    if (closed.count(card)) return true;
    return false;
}
void PlayerGreenValley::close(EstablishmentCard *card) {
    closed[card]=true;// operateur[] ajoute l'élément si il n'existe pas déja
}
void PlayerGreenValley::open(EstablishmentCard* card){
    closed.erase(card);
}

void PlayerGreenValley::printCards() const {
    cout << "\n" << this->username << "'s cards: \n";
    vector<pair<string, unsigned int>> headerNames;
    headerNames = {
            {" Name", 31},
            {"Closed", 1},
            {"Price", 5},
            {"Activation Nb", 13},
            {"Quantity", 8},
            {"Type" , 20},
            {"Icon", 8},
            {"Effect", 60}
    };
    cout << Formatter::formatHeader(headerNames);
    for (auto it = cardsCounter.begin(); it != cardsCounter.end(); it++) {
        if (it->second>0){
            // get all activation numbers
            string activationNumbers;
            size_t* actNumbers = it->first->getActivationNumbers();
            for (unsigned int i = 0; i < it->first->getNumberActivation(); i++) {
                activationNumbers += std::to_string(*actNumbers) + ' ';
                actNumbers++;
            }
            if (closed.count(it->first))
            cout << " " << Formatter::format(it->first->getName(), headerNames[0].second - 1)<<Formatter::format(std::to_string(closed.count(it->first)),headerNames[1].second) << Formatter::format(std::to_string(it->first->getPrice()), headerNames[2].second) << Formatter::format(activationNumbers, headerNames[3].second);
            cout << Formatter::format(std::to_string(it->second), headerNames[4].second) << Formatter::format(BaseCard::typeToString(it->first->getType()), headerNames[5].second) << Formatter::format(it->first->getIcon()->getName(), headerNames[6].second) << it->first->getEffetDescription() << "\n";
        }

    }
}
