#ifdef MACHI_KORO_CARTECOULEUR_H
#define MACHI_KORO_CARTECOULEUR_H
#include "Carte.h"
#include "Joueur.h"
#include "De.h"

class Bleu : private Carte {
private:
public:
	Bleue() { type = "Primary Industrie"; };
	IconBlue getIconBlue();
	virtual void effet() = 0; 
	//méthode qui sera défini dans toutes autres cartes
	void activation(class De de); 
	//verifie si le dé tiré est égale à l'activation des nums de la carte
};

class Vert : private Carte {
private:
public:
	Vert() { type = "Secondary Industrie"; };
	IconGreen getIconGreen();
	virtual void effet() = 0;
	void activation(class De de, class Joueur j);
	//verifie si le dé tiré par le joueur est égale à l'activation des nums de la carte
};

class Rouge : private Carte {
private:
public:
	Rouge() { type = "Restaurant"; };
	IconRed getIconRed();
	virtual void effet() = 0;
	void activation(class De de);
};

class Violet : private Carte {
private:
public:
	Violet() { type = "Major Establishment"; };
	IconPurple getIconPurple();
	virtual void effet() = 0;
	void activation(class De de, class Joueur j);
};

class Monument : private Carte {
private:
public:
	Monument() { type = "Landmark"; };
	IconLandmark getIconLandmark();
	virtual void effet() = 0;
};



#endif // MACHI_KORO_CARTECOULEUR_H
