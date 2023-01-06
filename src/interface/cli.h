#pragma once
#include "./interface.h"
#include "../game/game.h"
#include "../game/controller/control.h"

class Cli : public Interface {
protected:
	string format(string text, unsigned int maxLenght) const ;
	string formatHeader(vector<pair<string, unsigned int>> texts) const;
	string toLower(string text) const;
public:
    Cli() : Interface() {};
    ~Cli() {};
    void init() override {};
    void printWelcomingMessage() const override;
    string getInputText(vector<string> context={}) const override;
    bool confirmationDialog(string message, string firstOption, string secondOption) const override;
    void printBasicMessage(string message) const override;
    void printError(const std::exception& message) const override;
    size_t getInputNumber(size_t min=0,size_t max=0) const override;
    void printTurnCounter(size_t counter) const override;
    void printPlayerInformation(Player* player) const override;
    void printMonuments(Player* player) const override;
    void printCards(Player* player) const override;
    void printDices(size_t* throws, size_t nb) const override;
    void printBalances(Player** players) override;
    void printBoard() const override;
    string selectOneCard() const override;
    Player* selectOnePlayerDifferentFromTheCurrentOne(Player* player) const override;
    EstablishmentCard* selectOneEstablishmentCardFromPlayer(Player* target, string message) const override;
    Monument* selectMonumentCardFromCurrentPlayer(Player* player, string message) const override;
    EstablishmentCard* selectOneCardOwnedByAnyPlayer(string message) const override;
    enum Extension chooseExtension() const override;
    void delay() const;
    void update() const override {};
};

class GreenValleyCli : public Cli {
public:
    void printCards(Player* player) const override;
};
