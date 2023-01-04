//
// Created by jules on 29/12/2022.
//
#include "Ai.h"

size_t Ai::getInputNumber(size_t min, size_t max)const {
    vector<size_t> options;
    for (size_t i=min; i<= max;i++) options.push_back(i);
    size_t number;
    number= getAiChoice(options);
    printBasicMessage(to_string(number));
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
    delay();
    return options[dist(rng)]; // renvoie un élément situé à un index aléatoire entre le début et la fin du vector
}

bool Ai::confirmationDialog(string message, string firstOption, string secondOption)const{
    printBasicMessage(message);
    string stopAnswer="";
    stopAnswer=getAiChoice(vector<string>({firstOption,secondOption}));
    printBasicMessage(stopAnswer);
    if (Formatter::toLower(stopAnswer) == Formatter::toLower(secondOption)) {
        return false;
    }
    return true;
}

string Ai::getInputText(vector<string> context) const{
    string text="";
    text=getAiChoice(context);
    printBasicMessage(text);
    return text;
}

EstablishmentCard *Ai::selectOneCardOwnedByAnyPlayer(string message) const {
    printBasicMessage(message);
    EstablishmentCard* chosenCardPtr;
    Game* game=Controller::getInstance().getGame();
    vector<EstablishmentCard*> options;
    for (size_t j =0;j<game->getNbPlayers();j++){
        for (auto it : game->getPlayer(j).getCards()) if (it.second) options.push_back(it.first);
    }
    chosenCardPtr= getAiChoice(options);
    printBasicMessage(chosenCardPtr->getName());
    return chosenCardPtr;
}

Player *Ai::selectOnePlayerDifferentFromTheCurrentOne(Player *player) const {
    printBasicMessage("Type the name of the player you want to trade a card with :");
    Player *p2;
    Game* game = Controller::getInstance().getGame();
    p2= getAiChoice(game->getPlayers(),vector<Player*> ({player}));
    printBasicMessage(p2->getUsername());
    return p2;
}

EstablishmentCard *Ai::selectOneEstablishmentCardFromPlayer(Player *target, string message) const {
    printBasicMessage(message);
    EstablishmentCard *takenCardPtr;
    vector<EstablishmentCard*> options;
    for (auto it : target->getCards()) if (it.first->getType()!=Type::majorEstablishment && it.second) options.push_back(it.first);
    takenCardPtr= getAiChoice(options);
    printBasicMessage(takenCardPtr->getName());
    return takenCardPtr;
}

Monument *Ai::selectMonumentCardFromCurrentPlayer(Player *player, string message) const {
    if (player->getNbMonumentsActivated()==0) return nullptr;
    printBasicMessage(message);
    Monument* monumentPtr;
    vector<Monument*> options;
    for (auto it : player->getMonuments()) if (it.second) options.push_back(it.first);
    monumentPtr= getAiChoice(options);
    printBasicMessage(monumentPtr->getName());
    return monumentPtr;
}