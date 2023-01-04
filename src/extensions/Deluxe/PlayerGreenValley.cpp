//
// Created by jules on 10/12/2022.
//
#include "PlayerGreenValley.h"

void PlayerGreenValley::activateRedCards(size_t diceNumber){
    for(auto it=cardsCounter.begin();it!=cardsCounter.end();it++){
        if(it->first->getType()==Type::restaurants&& it->first->inActivationNumbers(diceNumber)){
            if (!isClosed(it->first)){
                for (size_t j = 0; j < it->second; j++) it->first->activation(*this);
            }
            else if (isClosed(it->first)) {
                open(it->first);
            }
        }
    }
}

vector<EstablishmentCard*> PlayerGreenValley::redCardsActivated(size_t diceNumber) {
    vector<EstablishmentCard*> activatedCards = {};
    for(auto it=cardsCounter.begin();it!=cardsCounter.end();it++){
        if(it->first->getType()==Type::restaurants&& it->first->inActivationNumbers(diceNumber))
            if (!isClosed(it->first)){
                for (size_t j = 0; j < it->second; j++) activatedCards.push_back(it->first);
            }
    }
    return activatedCards;
}

void PlayerGreenValley::activateBlueCards(size_t diceNumber){
    for(auto it=cardsCounter.begin();it!=cardsCounter.end();it++){
        if(it->first->getType()==Type::primaryIndustry&& it->first->inActivationNumbers(diceNumber)){
            if (!isClosed(it->first)){
                for (size_t j = 0; j < it->second; j++) it->first->activation(*this);
            }
            else if (isClosed(it->first)) {
                open(it->first);
            }
        }
    }
}

//this function is not used but could be in other extensions
vector<EstablishmentCard*> PlayerGreenValley::blueCardsActivated(size_t diceNumber) {
    vector<EstablishmentCard*> activatedCards = {};
    for(auto it=cardsCounter.begin();it!=cardsCounter.end();it++){
        if(it->first->getType()==Type::primaryIndustry&& it->first->inActivationNumbers(diceNumber))
            if (!isClosed(it->first)){
                for (size_t j = 0; j < it->second; j++) activatedCards.push_back(it->first);
            }
    }
    return activatedCards;
}

void PlayerGreenValley::activateGreenCards(size_t diceNumber){
    for(auto it=cardsCounter.begin();it!=cardsCounter.end();it++){
        if(it->first->getType()==Type::secondaryIndustry&& it->first->inActivationNumbers(diceNumber)){
            if (!isClosed(it->first)){
                for (size_t j = 0; j < it->second; j++) it->first->activation(*this);
            }
            else if (isClosed(it->first)) {
                open(it->first);
            }
        }
    }
}

vector<EstablishmentCard*> PlayerGreenValley::greenCardsActivated(size_t diceNumber) {
    vector<EstablishmentCard*> activatedCards = {};
    for(auto it=cardsCounter.begin();it!=cardsCounter.end();it++){
        if(it->first->getType()==Type::secondaryIndustry&& it->first->inActivationNumbers(diceNumber))
            if (!isClosed(it->first)){
                for (size_t j = 0; j < it->second; j++) activatedCards.push_back(it->first);
            }
    }
    return activatedCards;
}

void PlayerGreenValley::activatePurpleCards(size_t diceNumber){
    for(auto it=cardsCounter.begin();it!=cardsCounter.end();it++){
        if(it->first->getType()==Type::majorEstablishment&& it->first->inActivationNumbers(diceNumber)){
            if (!isClosed(it->first)){
                for (size_t j = 0; j < it->second; j++) it->first->activation(*this);
            }
            else if (isClosed(it->first)) {
                open(it->first);
            }
        }
    }
}

//this function is not used but could be in other extensions
vector<EstablishmentCard*> PlayerGreenValley::purpleCardsActivated(size_t diceNumber) {
    vector<EstablishmentCard*> activatedCards = {};
    for(auto it=cardsCounter.begin();it!=cardsCounter.end();it++){
        if(it->first->getType()==Type::majorEstablishment&& it->first->inActivationNumbers(diceNumber))
            if (!isClosed(it->first)){
                for (size_t j = 0; j < it->second; j++) activatedCards.push_back(it->first);
            }
    }
    return activatedCards;
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
