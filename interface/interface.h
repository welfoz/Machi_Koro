#pragma once
#include <string>
#include <iostream>
#include "../formatter/formatter.h"
#include "../players/player.h"
#include "../cards/icon.h"
#include "../extensions/Deluxe/PlayerGreenValley.h"
#include <random>
#include "unistd.h"
using namespace std;

class Interface {
protected:
	Interface() = default;

public:
	virtual ~Interface() = default;
	enum Option {cli, gui, cliGreenValley,};
	static Interface* createInterfaceFromOption(Option type);
	virtual void printWelcomingMessage() = 0;
	virtual string getInputText(vector<string> context={}, bool isAi=false) const = 0;
	virtual bool confirmationDialog(string message, string firstOption, string secondOption, bool isAi=false) = 0;
	virtual void printBasicMessage(string message) const = 0;
	virtual void printError(const std::exception& message) const = 0;
	virtual size_t getInputNumber(size_t min, size_t max,bool isAi) = 0;
	virtual void printTurnCounter(size_t counter) = 0;
	virtual void printPlayerInformation(Player* player) const = 0;
	virtual void printMonuments(Player* player) const = 0;
	virtual void printCards(Player* player) const = 0;
	virtual void printDices(size_t* throws, size_t nb)const = 0;
	virtual void printBalances(Player** players) const = 0;
	virtual void printBoard() const = 0;
	virtual string selectOneCard() const = 0;
    virtual EstablishmentCard* selectOneCardOwnedByAnyPlayer(string message,bool isAi) const = 0;
	virtual Player* selectOnePlayerDifferentFromTheCurrentOne(Player* player,bool isAi) const = 0;
	virtual EstablishmentCard* selectOneEstablishmentCardFromPlayer(Player* target, string message,bool isAi) const = 0;
    virtual Monument* selectMonumentCardFromCurrentPlayer(Player* player, string message,bool isAi) const = 0;
    template<typename t> t getAiChoice(std::vector<t> options,std::vector<t> exceptions={}) const;
}; 

class Cli : public Interface {
public:
	Cli() : Interface() {};
	~Cli() {};
	void printWelcomingMessage() override;
	string getInputText(vector<string> context={},bool isAi=false) const override;
	bool confirmationDialog(string message, string firstOption, string secondOption,bool isAi) override;
	void printBasicMessage(string message) const override;
	void printError(const std::exception& message) const override;
	size_t getInputNumber(size_t min, size_t max,bool isAi) override;
	void printTurnCounter(size_t counter) override;
	void printPlayerInformation(Player* player) const override;
	void printMonuments(Player* player) const override;
	void printCards(Player* player) const override;
	void printDices(size_t* throws, size_t nb) const override;
	void printBalances(Player** players) const override;
	void printBoard() const override;
	string selectOneCard() const override;
	Player* selectOnePlayerDifferentFromTheCurrentOne(Player* player,bool isAi) const override;
	EstablishmentCard* selectOneEstablishmentCardFromPlayer(Player* target, string message,bool isAi) const override;
    Monument* selectMonumentCardFromCurrentPlayer(Player* player, string message,bool isAi) const override;
    EstablishmentCard* selectOneCardOwnedByAnyPlayer(string message,bool isAi) const override;
	
};

class Gui : public Interface {
public:
	Gui() : Interface() {};
	~Gui() {};
	void printWelcomingMessage() override {};
	string getInputText(vector<string> context={},bool isAi=false) const override { return ""; };
	bool confirmationDialog(string message, string firstOption, string secondOption,bool isAi) override { return true; };
	void printBasicMessage(string message) const override {};
	void printError(const std::exception& message) const override {};
	size_t getInputNumber(size_t min, size_t max,bool isAi) override { return 0; };
	void printTurnCounter(size_t counter) override {};
	void printPlayerInformation(Player* player) const override {};
	void printMonuments(Player* player) const override {};
	void printCards(Player* player) const override {};
	void printDices(size_t* throws, size_t nb) const override {};
	void printBalances(Player** players) const override {};
	void printBoard() const override {};
	string selectOneCard() const override { return ""; };
	Player* selectOnePlayerDifferentFromTheCurrentOne(Player* player,bool isAi) const override { return player; };

	// WRONG IMPLEMENTATION
	// NEED TO RETURN SOMETHING TO COMPILE
	EstablishmentCard* selectOneEstablishmentCardFromPlayer(Player* target,string message,bool isAi) const override {
		return target->getCards().begin()->first;
	};

	// WRONG IMPLEMENTATION
	// NEED TO RETURN SOMETHING TO COMPILE
	Monument* selectMonumentCardFromCurrentPlayer(Player* player, string message,bool isAi) const override {
		return player->getMonuments().begin()->first;
	};

	EstablishmentCard* selectOneCardOwnedByAnyPlayer(string message,bool isAi) const override;
};

class GreenValleyCli : public Cli {
public:
	void printCards(Player* player) const override;
};
