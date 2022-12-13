#pragma once
#include <string>
#include <iostream>
#include "../formatter/formatter.h"
#include "../players/player.h"

using namespace std;

class Interface {
protected:
	Interface() = default;


public:
	virtual ~Interface() = default;
	enum Type {cli, gui};
	static Interface* createInterfaceFromOption(Type type);
	virtual void printWelcomingMessage() = 0;
	virtual string getInputText() = 0;
	virtual bool isPlayerWantsToContinue(string message, string firstOption, string secondOption) = 0;
	virtual void printBasicMessage(string message) = 0;
	virtual size_t getInputNumber() = 0;
	virtual void printTurnCounter(size_t counter) = 0;
	virtual void printPlayerInformation(Player* player) const = 0;
	virtual void printMonuments(Player* player) const = 0;
	virtual void printCards(Player* player) const = 0;
	virtual void printDice(size_t diceNumber, size_t diceValue) const = 0;
	virtual void printBalances(Player** players) const = 0;
	virtual void printBoard() const = 0;
}; 

class Cli : public Interface {
public:
	Cli() : Interface() {};
	~Cli() {};
	void printWelcomingMessage() override;
	string getInputText() override;
	bool isPlayerWantsToContinue(string message, string firstOption, string secondOption) override;
	void printBasicMessage(string message) override;
	size_t getInputNumber() override;
	void printTurnCounter(size_t counter) override;
	void printPlayerInformation(Player* player) const override;
	void printMonuments(Player* player) const override;
	void printCards(Player* player) const override;
	void printDice(size_t diceNumber, size_t diceValue) const override;
	void printBalances(Player** players) const override;
	void printBoard() const override;

	
};

class Gui : public Interface {
public:
	Gui() : Interface() {};
	~Gui() {};
	void printWelcomingMessage() override {};
	string getInputText() override { return ""; };
	bool isPlayerWantsToContinue(string message, string firstOption, string secondOption) override { return true; };
	void printBasicMessage(string message) override {};
	size_t getInputNumber() override { return 0; };
	void printTurnCounter(size_t counter) override {};
	void printPlayerInformation(Player* player) const override {};
	void printMonuments(Player* player) const override {};
	void printCards(Player* player) const override {};
	void printDice(size_t diceNumber, size_t diceValue) const override {};
	void printBalances(Player** players) const override {};
	void printBoard() const override {};
};
