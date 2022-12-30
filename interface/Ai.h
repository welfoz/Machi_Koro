#pragma once

#include "./interface.h"
#include "random"
#include "../game/controller/control.h"

class Ai : public Interface{
    Interface* humanInterface; //pointeur vers l'interface humaine référente
public:
    Ai(Interface* anInterface) : humanInterface(anInterface){};
    ~Ai() = default;

    template<typename t> t getAiChoice(std::vector<t> options,std::vector<t> exceptions={}) const;
    bool confirmationDialog(string message, string firstOption, string secondOption)const override;
    string getInputText(vector<string> context) const override;
    size_t getInputNumber(size_t min, size_t max) const override;
    EstablishmentCard* selectOneCardOwnedByAnyPlayer(string message) const override;
    Player* selectOnePlayerDifferentFromTheCurrentOne(Player* player) const override;
    EstablishmentCard* selectOneEstablishmentCardFromPlayer(Player* target, string message) const override;
    Monument* selectMonumentCardFromCurrentPlayer(Player* player, string message) const override;

    // never used methods
    void init() const override {return humanInterface->init();};
    void printWelcomingMessage() const override{return humanInterface->printWelcomingMessage();};
    void printBasicMessage(string message) const override{return humanInterface->printBasicMessage(message);};
    void printError(const std::exception& message) const override {return humanInterface->printError(message);};
    void printTurnCounter(size_t counter) const override{return humanInterface->printTurnCounter(counter);};
    void printPlayerInformation(Player* player) const override{return  humanInterface->printPlayerInformation(player);};
    void printMonuments(Player* player) const override{return humanInterface->printMonuments(player);};
    void printCards(Player* player) const override{return humanInterface->printCards(player);};
    void printDices(size_t* throws, size_t nb) const override{return humanInterface->printDices(throws,nb);};
    void printBalances(Player** players) const override{return humanInterface->printBalances(players);};
    void printBoard() const override {return humanInterface->printBoard();};
    string selectOneCard() const override {return humanInterface->selectOneCard();};
    enum Extension chooseExtension() const override {return humanInterface->chooseExtension();};
};



