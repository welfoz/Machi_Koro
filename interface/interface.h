#pragma once
#include <string>
#include <iostream>
#include "../formatter/formatter.h"
#include "../players/player.h"
#include "../cards/icon.h"
#include "../extensions/Deluxe/PlayerGreenValley.h"

using namespace std;

class Interface {
protected:
	Interface() = default;

public:
    enum Extension {Marina, GreenValley, Deluxe, Base};
    enum Option {cli, gui, cliGreenValley};
    virtual ~Interface() = default;
    virtual void init() const = 0;
	static Interface* createInterfaceFromOption(Option type);
	virtual void printWelcomingMessage() = 0;
	virtual string getInputText() const = 0;
	virtual bool confirmationDialog(string message, string firstOption, string secondOption) = 0;
	virtual void printBasicMessage(string message) = 0;
	virtual void printError(const std::exception& message) const = 0;
	virtual size_t getInputNumber() = 0;
	virtual void printTurnCounter(size_t counter) = 0;
	virtual void printPlayerInformation(Player* player) const = 0;
	virtual void printMonuments(Player* player) const = 0;
	virtual void printCards(Player* player) const = 0;
	virtual void printDices(size_t* throws, size_t nb)const = 0;
	virtual void printBalances(Player** players) const = 0;
	virtual void printBoard() const = 0;
	virtual string selectOneCard() const = 0;
    virtual EstablishmentCard* selectOneCardOwnedByAnyPlayer(string message) const = 0;
	virtual Player* selectOnePlayerDifferentFromTheCurrentOne(Player* player) const = 0;
	virtual EstablishmentCard* selectOneEstablishmentCardFromPlayer(Player* target, string message) const = 0;
    virtual Monument* selectMonumentCardFromCurrentPlayer(Player* player, string message) const = 0;
    virtual enum Extension chooseExtension() const = 0;
}; 

class Cli : public Interface {
public:
	Cli() : Interface() {};
	~Cli() {};
    void init() const override {};
    void printWelcomingMessage() override;
	string getInputText() const override;
	bool confirmationDialog(string message, string firstOption, string secondOption) override;
	void printBasicMessage(string message) override;
	void printError(const std::exception& message) const override;
	size_t getInputNumber() override;
	void printTurnCounter(size_t counter) override;
	void printPlayerInformation(Player* player) const override;
	void printMonuments(Player* player) const override;
	void printCards(Player* player) const override;
	void printDices(size_t* throws, size_t nb) const override;
	void printBalances(Player** players) const override;
	void printBoard() const override;
	string selectOneCard() const override;
	Player* selectOnePlayerDifferentFromTheCurrentOne(Player* player) const override;
	EstablishmentCard* selectOneEstablishmentCardFromPlayer(Player* target, string message) const override;
    Monument* selectMonumentCardFromCurrentPlayer(Player* player, string message) const override;
    EstablishmentCard* selectOneCardOwnedByAnyPlayer(string message) const override;
    enum Extension chooseExtension() const override;
};

class Gui : public Interface {
public:
	Gui() : Interface() {};
	~Gui() {};
    void init() const override;
    void printWelcomingMessage() override;
    string getInputText() const override;
	bool confirmationDialog(string message, string firstOption, string secondOption) override { return true; };
    void printBasicMessage(string message) override;
	void printError(const std::exception& message) const override {};
	size_t getInputNumber() override { return 0; };
    void printTurnCounter(size_t counter) override;
	void printPlayerInformation(Player* player) const override {};
	void printMonuments(Player* player) const override {};
	void printCards(Player* player) const override {};
	void printDices(size_t* throws, size_t nb) const override {};
	void printBalances(Player** players) const override {};
	void printBoard() const override {};
	string selectOneCard() const override { return ""; };
	Player* selectOnePlayerDifferentFromTheCurrentOne(Player* player) const override { return player; };

	// WRONG IMPLEMENTATION
	// NEED TO RETURN SOMETHING TO COMPILE
	EstablishmentCard* selectOneEstablishmentCardFromPlayer(Player* target,string message) const override {
		return target->getCards().begin()->first;
	};

	// WRONG IMPLEMENTATION
	// NEED TO RETURN SOMETHING TO COMPILE
	Monument* selectMonumentCardFromCurrentPlayer(Player* player, string message) const override {
		return player->getMonuments().begin()->first;
	};

	EstablishmentCard* selectOneCardOwnedByAnyPlayer(string message) const override;
    enum Extension chooseExtension() const override;
};

class GreenValleyCli : public Cli {
public:
	void printCards(Player* player) const override;
};
