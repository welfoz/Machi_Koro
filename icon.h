#ifndef MACHI_KORO_JOUEUR_H
#define MACHI_KORO_JOUEUR_H
#include<string>
using namespace std;

typedef struct Icon {
	string name;
	string image;
}Icon;

// Icones de Base
class IconPrimaryIndustry {
public:
	const Icon wheat  = { "wheat", "wheat.png" };
	const Icon gear = { "gear", "gear.png" };
	const Icon cow = { "cow", "cow.png" };
};

class IconSecondaryIndustry {
public:
	const Icon bread = { "bread", "bread.png" };
	const Icon factory = { "factory", "factory.png" };
	const Icon fruit = { "fruit", "fruit.png" };
};

class IconRestaurants {
public:
	const Icon cup = { "cup", "cup.png" };
};

class IconMajorAndLandMark {
public:
	const Icon major = { "major", "major.png" };
};
#endif 
