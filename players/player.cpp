#include "player.h"
#include "../formatter/formatter.h"
#include "../game/game.h"

void Player::purchaseMonument(Monument* card) {
    if (!monuments[card]) monuments[card]=true;
}
vector<EstablishmentCard*> Player::activateRedCards(size_t diceNumber) {
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

void Player::activateBlueCards(size_t diceNumber){
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
vector<EstablishmentCard*> Player::activateGreenCards(size_t diceNumber){
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
void Player::activatePurpleCards(size_t diceNumber){
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

bool Player::getMonument(std::string name) const {
    for (auto it=monuments.begin();it!=monuments.end();it++){
        if (it->first->getName()==name) return it->second;
    }
    return false;
}

const size_t& Player::getId() const {
    return id;
}


void Player::purchaseEstablishment(EstablishmentCard* card) {
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

Player::Player(string name, size_t id, vector<Monument*> monuments, vector<EstablishmentCard*> cards, map<EstablishmentCard*,bool>closed, bool iP) : username(name), id(id), isPlaying(iP), closed(closed){
	for (auto it = monuments.begin(); it != monuments.end(); it++) {
		// init all monuments to false
		this->monuments.insert({ *it, 0});
	}

	for (auto it = cards.begin(); it != cards.end(); it++) {
		purchaseEstablishment(*it);
	}
    Game::getInstance().getInterface()->printBasicMessage(name + " added!\n");
};

size_t Player::cheapestMonumentAvailablePrice() const {
    auto it= find_if(monuments.begin(),monuments.end(),[](pair<Monument*,bool> it){return it.second==false;});
    size_t min=0;
    if(it!=monuments.end()){
        min=it->first->getPrice();
        for (;it!=monuments.end();it++){
            if (it->first->getPrice()<min) min=it->first->getPrice();
        }
    }
    return min;
}

void Player::removeMonument(Monument* card) {
	monuments[card] = false;
}

void Player::removeEstablishment(EstablishmentCard* card) {
	auto it = cardsCounter.find(card);
	if (it != cardsCounter.end() && it->second == 0) {
		throw "No card available";
	}
	cardsCounter[card]--;
}

bool Player::isClosed(EstablishmentCard *card) {
    auto it=find_if(closed.begin(),closed.end(),[card](pair<EstablishmentCard*,bool> elem){return elem.first==card;});
    if (it!=closed.end()) return it->second;
    else return false;// pour l'edition standard où closed n'est pas initialisé - tjr retourner false
}
void Player::close(EstablishmentCard *card) {
    closed[card]=true;// operateur[] ajoute l'élément si il n'existe pas déja
}
void Player::open(EstablishmentCard* card){
    closed.at(card)=false;
}

const size_t Player::getNbMonumentsActivated() const{
    size_t nb=0;
    for (auto it : monuments) if (it.second) nb++;
    return nb;
}


EstablishmentCard* Player::getCardByName(string name) const {
    auto it = find_if(cardsCounter.begin(), cardsCounter.end(), [&name](std::pair<EstablishmentCard* const, size_t> obj) {return obj.first->getName() == name; });
	if (it != cardsCounter.end()) {
        //found the name!
        return it->first;
    }
    string error = "error getCardByName, didn't find : " + name + "\n";
    throw invalid_argument(error);
}
