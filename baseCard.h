#ifndef MACHI_KORO_CARTE_H
#define MACHI_KORO_CARTE_H
#include <string>
#include "icon.h"


class BaseCard {
protected:
    Type type;
private:
	string name;
	size_t price;
	const Icon* icon;

	BaseCard(string name, Type type, size_t price, const Icon* icon): name(name), type(type), price(price), icon(icon) {};

public:
	const Icon* getIcon() const {
		return icon;
	}

    const Type getType() const{
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
