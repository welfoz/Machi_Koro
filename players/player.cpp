
#include "player.h"
#include "../formatter/formatter.h"
#include "../cards/allCards.h"

void Player::purchaseMonument(Monument* card) {
    if (!monuments[card]) monuments[card]=true;
}
void Player::activateRedCards(size_t diceNumber) {
    for(auto it=cardsCounter.begin();it!=cardsCounter.end();it++){
        if(it->first->getType()==Type::restaurants&& it->first->inActivationNumbers(diceNumber))
            for (size_t j=0;j<it->second;j++) it->first->activation(*this);
    }
}
void Player::activateBlueCards(size_t diceNumber){
    for(auto it=cardsCounter.begin();it!=cardsCounter.end();it++){
        if(it->first->getType()==Type::primaryIndustry&& it->first->inActivationNumbers(diceNumber))
            for (size_t j=0;j<it->second;j++) it->first->activation(*this);
    }
}
void Player::activateGreenCards(size_t diceNumber){
    for(auto it=cardsCounter.begin();it!=cardsCounter.end();it++){
        if(it->first->getType()==Type::secondaryIndustry&& it->first->inActivationNumbers(diceNumber))
            for (size_t j=0;j<it->second;j++) it->first->activation(*this);
    }
}
void Player::activatePurpleCards(size_t diceNumber){
    for(auto it=cardsCounter.begin();it!=cardsCounter.end();it++){
        if(it->first->getType()==Type::majorEstablishment&& it->first->inActivationNumbers(diceNumber))
            for (size_t j=0;j<it->second;j++) it->first->activation(*this);
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

Player::Player(string name, size_t id, vector<Monument*> monuments, vector<EstablishmentCard*> cards, bool iP) : username(name), id(id), isPlaying(iP) {
	for (auto it = monuments.begin(); it != monuments.end(); it++) {
		// init all monuments to false
		this->monuments.insert({ *it, 0});
	}

	for (auto it = cards.begin(); it != cards.end(); it++) {
		purchaseEstablishment(*it);
	}
	cout << name << " added!\n";
};

void Player::printCards() const {
	cout << "\n" << username << "'s cards: \n";
	vector<pair<string, unsigned int>> headerNames;
	headerNames = {
		{" Name", 31},
		{"Price", 5},
		{"Activation Nb", 13},
		{"Quantity", 8},
		{"Type" , 20},
		{"Icon", 8},
		{"Effect", 60}
	};
    cout << Formatter::formatHeader(headerNames);
	for (auto it = cardsCounter.begin(); it != cardsCounter.end(); it++) {

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
}

void Player::printMonuments() const {
	cout << "\n" << username << "'s monuments: \n";
	vector<pair<string, unsigned int>> headerNames;
	headerNames = {
		{" Name", 31},
		{"Activated", 9},
		{"Price", 5},
		{"Type" , 20},
		{"Icon", 8},
		{"Effect", 50}
	};
	cout << Formatter::formatHeader(headerNames);
	for (auto it = monuments.begin(); it != monuments.end(); it++) {

		cout << " " << Formatter::format(it->first->getName(), headerNames[0].second - 1) << Formatter::format(std::to_string(it->second), headerNames[1].second) << Formatter::format(std::to_string(it->first->getPrice()), headerNames[2].second);
		cout << Formatter::format(BaseCard::typeToString(it->first->getType()), headerNames[3].second);
		cout << Formatter::format(it->first->getIcon()->getName(), headerNames[4].second);
		cout << it->first->getEffetDescription() << "\n";
	}
}
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