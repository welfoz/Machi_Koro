#pragma once
#include "establishmentCard.h"

class Blue : public EstablishmentCard {
protected:
	Blue(size_t* act, size_t number, string name, size_t price, string desc, size_t quantity) 
		: EstablishmentCard(act, number, name, Type::primaryIndustry, price, desc, quantity) {};
public:
	const Icon* getIconByName(string name);

	//méthode qui sera définie dans toutes autres cartes
	virtual void activation(Player& p) {};
};

class Green : private EstablishmentCard {
protected:
	Green(size_t* act, size_t number, string name, size_t price, string desc, size_t quantity) 
		: EstablishmentCard(act, number, name, Type::secondaryIndustry, price, desc, quantity) {};
public:

	const Icon* getIconByName(string name);

	//méthode qui sera définie dans toutes autres cartes
	virtual void activation(Player& p) {};
};

class Red : private EstablishmentCard {
protected:
	Red(size_t* act, size_t number, string name, size_t price, string desc, size_t quantity)
		: EstablishmentCard(act, number, name, Type::restaurants, price, desc, quantity) {};
public:

	const Icon* getIconByName(string name);

	//méthode qui sera définie dans toutes autres cartes
	virtual void activation(Player& p) {};
};

class Purple : private EstablishmentCard {
protected:
	Purple(size_t* act, size_t number, string name, size_t price, string desc, size_t quantity) 
		: EstablishmentCard(act, number, name, Type::majorEstablishment, price, desc, quantity) {};
public:

	const Icon* getIconByName(string name);

	//méthode qui sera définie dans toutes autres cartes
	virtual void activation(Player& p) {};
};
