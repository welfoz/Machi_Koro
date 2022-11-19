//
// Created by jules on 12/11/2022.
//

#ifndef MACHI_KORO_CARTE_H
#define MACHI_KORO_CARTE_H
#include <string>
#include "icon.h"
#include "joueur.h"

using namespace std;
class Carte {
protected:
    string type;
private:
	string name;
	int* activation_numeros;
	int number_of_numeros;
	int prix;
	Icon icon;

	void setIcon(Icon icone) {
		icon = icone;
	}
public:
	const Icon& getIcon() const {
		return icon;
	}
    const string& getType() const{
        return type;
    }
    bool inActivationNumeros(size_t nombreTire) const;
};

#endif //MACHI_KORO_CARTE_H
