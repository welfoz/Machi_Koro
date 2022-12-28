#include "allCards.h"
#include "../game/controller/control.h"

// Blue card
void WheatField::activation(Player &p) {
    Controller::getInstance().getGame()->getBank()->credit(p.getId(),1);
}
void Ranch::activation(Player &p) {
    Controller::getInstance().getGame()->getBank()->credit(p.getId(),1);
}
void Forest::activation(Player &p) {
    Controller::getInstance().getGame()->getBank()->credit(p.getId(),1);
}
void Mine::activation(Player &p) {
    Controller::getInstance().getGame()->getBank()->credit(p.getId(),5);
}
void AppleOrchard::activation(Player &p) {
    Controller::getInstance().getGame()->getBank()->credit(p.getId(),3);
}
// Green card

void Bakery::activation(Player &p) {
    Controller::getInstance().getGame()->getBank()->credit(p.getId(),1);
}
void ConvenienceStore::activation(Player &p) {
    Controller::getInstance().getGame()->getBank()->credit(p.getId(),3);
}
void CheeseFactory::activation(Player &p) {
    auto cards=p.getCards();
    for (auto it=cards.begin();it!=cards.end();it++){
        if (it->first->getIcon()->getName()=="cow"){
            for (size_t i=0;i<it->second;i++) Controller::getInstance().getGame()->getBank()->credit(p.getId(),3);
        }
    }
}

void FurnitureFactory::activation(Player &p) {
    auto cards=p.getCards();
    for (auto it=cards.begin();it!=cards.end(); it++){
        if (it->first->getIcon()->getName()=="gear"){
            for (size_t i=0;i<it->second;i++) Controller::getInstance().getGame()->getBank()->credit(p.getId(),3);
        }
    }
}

void FruitVegetableMarket::activation(Player &p) {
    auto cards=p.getCards();
    for (auto it=cards.begin();it!=cards.end(); it++){
        if (it->first->getIcon()->getName()=="wheat"){
            for (size_t i=0;i<it->second;i++) Controller::getInstance().getGame()->getBank()->credit(p.getId(),2);
        }
    }
}
// Red cards

void Cafe::activation(Player &p) {
    Controller::getInstance().getGame()->getBank()->trade(p.getId(), Controller::getInstance().getGame()->getIdCurrentPlayer(), 1);
}
void FamilyRestaurant::activation(Player &p) {
    Controller::getInstance().getGame()->getBank()->trade(p.getId(),Controller::getInstance().getGame()->getIdCurrentPlayer(),2);
}
//Purple cards

void Stadium::activation(Player &p) {
    for (size_t k=0;k<Controller::getInstance().getGame()->getNbPlayers();k++){
        if (k!=p.getId()) Controller::getInstance().getGame()->getBank()->trade(p.getId(),k,2);
    }
}
void TVStation::activation(Player &p) {
	Player* p2 = Controller::getInstance().getInterface()->selectOnePlayerDifferentFromTheCurrentOne(&p);
    Controller::getInstance().getGame()->getBank()->trade(p.getId(),p2->getId(),5);
}

void BusinessCenter::activation(Player &p) {
	Player* p2 = Controller::getInstance().getInterface()->selectOnePlayerDifferentFromTheCurrentOne(&p);

    EstablishmentCard* takenCardPtr = Controller::getInstance().getInterface()->selectOneEstablishmentCardFromPlayer(p2, "Which non-major Establishment card do want to take ? (by name)");

    EstablishmentCard* givenCardPtr = Controller::getInstance().getInterface()->selectOneEstablishmentCardFromPlayer(&p, "Which non-major Establishment card do you want to give ? (by name)");

    Controller::getInstance().tradeTwoEstablishmentCards(&p, p2, givenCardPtr, takenCardPtr);
}