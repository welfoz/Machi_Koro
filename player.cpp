#pragma once
#include "player.h"
#include "account.h"
#include "monument.h"
#include "establishmentCard.h"
#include"baseCard.h"

void Player::activateRedCards(size_t diceNumber) {
    for(auto it=cardsCounter.begin();it!=cardsCounter.end();it++){
        if(it->first->getType()=="Restaurants"&& it->first->inActivationNumbers(diceNumber)) it->first->activation(*this);
    }
}
void Player::activateBlueCards(size_t diceNumber){
    for(auto it=cardsCounter.begin();it!=cardsCounter.end();it++){
        if(it->first->getType()=="Primary Iindustry"&& it->first->inActivationNumbers(diceNumber)) it->first->activation(*this);
    }
}
void Player::activateGreenCards(size_t diceNumber){
    for(auto it=cardsCounter.begin();it!=cardsCounter.end();it++){
        if(it->first->getType()=="Secondary Iindustry"&& it->first->inActivationNumbers(diceNumber)) it->first->activation(*this);
    }
}
void Player::activatePurpleCards(size_t diceNumber){
    for(auto it=cardsCounter.begin();it!=cardsCounter.end();it++){
        if(it->first->getType()=="Major Establishment"&& it->first->inActivationNumbers(diceNumber)) it->first->activation(*this);
    }
}