#include "cardColor.h"
#include "../game/game.h"

// check if the icon name passed belongs to Icons of Game
// check if the icon name passed belongs to the right type
const Icon* Blue::getIconByName(string name) {
	const vector<const Icon*> icons = Game::getInstance().getIcons();
    auto it = find_if(icons.begin(), icons.end(), [&name](const Icon* obj) {return obj->getName() == name && obj->getType() == Type::primaryIndustry; });

	if (it != icons.end()) {
        //found the icon!
        return *it;
    }
    else {
		string error = "error getIconByName, didn't find : " + name + "\n";
		throw error;
    }
};

const Icon* Green::getIconByName(string name) {
	const vector<const Icon*> icons = Game::getInstance().getIcons();
    auto it = find_if(icons.begin(), icons.end(), [&name](const Icon* obj) {return obj->getName() == name && obj->getType() == Type::secondaryIndustry; });
	
	if (it != icons.end()) {
        //found the icon!
        return *it;
    }
    else {
		string error = "error getIconByName, didn't find : " + name + "\n";
		throw error;
    }
};

const Icon* Red::getIconByName(string name) {
	const vector<const Icon*> icons = Game::getInstance().getIcons();
    auto it = find_if(icons.begin(), icons.end(), [&name](const Icon* obj) {return obj->getName() == name && obj->getType() == Type::restaurants; });
	
	if (it != icons.end()) {
        //found the icon!
        return *it;
    }
    else {
		string error = "error getIconByName, didn't find : " + name + "\n";
		throw error;
    }
};

const Icon* Purple::getIconByName(string name) {
	const vector<const Icon*> icons = Game::getInstance().getIcons();
    auto it = find_if(icons.begin(), icons.end(), [&name](const Icon* obj) {return obj->getName() == name && obj->getType() == Type::majorEstablishment; });
	
	if (it != icons.end()) {
        //found the icon!
        return *it;
    }
    else {
		string error = "error getIconByName, didn't find : " + name + "\n";
		throw error;
    }
};

