#include "marinaExtensionCards.h"
//Blue card

void FlowerGarden::activation(Player &p) {
	Game::getInstance().getBank()->credit(p.getId(), 1);
}

void MackerelBoat::activation(Player &p) {
	if (p.getMonument("harbor")) {
		Game::getInstance().getBank()->credit(p.getId(), 3);
	}
}
 
void TunaBoat::activation(Player& p) {
	size_t diceValue = Game::getInstance().getDiceValue();  //Rajouter getter qui renvoie la valeur des dés tirés ??
	Game::getInstance().getBank()->credit(p.getId(), diceValue);
}

//Green card

void FlowerShop::activation(Player &p) {
	for (auto it = p.getCards().begin(); it != p.getCards().end(); it++) {
		if (it->first->getName() == "Flower Garden") {
			for (size_t i = 0; i < it->second; i++) Game::getInstance().getBank()->credit(p.getId(), 1);
		}
	}
}


void FoodWarehouse::activation(Player &p) {
	for (auto it = p.getCards().begin(); it != p.getCards().end(); it++) {
		if (it->first->getIcon()->getName() == "cup") {
			for (size_t i = 0; i < it->second; i++) Game::getInstance().getBank()->credit(p.getId(), 2);
		}
	}
}

//Red

void SushiBar::activation(Player& p) {
	if (p.getMonument("harbor")) {
		Game::getInstance().getBank()->trade(p.getId(), Game::getInstance().getIdCurrentPlayer(), 3);
	}
}

void PizzaJoint::activation(Player &p) {
	Game::getInstance().getBank()->trade(p.getId(), Game::getInstance().getIdCurrentPlayer(), 1);
}


void HamburgerStand::activation(Player& p) {
	Game::getInstance().getBank()->trade(p.getId(), Game::getInstance().getIdCurrentPlayer(), 1);
}

//Purple

//pas sur à 100%, à tester
void Publisher::activation(Player &p) {
	for (size_t k = 0; k < Game::getInstance().getNbPlayers(); k++) {
		if (k != p.getId()) {
			Player* p2; 
			p2 = Game::getInstance().getPlayer(k);
			for (auto it = p2->getCards().begin(); it != p2->getCards().end(); it++) {
				if (it->first->getIcon()->getName() == "cup" || it->first->getIcon()->getName() == "bread") {
					for (size_t i = 0; i < it->second; i++)
						Game::getInstance().getBank()->trade(p.getId(), p2->getId(), 1);
				}
			}
		}
	}
}

void TaxOffice::activation(Player& p) {
	for (size_t k = 0; k < Game::getInstance().getNbPlayers(); k++) {
		Player* p2; 
		if (k != p.getId()) {
			size_t account = Game::getInstance().getBank()->getAccount(k);
			if (account >= 10) {
				p2 = Game::getInstance().getPlayer(k); 
				Game::getInstance().getBank()->trade(p.getId(), p2->getId(), account/2);
			}
		}
	}
}




