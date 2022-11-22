#ifndef MACHI_KORO_CARTE_H
#define MACHI_KORO_CARTE_H
#include <string>
#include "icon.h"


class BaseCard {
protected:
    string type;
private:
	string name;
	size_t price;
	Icon icon;

	BaseCard(string name, string type, size_t price, Icon icon): name(name), type(type), price(price), icon(icon) {};

public:
	const Icon& getIcon() const {
		return icon;
	}

    const string& getType() const{
        return type;
    }

	const size_t& getPrice() const {
		return price;
	}

	const string& getName() const {
		return name;
	}
};

#endif //MACHI_KORO_CARTE_H
