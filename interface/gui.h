#pragma once
#include "./interface.h"

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
