
#pragma once
#include "controller/control.h"
#include "./interface.h"
#include "random"
class Ai : public Interface{
    Interface* humanInterface; //pointeur vers l'interface humaine référente
public:
    Ai(Interface* anInterface) : humanInterface(anInterface){};
    ~Ai() = default;

    template<typename t> t getAiChoice(std::vector<t> options,std::vector<t> exceptions={}) const;
    bool confirmationDialog(string message, string firstOption, string secondOption) override;
    string getInputText(vector<string> context) const override;
    size_t getInputNumber(size_t min, size_t max) override;
    EstablishmentCard* selectOneCardOwnedByAnyPlayer(string message) const override;
    Player* selectOnePlayerDifferentFromTheCurrentOne(Player* player) const override;
    EstablishmentCard* selectOneEstablishmentCardFromPlayer(Player* target, string message) const override;
    Monument* selectMonumentCardFromCurrentPlayer(Player* player, string message) const override;

    // never used methods
    void init() const override {return humanInterface->init();};
    void printWelcomingMessage() override{return humanInterface->printWelcomingMessage();};
    void printBasicMessage(string message) override{return humanInterface->printBasicMessage(message);};
    void printError(const std::exception& message) const override {return humanInterface->printError(message);};
    void printTurnCounter(size_t counter) override{return humanInterface->printTurnCounter(counter);};
    void printPlayerInformation(Player* player) const override{return  humanInterface->printPlayerInformation(player);};
    void printMonuments(Player* player) const override{return humanInterface->printMonuments(player);};
    void printCards(Player* player) const override{return humanInterface->printCards(player);};
    void printDices(size_t* throws, size_t nb) const override{return humanInterface->printDices(throws,nb);};
    void printBalances(Player** players) const override{return humanInterface->printBalances(players);};
    void printBoard() const override {return humanInterface->printBoard();};
    string selectOneCard() const override {return humanInterface->selectOneCard();};
    enum Extension chooseExtension() const override {return humanInterface->chooseExtension();};
};



