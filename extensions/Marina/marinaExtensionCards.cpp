#include "marinaExtensionCards.h"
#include "../../game/controller/control.h"
//Blue card

void FlowerGarden::activation(Player &p) {
	Controller::getInstance().getGame()->getBank()->credit(p.getId(), 1);
}

void MackerelBoat::activation(Player &p) {
	if (p.getMonument("harbor")) {
		Controller::getInstance().getGame()->getBank()->credit(p.getId(), 3);
	}
}
 
void TunaBoat::activation(Player& p) {
	size_t diceValue = Controller::getInstance().getGame()->getDiceValue();  //Rajouter getter qui renvoie la valeur des dés tirés ??
	Controller::getInstance().getGame()->getBank()->credit(p.getId(), diceValue);
}

//Green card

void FlowerShop::activation(Player &p) {
	for (auto it = p.getCards().begin(); it != p.getCards().end(); it++) {
		if (it->first->getName() == "Flower Garden") {
			for (size_t i = 0; i < it->second; i++) Controller::getInstance().getGame()->getBank()->credit(p.getId(), 1);
		}
	}
}


void FoodWarehouse::activation(Player &p) {
	for (auto it = p.getCards().begin(); it != p.getCards().end(); it++) {
		if (it->first->getIcon()->getName() == "cup") {
			for (size_t i = 0; i < it->second; i++) Controller::getInstance().getGame()->getBank()->credit(p.getId(), 2);
		}
	}
}

//Red

void SushiBar::activation(Player& p) {
	if (p.getMonument("harbor")) {
		Controller::getInstance().getGame()->getBank()->trade(p.getId(), Controller::getInstance().getGame()->getIdCurrentPlayer(), 3);
	}
}

void PizzaJoint::activation(Player &p) {
	Controller::getInstance().getGame()->getBank()->trade(p.getId(), Controller::getInstance().getGame()->getIdCurrentPlayer(), 1);
}


void HamburgerStand::activation(Player& p) {
	Controller::getInstance().getGame()->getBank()->trade(p.getId(), Controller::getInstance().getGame()->getIdCurrentPlayer(), 1);
}

//Purple

//pas sur à 100%, à tester
void Publisher::activation(Player &p) {
	for (size_t k = 0; k < Controller::getInstance().getGame()->getNbPlayers(); k++) {
		if (k != p.getId()) {
			Player& p2 = Controller::getInstance().getGame()->getPlayer(k);
			for (auto it = p2.getCards().begin(); it != p2.getCards().end(); it++) {
				if (it->first->getIcon()->getName() == "cup" || it->first->getIcon()->getName() == "bread") {
					for (size_t i = 0; i < it->second; i++)
						Controller::getInstance().getGame()->getBank()->trade(p.getId(), p2.getId(), 1);
				}
			}
		}
	}
}

void TaxOffice::activation(Player& p) {
	for (size_t k = 0; k < Controller::getInstance().getGame()->getNbPlayers(); k++) {
		if (k != p.getId()) {
			size_t solde = Controller::getInstance().getGame()->getBank()->getAccount(k)->getSolde();
			if (solde >= 10) {
				Controller::getInstance().getGame()->getBank()->trade(p.getId(), Controller::getInstance().getGame()->getPlayer(k).getId(), solde/2);
			}
		}
	}
}




