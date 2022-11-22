#include "baseCard.h"
#include "string"

using namespace std;

class Monument: public BaseCard {
	bool active;
public:
	Monument(string name, size_t price): BaseCard(name, Type::landmark, price, nullptr) {
		setIcon(getIcon("landmark"));
	};

	const bool isActivated() {
		return active;
	}

	//check if the type of the icon is the same than the card type 
	// raise error if not
	const Icon* getIcon(string name);
};
