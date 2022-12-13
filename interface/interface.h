#pragma once
#include <string>
#include <iostream>
#include "../formatter/formatter.h"
#include "../players/player.h"
#include "../cards/icon.h"

using namespace std;

class Interface {
protected:
	Interface() = default;


public:
	virtual ~Interface() = default;
	enum Option {cli, gui};
	static Interface* createInterfaceFromOption(Option type);
	virtual void printWelcomingMessage() = 0;
	virtual string getInputText() const = 0;
	virtual bool isPlayerWantsToContinue(string message, string firstOption, string secondOption) = 0;
	virtual void printBasicMessage(string message) = 0;
	virtual void printError(const std::exception& message) const = 0;
	virtual size_t getInputNumber() = 0;
	virtual void printTurnCounter(size_t counter) = 0;
	virtual void printPlayerInformation(Player* player) const = 0;
	virtual void printMonuments(Player* player) const = 0;
	virtual void printCards(Player* player) const = 0;
	virtual void printDice(size_t diceNumber, size_t diceValue) const = 0;
	virtual void printBalances(Player** players) const = 0;
	virtual void printBoard() const = 0;
	virtual string selectOneCard() const = 0;
	virtual Player* selectOnePlayerDifferentFromTheCurrentOne(Player* player) const = 0;
	virtual EstablishmentCard* selectOneEstablishmentCardFromPlayer(Player* player, string message) const = 0;
}; 

class Cli : public Interface {
public:
	Cli() : Interface() {};
	~Cli() {};
	void printWelcomingMessage() override;
	string getInputText() const override;
	bool isPlayerWantsToContinue(string message, string firstOption, string secondOption) override;
	void printBasicMessage(string message) override;
	void printError(const std::exception& message) const override;
	size_t getInputNumber() override;
	void printTurnCounter(size_t counter) override;
	void printPlayerInformation(Player* player) const override;
	void printMonuments(Player* player) const override;
	void printCards(Player* player) const override;
	void printDice(size_t diceNumber, size_t diceValue) const override;
	void printBalances(Player** players) const override;
	void printBoard() const override;
	string selectOneCard() const override;
	Player* selectOnePlayerDifferentFromTheCurrentOne(Player* player) const override;
	EstablishmentCard* selectOneEstablishmentCardFromPlayer(Player* player, string message) const override;

	
};

class Gui : public Interface {
public:
	Gui() : Interface() {};
	~Gui() {};
	void printWelcomingMessage() override {};
	string getInputText() const override { return ""; };
	bool isPlayerWantsToContinue(string message, string firstOption, string secondOption) override { return true; };
	void printBasicMessage(string message) override {};
	void printError(const std::exception& message) const override {};
	size_t getInputNumber() override { return 0; };
	void printTurnCounter(size_t counter) override {};
	void printPlayerInformation(Player* player) const override {};
	void printMonuments(Player* player) const override {};
	void printCards(Player* player) const override {};
	void printDice(size_t diceNumber, size_t diceValue) const override {};
	void printBalances(Player** players) const override {};
	void printBoard() const override {};
	string selectOneCard() const override { return ""; };
	Player* selectOnePlayerDifferentFromTheCurrentOne(Player* player) const override { return player; };
	EstablishmentCard* selectOneEstablishmentCardFromPlayer(Player* player, string message) const override { 
		return player->getCards().begin()->first;
	};
};