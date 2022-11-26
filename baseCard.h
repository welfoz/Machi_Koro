#pragma once
#include <string>
#include "icon.h"
using namespace std;


class BaseCard {
protected:
    Type type;
	BaseCard(string name, Type type, size_t price, const Icon* icon, string desc): name(name), type(type), price(price), icon(icon), effectDescription(desc) {};
private:
	const string name;
	const size_t price;
	const Icon* icon;
	const string effectDescription;

public:
	void setIcon(const Icon* icon) {
		this->icon = icon;
	}

	const Icon* getIcon() const {
		return icon;
	}


    Type getType() const{
        return type;
    }

	const size_t& getPrice() const {
		return price;
	}

	const string& getName() const {
		return name;
	}

	const string& getEffetDescription() const {
		return this->effectDescription;
	}
};

/*essai*/