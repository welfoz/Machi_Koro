#include "monument.h"
#include "../game/game.h"

const Icon* Monument::getIconByName(string name) {
	const vector< const Icon*> icons = Game::getInstance().getIcons();
    auto it = find_if(icons.begin(), icons.end(), [&name](const Icon* obj) {return obj->getName() == name && obj->getType() == Type::landmark; });
	
	if (it != icons.end()) {
        //found the icon!
        return *it;
    }
    else {
		string error = "error getIconByName, didn't find : " + name + "\n";
		throw error;
    }
};

