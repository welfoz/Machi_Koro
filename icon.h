#ifndef MACHI_KORO_JOUEUR_H
#define MACHI_KORO_JOUEUR_H
#include<string>
using namespace std;

struct Icon {
	string name;
	string image;
};

// Icones de Base
class IconPrimaryIndustry {
public:
	static const Icon wheat;
	static const Icon gear;
	static const Icon cow;
};

class IconSecondaryIndustry {
public:
	static const Icon bread;
	static const Icon factory;
	static const Icon fruit;
};

class IconRestaurants {
public:
	static const Icon cup;
};

class IconPurple{
public:
    static const Icon tower;
};

class IconMajorAndLandMark {
public:
	static const Icon major;
};


// pour les extensions, c'est ici qu'on rajoute de nouvelles icones
class IconPrimaryIndustryExtension : public IconPrimaryIndustry {
};

class IconSecondaryIndustryExtension : public IconSecondaryIndustry {
};

class IconRestaurantExtension : public IconRestaurants {
};

class IconPurpleExtension : public IconPurple{

};

class IconMajorAndLandMarkExtension : public IconMajorAndLandMark {
};

//};
//class Ble : public BlueCarte {
//public: 
//	Ble(): BlueCarte() {
//		BlueCarte::Carte::setIcon(getType().b);
//	}
//};
#endif 
