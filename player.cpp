#pragma once
#include "player.h"

Player::Player(int id, std::string username, int nbmonument) : id(id), username(username), nbMonument(nbmonument){// comment initialiser l' attribut monument;

}

void Player::purchaseEstablishment(EstablishmentCard &card){ // Le jeu se charge de la transaction ?
    if (cardsCounter.count(&card)==0) cardsCounter.insert(pair<EstablishmentCard*,::size_t>(&card,1));
    else cardsCounter[&card]+=1;
}

void Player::purchaseMonument(Monument &card) {
    if (!monuments[&card]) monuments[&card]=true;
}

const size_t Player::nbDiceChosen() const{ // est appelé par le jeu seulement si le joueur posède station
    if (!getMonument("Station")) return 1;
    size_t n=0;
    while (n>2 || n<1){
        cout<<"How many dice do you chose to roll ?\n"<<endl;
        cin>>n;
        if (n>2 || n<1) cout<<"Veuillez choisir un nombre entre 1 et 2\n"<<endl;
    }
    return n;
}

void Player::activateRedCards(size_t diceNumber) {
    for(auto it=cardsCounter.begin();it!=cardsCounter.end();it++){
        if(it->first->getType()=="Restaurants"&& it->first->inActivationNumbers(diceNumber)) it->first->activation(*this);
    }
}
void Player::activateBlueCards(size_t diceNumber){
    for(auto it=cardsCounter.begin();it!=cardsCounter.end();it++){
        if(it->first->getType()=="Primary Industry"&& it->first->inActivationNumbers(diceNumber)) it->first->activation(*this);
    }
}
void Player::activateGreenCards(size_t diceNumber){
    for(auto it=cardsCounter.begin();it!=cardsCounter.end();it++){
        if(it->first->getType()=="Secondary Industry"&& it->first->inActivationNumbers(diceNumber)) it->first->activation(*this);
    }
}
void Player::activatePurpleCards(size_t diceNumber){
    for(auto it=cardsCounter.begin();it!=cardsCounter.end();it++){
        if(it->first->getType()=="Major Establishment"&& it->first->inActivationNumbers(diceNumber)) it->first->activation(*this);
    }
}

bool Player::getMonument(std::string name) const {
    for (auto it=monuments.begin();it!=monuments.end();it++){
        if (it->first->getName()==name) return it->second;
    }
    return false;
}

const string& Player::getUsername() const {
    return username;
}

const size_t& Player::getId() const {
    return id;
}
