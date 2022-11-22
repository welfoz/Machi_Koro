#ifndef MACHI_KORO_CARTE_H
#define MACHI_KORO_CARTE_H
#include <string>
#include "icon.h"


class BaseCard {
protected:
    Type type;
	BaseCard(string name, Type type, size_t price, const Icon* icon): name(name), type(type), price(price), icon(icon) {};
private:
	string name;
	size_t price;
	const Icon* icon;


public:
	void setIcon(const Icon* icon) {
		this->icon = icon;
	}

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
