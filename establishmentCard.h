#pragma once
#include "baseCard.h"
#include "player.h"
class Player;

class EstablishmentCard : public BaseCard {
	size_t* activationNumbers;
	size_t numberActivation;
protected:
	EstablishmentCard(size_t* act, size_t number, string name, Type type, size_t price, string desc) : BaseCard(name, type, price, nullptr, desc), activationNumbers(act), numberActivation(number) {
	};
public:
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
};
