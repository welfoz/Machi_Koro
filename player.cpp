#include "player.h"

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

void Player::purchaseCard(EstablishmentCard* card) {
	// Increment the counter of this card
	// if the cards isn't yet counted, set the counter to 1
	auto itCardsCounter = cardsCounter.find(card);
	if (itCardsCounter != cardsCounter.end()) {
		cardsCounter[card]++;
	}
	else {
		this->cardsCounter.insert({ card, 1 });
	}
}

Player::Player(string name, size_t id, vector<Monument*> monuments, vector<EstablishmentCard*> cards) : username(name), id(id) {
	for (auto it = monuments.begin(); it != monuments.end(); it++) {
		// init all monuments to false
		this->monuments.insert({ *it, 0 });
	}

	for (auto it = cards.begin(); it != cards.end(); it++) {
		purchaseCard(*it);
	}
	printCards();
};

void Player::printCards() const {
	cout << username << " cards : \n";
	for (auto it = cardsCounter.begin(); it != cardsCounter.end(); it++) {
		cout << it->first->getName() << " : " << it->second << "\n";
	}

}