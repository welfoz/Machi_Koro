#pragma once

#include "./interface.h"
#include "random"
#include "../game/controller/control.h"
#include <chrono>
#include <thread>
class Ai : public Interface{
    Interface* humanInterface; //pointeur vers l'interface humaine référente
    string toLower(string text) const;
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

    // redirecting to corresponding human interface methods -> usefull when the current player is AI, but the controller needs to use any of these methods
    void init() override {return humanInterface->init();};
    void printWelcomingMessage() const override{return humanInterface->printWelcomingMessage();};
    void printBasicMessage(string message) const override{return humanInterface->printBasicMessage(message);};
    void printError(const std::exception& message) const override {return humanInterface->printError(message);};
    void printTurnCounter(size_t counter) const override{return humanInterface->printTurnCounter(counter);};
    void printPlayerInformation(Player* player) const override{return  humanInterface->printPlayerInformation(player);};
    void printMonuments(Player* player) const override{return humanInterface->printMonuments(player);};
    void printCards(Player* player) const override{return humanInterface->printCards(player);};
    void printDices(size_t* throws, size_t nb) const override{return humanInterface->printDices(throws,nb);};
    void printBalances(Player** players) override {return humanInterface->printBalances(players);};
    void printBoard() const override {return humanInterface->printBoard();};
    string selectOneCard() const override {return humanInterface->selectOneCard();};
    enum Extension chooseExtension() const override {return humanInterface->chooseExtension();};
    void delay() const override{ return humanInterface->delay();}
    void update() const override { return humanInterface->update(); };
//    void update() const override { return humanInterface->update(); };
};



