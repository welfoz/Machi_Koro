#pragma once
#include "establishmentCard.h"

class Blue : public EstablishmentCard {
protected:
	Blue(size_t* act, size_t number, string name, size_t price, string desc) 
		: EstablishmentCard(act, number, name, Type::primaryIndustry, price, desc) {};
public:
	const Icon* getIconByName(string name);

	//méthode qui sera défini dans toutes autres cartes
	virtual void activation(Player& p) {};
};

class Green : public EstablishmentCard {
protected:
	Green(size_t* act, size_t number, string name, size_t price, string desc) 
		: EstablishmentCard(act, number, name, Type::secondaryIndustry, price, desc) {};
public:

	const Icon* getIconByName(string name);

	//méthode qui sera défini dans toutes autres cartes
	virtual void activation(Player& p) {};
};

class Red : public EstablishmentCard {
protected:
	Red(size_t* act, size_t number, string name, size_t price, string desc)
		: EstablishmentCard(act, number, name, Type::restaurants, price, desc) {};
public:

	const Icon* getIconByName(string name);

	//méthode qui sera défini dans toutes autres cartes
	virtual void activation(Player& p) {};
};

class Purple : public EstablishmentCard {
protected:
	Purple(size_t* act, size_t number, string name, size_t price, string desc) 
		: EstablishmentCard(act, number, name, Type::majorEstablishment, price, desc) {};
public:

	const Icon* getIconByName(string name);

	//méthode qui sera défini dans toutes autres cartes
	virtual void activation(Player& p) {};
};
