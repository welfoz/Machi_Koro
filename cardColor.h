
#ifndef MACHI_KORO_CARTECOULEUR_H
#define MACHI_KORO_CARTECOULEUR_H
#include "establismentCard.h"
#include "joueur.h"
#include "dice.h"

class Blue : private EstablishmentCard {
protected:
	Blue(size_t* act, size_t number, string name, size_t price, string desc) 
		: EstablishmentCard(act, number, name, Type::primaryIndustry, price, desc) {};
public:

	const Icon* getIcon(string name);

	//méthode qui sera défini dans toutes autres cartes
	virtual void activation();
};

class Green : private EstablishmentCard {
protected:
	Green(size_t* act, size_t number, string name, size_t price, string desc) 
		: EstablishmentCard(act, number, name, Type::secondaryIndustry, price, desc) {};
public:

	const Icon* getIcon(string name);

	//méthode qui sera défini dans toutes autres cartes
	virtual void activation();
};

class Red : private EstablishmentCard {
protected:
	Red(size_t* act, size_t number, string name, size_t price, string desc)
		: EstablishmentCard(act, number, name, Type::restaurants, price, desc) {};
public:

	const Icon* getIcon(string name);

	//méthode qui sera défini dans toutes autres cartes
	virtual void activation();
};

class Purple : private EstablishmentCard {
protected:
	Purple(size_t* act, size_t number, string name, size_t price, string desc) 
		: EstablishmentCard(act, number, name, Type::majorEstablishment, price, desc) {};
public:

	const Icon* getIcon(string name);

	//méthode qui sera défini dans toutes autres cartes
	virtual void activation();
};




#endif // MACHI_KORO_CARTECOULEUR_H
