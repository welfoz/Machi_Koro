//
// Created by jules on 29/12/2022.
//

#ifndef MACHI_KORO_AI_H
#define MACHI_KORO_AI_H
#include "interface.h"

class Ai : public Interface{
    template<typename t> t getAiChoice(std::vector<t> options,std::vector<t> exceptions={}) const;
    bool confirmationDialog(string message, string firstOption, string secondOption) override;
    string getInputText(vector<string> context) const override;
    size_t getInputNumber(size_t min, size_t max) override;
    EstablishmentCard* selectOneCardOwnedByAnyPlayer(string message) const override;
    Player* selectOnePlayerDifferentFromTheCurrentOne(Player* player) const override;
    EstablishmentCard* selectOneEstablishmentCardFromPlayer(Player* target, string message) const override;
    Monument* selectMonumentCardFromCurrentPlayer(Player* player, string message) const override;
};


#endif //MACHI_KORO_AI_H
