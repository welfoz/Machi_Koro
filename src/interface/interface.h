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
    virtual void init() = 0;
    virtual void printWelcomingMessage() const = 0;
    virtual string getInputText(vector<string> context={}) const = 0;
    virtual bool confirmationDialog(string message, string firstOption, string secondOption)const = 0;
    virtual void printBasicMessage(string message) const= 0;
    virtual void printError(const std::exception& message) const = 0;
    virtual size_t getInputNumber(size_t min=0, size_t max=0)const = 0;
    virtual void printTurnCounter(size_t counter)const = 0;
    virtual void printPlayerInformation(Player* player) const = 0;
    virtual void printMonuments(Player* player) const = 0;
    virtual void printCards(Player* player) const = 0;
    virtual void printDices(size_t* throws, size_t nb)const = 0;
    virtual void printBalances(Player** players) = 0;
    virtual void printBoard() const = 0;
    virtual string selectOneCard() const = 0;
    virtual EstablishmentCard* selectOneCardOwnedByAnyPlayer(string message) const = 0;
    virtual Player* selectOnePlayerDifferentFromTheCurrentOne(Player* player) const = 0;
    virtual EstablishmentCard* selectOneEstablishmentCardFromPlayer(Player* target, string message) const = 0;
    virtual Monument* selectMonumentCardFromCurrentPlayer(Player* player, string message) const = 0;
    virtual enum Extension chooseExtension() const = 0;
};
