//
// Created by jules on 29/12/2022.
//

#include "Ai.h"
size_t Ai::getInputNumber(size_t min, size_t max) {
    vector<size_t> options;
    for (size_t i=min; i<= max;i++) options.push_back(i);
    size_t number;
    number= getAiChoice(options);
    return number;
}

template<typename t>
t Ai::getAiChoice(std::vector<t> options, std::vector<t> exceptions) const {
    if (exceptions.size() > 0)
        for (auto it: exceptions)
            if (count(options.begin(), options.end(), it)) std::remove(options.begin(), options.end(), it);
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, options.size() - 1);
    return options[dist(rng)]; // renvoie un élément situé à un index aléatoire entre le début et la fin du vector
}

bool Ai::confirmationDialog(string message, string firstOption, string secondOption) {
    string stopAnswer="";
    stopAnswer=getAiChoice(vector<string>({firstOption,secondOption}));
    if (Formatter::toLower(stopAnswer) == Formatter::toLower(secondOption)) {
        return false;
    }
    return true;
}

string Ai::getInputText(vector<string> context) const{
    string text="";
    text=getAiChoice(context);
    return text;
}

EstablishmentCard *Ai::selectOneCardOwnedByAnyPlayer(string message) const {
    EstablishmentCard* chosenCardPtr;
    Game* game=Controller::getInstance().getGame();
    vector<EstablishmentCard*> options;
    for (size_t j =0;j<game->getNbPlayers();j++){
        for (auto it : game->getPlayer(j).getCards()) options.push_back(it.first);
    }
    chosenCardPtr= getAiChoice(options);
    return chosenCardPtr;
}

Player *Ai::selectOnePlayerDifferentFromTheCurrentOne(Player *player) const {
    Player *p2;
    Game* game = Controller::getInstance().getGame();
    p2= getAiChoice(game->getPlayers(),vector<Player*> ({player}));
    return p2;
}

EstablishmentCard *Ai::selectOneEstablishmentCardFromPlayer(Player *target, string message) const {
    EstablishmentCard *takenCardPtr;
    vector<EstablishmentCard*> options;
    for (auto it : target->getCards()) if (it.first->getType()!=Type::majorEstablishment) options.push_back(it.first);
    takenCardPtr= getAiChoice(options);
    return takenCardPtr;
}

Monument *Ai::selectMonumentCardFromCurrentPlayer(Player *player, string message) const {
    Monument* monumentPtr;
    vector<Monument*> options;
    for (auto it : player->getMonuments()) if (it.second) options.push_back(it.first);
    monumentPtr= getAiChoice(options);
    return monumentPtr;
}