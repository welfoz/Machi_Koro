#pragma once
#include "baseCard.h"
class Player;

class EstablishmentCard : public BaseCard {
    friend class Game;
	size_t* activationNumbers;
	const size_t numberActivation;
	const size_t quantity;
protected:
	EstablishmentCard(size_t* act, size_t number, string name, Type type, size_t price, string desc, size_t quantity) : BaseCard(name, type, price, nullptr, desc), activationNumbers(act), numberActivation(number), quantity(quantity) {
	};
    ~EstablishmentCard() {};
public:
	virtual const Icon* getIconByName(string name) = 0;
	void setActivationNumbers(size_t* const act) {
		activationNumbers = act;
	}

    bool inActivationNumbers(size_t diceNumber) const;

	size_t getNumberActivation() const {
		return numberActivation;
	};

	size_t* const getActivationNumbers() const {
		return activationNumbers;
	}
	virtual void activation(Player& p) {};
	
	const size_t getQuantity() const {
		return quantity;
	}
};
