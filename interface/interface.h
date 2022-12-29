#pragma once
#include <string>
#include <iostream>
#include "../formatter/formatter.h"
#include "../players/player.h"
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
