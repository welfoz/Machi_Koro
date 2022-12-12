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
    auto it=find_if(closed.begin(),closed.end(),[card](pair<EstablishmentCard*,bool> elem){return elem.first==card;});
    if (it!=closed.end()) return it->second;
    else return false;// pour l'edition standard où closed n'est pas initialisé - tjr retourner false
}
void PlayerGreenValley::close(EstablishmentCard *card) {
    closed[card]=true;// operateur[] ajoute l'élément si il n'existe pas déja
}
void PlayerGreenValley::open(EstablishmentCard* card){
    closed.at(card)=false;
}
