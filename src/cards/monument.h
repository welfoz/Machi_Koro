#pragma once
#include "baseCard.h"
#include "string"

using namespace std;

class Monument: public BaseCard {
public:
	Monument(string name, size_t price, string desc): BaseCard(name, Type::landmark, price, nullptr, desc) {
		setIcon(getIconByName("major"));
	};

	//check if the type of the icon is the same than the card type 
	// raise error if not
	const Icon* getIconByName(string name);
};
