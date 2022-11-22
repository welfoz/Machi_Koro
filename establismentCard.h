//
// Created by jules on 12/11/2022.
//

//#ifndef MACHI_KORO_CARTE_H
//#define MACHI_KORO_CARTE_H
#include "baseCard.h"

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

    bool inActivationNumeros(size_t diceNumber) const;
	
	size_t getNumberActivation() const {
		return numberActivation;
	};

	size_t* const getActivationNumbers() const {
		return activationNumbers;
	}
};

//#endif //MACHI_KORO_CARTE_H
