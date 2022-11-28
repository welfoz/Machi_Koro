#pragma once
#include "game.h"
#include "cardColor.h"

class Marina: public Game {
public:
	Marina() : Game() {};

	void createEstablishmentCards() override;
	void createMonumentCards() override;
	void createBoard() override;
	void createIcons() override;
	void turn(Player* player) override;
};

class FlowerGarden : public Blue {
public:
	FlowerGarden() : Blue(nullptr, 1, "Flower Garden", 2, "You get 1 coin from the bank, on anyone's turn.", 6) {
		BaseCard::setIcon(getIconByName("boat"));
		size_t* actNumber = new size_t[1];
		actNumber[0] = 4;
		EstablishmentCard::setActivationNumbers(actNumber);
	};
	void activation(Player& p) override {};
};

class MackerelBoat : public Blue {
public:
	MackerelBoat() : Blue(nullptr, 1, "Mackerel Boat", 2, "If you have a Harbor, get 3 coins from the bank on anyone's turn.", 6) {
		BaseCard::setIcon(getIconByName("boat"));
		size_t* actNumber = new size_t[1];
		actNumber[0] = 8;
		EstablishmentCard::setActivationNumbers(actNumber);
	};
	void activation(Player& p) override {};
};

class TunaBoat : public Blue {
public:
	TunaBoat() : Blue(nullptr, 2, "Tuna Boat", 5, "On anyone's Turn: The current player rolls 2 dice. If you have a harbor you get as many coins as the dice total.", 6) {
		BaseCard::setIcon(getIconByName("boat"));
		size_t* actNumber = new size_t[2];
		actNumber[0] = 12;
		actNumber[1] = 14;
		EstablishmentCard::setActivationNumbers(actNumber);
	};
	void activation(Player& p) override {};
};

class FlowerShop : public Green {
public:
	FlowerShop() : Green(nullptr, 1, "Flower Shop", 1, "Get 1 coin from the bank for each Flower Garden you own. (your turn only)", 6) {
		BaseCard::setIcon(getIconByName("bread"));
		size_t* actNumber = new size_t[1];
		actNumber[0] = 6;
		EstablishmentCard::setActivationNumbers(actNumber);
	};
	void activation(Player& p) override {};
};

class FoodWarehouse : public Green {
public:
	FoodWarehouse() : Green(nullptr, 2, "Food Warehouse", 2, "Get 2 coins from the bank for each Cup establishment you own. (your turn only)", 6) {
		BaseCard::setIcon(getIconByName("factory"));
		size_t* actNumber = new size_t[2];
		actNumber[0] = 12;
		actNumber[1] = 13;
		EstablishmentCard::setActivationNumbers(actNumber);
	};
	void activation(Player& p) override {};
};

class SushiBar : public Red{
public:
	SushiBar() : Red(nullptr, 1, "Sushi Bar", 2, "If you have a harbor, you get 3 coins from the player who rolled the dice.", 6) {
		BaseCard::setIcon(getIconByName("cup"));
		size_t* actNumber = new size_t[1];
		actNumber[0] = 1;
		EstablishmentCard::setActivationNumbers(actNumber);
	};
	void activation(Player& p) override {};
};

class PizzaJoint : public Red{
public:
	PizzaJoint() : Red(nullptr, 1, "Pizza Joint", 1, "Get 1 coin from the player who rolled the dice.", 6) {
		BaseCard::setIcon(getIconByName("cup"));
		size_t* actNumber = new size_t[1];
		actNumber[0] = 7;
		EstablishmentCard::setActivationNumbers(actNumber);
	};
	void activation(Player& p) override {};
};

class HamburgerStand : public Red {
public:
	HamburgerStand() : Red(nullptr, 1, "Hamburger Stand", 1, "Take 1 coin from the active player. (your turn only)", 6) {
		BaseCard::setIcon(getIconByName("cup"));
		size_t* actNumber = new size_t[1];
		actNumber[0] = 8;
		EstablishmentCard::setActivationNumbers(actNumber);
	};
	void activation(Player& p) override {};
};

class Publisher : public Purple {
public:
	Publisher() : Purple(nullptr, 1, "Publisher", 7, "Take 1 coin from each opponent for each Cup and Bread establishment they own. (your turn only)", 5) {
		BaseCard::setIcon(getIconByName("major"));
		size_t* actNumber = new size_t[1];
		actNumber[0] = 5;
		EstablishmentCard::setActivationNumbers(actNumber);
	};
	void activation(Player& p) override {};
};


class TaxOffice : public Purple {
public:
	TaxOffice() : Purple(nullptr, 2, "Tax Office", 4, "From each oponont with 10 or more coins: take half their coins, rounded down. This only applies in your turn.", 5) {
		BaseCard::setIcon(getIconByName("major"));
		size_t* actNumber = new size_t[2];
		actNumber[0] = 8;
		actNumber[1] = 9;
		EstablishmentCard::setActivationNumbers(actNumber);
	};
	void activation(Player& p) override {};
};
