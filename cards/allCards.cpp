#include "allCards.h"
// Blue card
void WheatField::activation(Player &p) {
    Game::getInstance().getBank()->credit(p.getId(),1);
}
void Ranch::activation(Player &p) {
    Game::getInstance().getBank()->credit(p.getId(),1);
}
void Forest::activation(Player &p) {
    Game::getInstance().getBank()->credit(p.getId(),1);
}
void Mine::activation(Player &p) {
    Game::getInstance().getBank()->credit(p.getId(),5);
}
void AppleOrchard::activation(Player &p) {
    Game::getInstance().getBank()->credit(p.getId(),3);
}
// Green card

void Bakery::activation(Player &p) {
    Game::getInstance().getBank()->credit(p.getId(),1);
}
void ConvenienceStore::activation(Player &p) {
    Game::getInstance().getBank()->credit(p.getId(),3);
}
void CheeseFactory::activation(Player &p) {
    auto cards=p.getCards();
    for (auto it=cards.begin();it!=cards.end();it++){
        if (it->first->getIcon()->getName()=="cow"){
            for (size_t i=0;i<it->second;i++) Game::getInstance().getBank()->credit(p.getId(),3);
        }
    }
}

void FurnitureFactory::activation(Player &p) {
    auto cards=p.getCards();
    for (auto it=cards.begin();it!=cards.end(); it++){
        if (it->first->getIcon()->getName()=="gear"){
            for (size_t i=0;i<it->second;i++) Game::getInstance().getBank()->credit(p.getId(),3);
        }
    }
}

void FruitVegetableMarket::activation(Player &p) {
    auto cards=p.getCards();
    for (auto it=cards.begin();it!=cards.end(); it++){
        if (it->first->getIcon()->getName()=="wheat"){
            for (size_t i=0;i<it->second;i++) Game::getInstance().getBank()->credit(p.getId(),2);
        }
    }
}
// Red cards

void Cafe::activation(Player &p) {
    Game::getInstance().getBank()->trade(p.getId(),Game::getInstance().getIdCurrentPlayer(),1);
}
void FamilyRestaurant::activation(Player &p) {
    Game::getInstance().getBank()->trade(p.getId(),Game::getInstance().getIdCurrentPlayer(),2);
}
//Purple cards

void Stadium::activation(Player &p) {
    for (size_t k=0;k<Game::getInstance().getNbPlayers();k++){
        if (k!=p.getId()) Game::getInstance().getBank()->trade(p.getId(),k,2);
    }
}
void TVStation::activation(Player &p) {
    for (size_t j=0;j<Game::getInstance().getNbPlayers();j++){
        Game::getInstance().getInterface()->printPlayerInformation(&Game::getInstance().getPlayer(j));
    }

	Player* p2 = Game::getInstance().getInterface()->selectOnePlayerDifferentFromTheCurrentOne(&p);
    Game::getInstance().getBank()->trade(p.getId(),p2->getId(),5);
}

void BusinessCenter::activation(Player &p) {
	Player* p2 = Game::getInstance().getInterface()->selectOnePlayerDifferentFromTheCurrentOne(&p);

    Game::getInstance().getInterface()->printCards(p2);
    EstablishmentCard* takenCardPtr = Game::getInstance().getInterface()->selectOneEstablishmentCardFromPlayer(p2, "Which non-major Establishment card do want to take ? (by name)" );

    Game::getInstance().getInterface()->printCards(&p);
    EstablishmentCard* givenCardPtr = Game::getInstance().getInterface()->selectOneEstablishmentCardFromPlayer(&p, "Which non-major Establishment card do you want to give ? (by name)" );

    Game::getInstance().tradeCards(&p, p2, givenCardPtr, takenCardPtr);
}