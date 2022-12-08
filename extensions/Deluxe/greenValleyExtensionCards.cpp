#include "greenValleyExtensionCards.h"

//blue 

void CornField::activation(Player& p) {
	size_t nbActiveMonuments;
	map<Monument*, bool> monuments;
	monuments = Game::getInstance().getPlayer(p.getId()).getMonuments();
	for (auto it = p.getMonuments().begin(); it != p.getMonuments().end(); it++) {
		if (monuments[it->first])
			nbActiveMonuments += 1;
	}
	if (nbActiveMonuments < 2)
		Game::getInstance().getBank()->credit(p.getId(), 1);
}

void Vineyard::activation(Player& p) {
	Game::getInstance().getBank()->credit(p.getId(), 3); 
}

//Green

void GeneralStore::activation(Player& p) {
	size_t nbActiveMonuments;
	map<Monument*, bool> monuments;
	monuments = Game::getInstance().getPlayer(p.getId()).getMonuments();
	for (auto it = p.getMonuments().begin(); it != p.getMonuments().end(); it++) {
		if (monuments[it->first])
			nbActiveMonuments += 1; 
	}
	if (nbActiveMonuments < 2)
		Game::getInstance().getBank()->credit(p.getId(), 2);
}

void LoanOffice::activation(Player& p) {
	Game::getInstance().getBank()->debit(p.getId(), 2);
}

void Winery::activation(Player& p) {
	for (auto it = p.getCards().begin(); it != p.getCards().end(); it++) {
		if (it->first->getName() == "Vineyard") {
			for (size_t i = 0; i < it->second; i++) Game::getInstance().getBank()->credit(p.getId(), 6);
		}
	}
}

void SodaBottlingPlant::activation(Player& p) {
	for (size_t k = 0; k < Game::getInstance().getNbPlayers(); k++) {
		if (k != p.getId()) {
			Player* p2;
			p2 = Game::getInstance().getPlayer(k); 
			for (auto it = p2->getCards().begin(); it != p2->getCards().end(); it++) {
				if (it->first->getIcon() == "cup") {
					for (size_t i = 0; i < it->second; i++) Game::getInstance().getBank()->credit(p.getId(), 1);
				}
			}
		}
	}
}

//Red

void FrenchRestaurnt::activation(Player& p) {
	size_t idCurrentPlayer;
	idCurrentPlayer = Game::getInstance().getIdCurrentPlayer(); 
	size_t nbActiveMonuments;
	map<Monument*, bool> monuments;
	monuments = Game::getInstance().getPlayer(idCurrentPlayer).getMonuments();
	for (auto it = p.getMonuments().begin(); it != p.getMonuments().end(); it++) {
		if (monuments[it->first])
			nbActiveMonuments += 1;
	}
	if (nbActiveMonuments >= 2) {
		Game::getInstance().getBank()->trade(p.getId(), idCurrentPlayer, 5);
	}
}

void MembersOnlyClub::activation(Player& p) {
	size_t idCurrentPlayer;
	idCurrentPlayer = Game::getInstance().getIdCurrentPlayer();
	size_t nbActiveMonuments;
	map<Monument*, bool> monuments;
	monuments = Game::getInstance().getPlayer(idCurrentPlayer).getMonuments();
	for (auto it = p.getMonuments().begin(); it != p.getMonuments().end(); it++) {
		if (monuments[it->first])
			nbActiveMonuments += 1;
	}
	if (nbActiveMonuments >= 3) {
		Game::getInstance().getBank()->trade(p.getId(), idCurrentPlayer, Game::getInstance().getBank()->getAccount(idCurrentPlayer)->getSolde); 
	}
}

void Park::activation(Player& p) {
	size_t totalCoin = 0; 
	size_t playerCoin; 
	size_t nbPlayers = Game::getInstance().getNbPlayers();
	for (size_t k = 0; k < nbPlayers; k++) {
		playerCoin = Game::getInstance().getBank()->getAccount(k)->getSolde();
		totalCoin += playerCoin; 
		Game::getInstance().getBank()->debit(k, playerCoin); 
	}
	totalCoin += (nbPlayers - totalCoin % nbPlayers); 
	for (size_t k = 0; k < nbPlayers; k++) {
		Game::getInstance().getBank()->credit(k, totalCoin / nbPlayers); 
	}
}

