#ifndef MACHI_KORO_CARTECOULEUR_H
#define MACHI_KORO_CARTECOULEUR_H
#include "carte.h"
#include "joueur.h"
#include "de.h"

class Bleu : private Carte {
public:
	Bleu()  { type = "Primary Industrie"; };
	//IconBlue getIconBlue();
	const IconPrimaryIndustryExtension& getIcons() const {
		return IconPrimaryIndustryExtension();
	}
	void effet();
	//méthode qui sera défini dans toutes autres cartes
	virtual void activation(class De de);
	//verifie si le dé tiré est égale à l'activation des nums de la carte
};

class Vert : private Carte {
public:
	Vert() { type = "Secondary Industrie"; };
	const IconSecondaryIndustryExtension& getIcons() const {
		return IconSecondaryIndustryExtension();
	}
	void effet(class Joueur j){
        activation(j);
    }
	virtual void activation(class Joueur j);
	//verifie si le dé tiré par le joueur est égale à l'activation des nums de la carte
};

class Rouge : private Carte {
    friend class Joueur;
public:
	Rouge() { type = "Restaurant"; };
	const IconRestaurantExtension& getIcons() const {
		return IconRestaurantExtension();
	}
	void effet();
	virtual void activation(class De de);
};

class Violet : private Carte {
public:
	Violet() { type = "Major Establishment"; };
	IconPurple getIconPurple();
	const IconPurpleExtension& getIcons() const {
		return IconPurpleExtension();
	}
	void effect();
	virtual void activation(class De de, class Joueur j);
};

class Monument : private Carte {
public:
	Monument() { type = "Landmark"; };
	const IconMajorAndLandMarkExtension& getIcons() const {
		return IconMajorAndLandMarkExtension();
	}
	void effet();
};



#endif // MACHI_KORO_CARTECOULEUR_H
