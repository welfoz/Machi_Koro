#include "marinaExtension.h"
//Blue card

void FlowerGarden::activation(Player &p) {
	Game::getInstance().getBank()->credit(p.getId(), 1);
}

void MackerelBoat::activation(Player &p) {
	if (p.getMonument("harbor")) {
		Game::getInstance().getBank()->credit(p.getId(), 3);
	}
}

/*void FlowerShop::activation(Player& p) {
	for (auto it = p.getCards().begin(); it != p.getCards().end(); it++) {
		if (it->first->getQuantity()
}*/

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

void Publisher::activation(Player &p) {
	for (size_t k = 0; k < Game::getInstance().getNbPlayers(); k++) {
		if (k != p.getId()) {
			Player* p2; 
			p2 = Game::getInstance().getPlayerById(k);  //Methode getPlayerById à créer dans Game
			for (auto it = p2->getCards().begin(); it != p2->getCards().end(); it++) {
				if (it->first->getIcon()->getName() == "cup" || it->first->getIcon()->getName() == "bread") {
					for (size_t i = 0; i < it->second; i++)
						Game::getInstance().getBank()->trade(p.getId(), p2->getId(), 1);
				}
			}
		}
	}
}



