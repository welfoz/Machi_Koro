#include "marinaController.h"

MarinaController::MarinaController(Interface* interface) : Controller(interface) {
    delete game;
    game = dynamic_cast<Marina*>(new Marina());
};

MarinaController& MarinaController::getInstance(Interface* interface)
{
    if (instance == nullptr)
        instance = new MarinaController(interface);
    return dynamic_cast<MarinaController&>(*instance);
}

void MarinaController::turn(Player* player) {
    if (winner!= nullptr) return;

    proxy->getInterface()->printPlayerInformation(player);
    proxy->getInterface()->printMonuments(player);
    proxy->getInterface()->printCards(player);

    this->proxy->getInterface()->update();

    activateCityHall(player);

    const size_t nb = getNbDiceChosen(*player);

    size_t* throws = getGame()->throwDices(nb);
    proxy->getInterface()->printDices(throws,nb);

    throws = activateRadioTower(player, nb, throws);


    getGame()->setDiceValue(nb,throws);
    getGame()->diceValue= this->activateHarbor(getGame()->diceValue,player);

    getGame()->activation(player, game->diceValue);

    proxy->getInterface()->printBalances(game->players);
    this->proxy->getInterface()->update();

    map<Monument*,bool> playerMonuments = player->getMonuments();
    map<EstablishmentCard*,size_t> playerCards = player->getCards();

    action(player);

    this->proxy->getInterface()->update();

    dynamic_cast<MarinaBoard*>(getGame()->board)->checkNumberOfDecks();

    if (player->getMonuments() == playerMonuments && player->getCards() == playerCards)
        activateAirport(player);

    activateAmusementPark(player, nb, throws);
}


void MarinaController::activateCityHall(Player* player){
    if (Controller::getInstance().getGame()->getBank()->getAccount(player->getId())->getSolde() == 0)
        Controller::getInstance().getGame()->getBank()->credit(player->getId(), 1);
}


size_t MarinaController::activateHarbor(size_t diceValue, Player* player){
    if (diceValue >= 10 && player->getMonument("Harbor") && proxy->getInterface()->confirmationDialog("Do you want to add 2 to the dice value ?","Yes","No")) return diceValue + 2;
    else return diceValue;
}

void MarinaController::activateAirport(Player* player){
    if (player->getMonument("Airport")) Controller::getInstance().getGame()->getBank()->credit(player->getId(), 10);
}

