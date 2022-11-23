#include "player.h"
#include "account.h"
#include "monument.h"
#include "establishmentCard.h"
#include"baseCard.h"

void Player::activateRedCards(size_t nombreTire) {
    for(auto it=cardsCounter.begin();it!=cardsCounter.end();it++){
        if(it->first->getType()=="Restaurants"&& it->first->inActivationNumbers(nombreTire)) it->first->activation(*this);
    }
}
void Player::activateBlueCards(size_t nombreTire){
    for(auto it=cardsCounter.begin();it!=cardsCounter.end();it++){
        if(it->first->getType()=="Primary Iindustry"&& it->first->inActivationNumbers(nombreTire)) it->first->activation(*this);
    }
}
void Player::activateGreenCards(size_t nombreTire){
    for(auto it=cardsCounter.begin();it!=cardsCounter.end();it++){
        if(it->first->getType()=="Secondary Iindustry"&& it->first->inActivationNumbers(nombreTire)) it->first->activation(*this);
    }
}
void Player::activatePurpleCards(size_t nombreTire){
    for(auto it=cardsCounter.begin();it!=cardsCounter.end();it++){
        if(it->first->getType()=="Major Establishment"&& it->first->inActivationNumbers(nombreTire)) it->first->activation(*this);
    }
}