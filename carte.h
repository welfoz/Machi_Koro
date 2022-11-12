//
// Created by jules on 12/11/2022.
//

#ifndef MACHI_KORO_CARTE_H
#define MACHI_KORO_CARTE_H
#include <string>
#include "icon.h"

using namespace std;
class Carte {
private:
	string name;
	string type; 
	int* activation_numeros;
	int number_of_numeros;
	int prix;
	Icon icon;

	void setIcon(Icon icone) {
		icon = icone;
	}
	const Icon& getIcon() const {
		return icon;
	}
};

#endif //MACHI_KORO_CARTE_H
