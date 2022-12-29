#pragma once
#include "./interface.h"

class Cli : public Interface {
public:
    Cli() : Interface() {};
    ~Cli() {};
    void init() const override {};
    void printWelcomingMessage() override;
    string getInputText(vector<string> context={}) const override;
    bool confirmationDialog(string message, string firstOption, string secondOption) override;
    void printBasicMessage(string message) override;
    void printError(const std::exception& message) const override;
    size_t getInputNumber(size_t min=0,size_t max=0) override;
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

class GreenValleyCli : public Cli {
public:
    void printCards(Player* player) const override;
};
