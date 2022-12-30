#pragma once
#include "./interface.h"
#include "../Qt/viewSet.h"

class Gui : public Interface {
public:
    Gui() : Interface() {};
    ~Gui() {};
    ViewSet* board;
    void init() override;
    void printWelcomingMessage() override;
    string getInputText() const override;
    bool confirmationDialog(string message, string firstOption, string secondOption) override;
    void printBasicMessage(string message) override;
    void printError(const std::exception& message) const override;
    size_t getInputNumber() override;
    void printTurnCounter(size_t counter) override;
    void printPlayerInformation(Player* player) const override {};
    void printMonuments(Player* player) const override {};
    void printCards(Player* player) const override {};
    void printDices(size_t* throws, size_t nb) const override {};
    void printBalances(Player** players) override;
    void printBoard() const override;
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
