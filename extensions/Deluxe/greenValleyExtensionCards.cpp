#include "greenValleyExtensionCards.h"
//#include "../../game/controller/control.h"

void CornField::activation(Player &p) {
    if (p.getNbMonumentsActivated()<2) Controller::getInstance().getGame()->getBank()->credit(p.getId(),1);
}
void Vineyard::activation(Player &p) {
    Controller::getInstance().getGame()->getBank()->credit(p.getId(),3);
}
void GeneralStore::activation(Player &p) {
    if(p.getNbMonumentsActivated()<2) Controller::getInstance().getGame()->getBank()->credit(p.getId(),2);
}
void MovingCompany::activation(Player &p) {
    auto p2=Controller::getInstance().getInterface()->selectOnePlayerDifferentFromTheCurrentOne(&p);
    auto givenCardPtr=Controller::getInstance().getInterface()->selectOneEstablishmentCardFromPlayer(&p,"Which card do you want to give to "+p2->getUsername());
    p.removeEstablishment(givenCardPtr);
    p2->purchaseEstablishment(givenCardPtr);
    Controller::getInstance().getGame()->getBank()->credit(p.getId(),4);
}

void LoanOffice::activation(Player &p) {
    Controller::getInstance().getGame()->getBank()->debit(p.getId(),2);
}
void Winery::activation(Player &p) {
    PlayerGreenValley *playerGreenValley=dynamic_cast<PlayerGreenValley*>(&p);
    auto cards=p.getCards();
    for (auto it : cards){
        if (it.first->getName()=="Vineyard"){
            for (size_t i=0;i<it.second;i++) {
                Controller::getInstance().getGame()->getBank()->credit(p.getId(),6);
                playerGreenValley->close(it.first);
            }
        }
    }
}

void DemolitionCompany::activation(Player &p) {
    auto monumentPtr= Controller::getInstance().getInterface()->selectMonumentCardFromCurrentPlayer(&p,"Which monument do you want to demolish ?");
    if (monumentPtr!= nullptr) {
        p.removeMonument(monumentPtr);
        Controller::getInstance().getGame()->getBank()->credit(p.getId(),8);
    }
}
void SodaBottlingPlant::activation(Player &p) {
    for (size_t j=0;j<Controller::getInstance().getGame()->getNbPlayers();j++){
        auto cards=Controller::getInstance().getGame()->getPlayer(j).getCards();
        for (auto it : cards) if (it.first->getIcon()->getName()=="cup"){
            for (size_t i=0;i<it.second;i++) Controller::getInstance().getGame()->getBank()->credit(p.getId(),1);
        }
    }
}

void FrenchRestaurant::activation(Player &p) {
    size_t idCurrentPlayer=Controller::getInstance().getGame()->getIdCurrentPlayer();
    if (Controller::getInstance().getGame()->getPlayer(idCurrentPlayer).getNbMonumentsActivated()>=2){
        Controller::getInstance().getGame()->getBank()->trade(p.getId(),idCurrentPlayer,5);
    }
}
void MembersOnlyClub::activation(Player &p) {
    size_t idCurrentPlayer=Controller::getInstance().getGame()->getIdCurrentPlayer();
    if (Controller::getInstance().getGame()->getPlayer(idCurrentPlayer).getNbMonumentsActivated()>=3){
        size_t totalSolde=Controller::getInstance().getGame()->getBank()->getAccount(idCurrentPlayer)->getSolde();
        Controller::getInstance().getGame()->getBank()->trade(p.getId(),idCurrentPlayer,totalSolde);
    }
}
void Park::activation(Player &p) {
    size_t nbPlayers=Controller::getInstance().getGame()->getNbPlayers();
    size_t totalMoney=0;
    for (size_t i=0;i<nbPlayers;i++){
        totalMoney+=Controller::getInstance().getGame()->getBank()->getAccount(i)->getSolde();
    }
    size_t equalShare=ceil(totalMoney/nbPlayers);
    for (size_t i=0;i<nbPlayers;i++){
        size_t solde=Controller::getInstance().getGame()->getBank()->getAccount(i)->getSolde();
        Controller::getInstance().getGame()->getBank()->debit(i,solde);
        Controller::getInstance().getGame()->getBank()->credit(i,equalShare);
    }
}
void RenovationCompany::activation(Player &p) {
    auto renovatedCardPtr=Controller::getInstance().getInterface()->selectOneCardOwnedByAnyPlayer("Which non-major establishment do you want to renovate ?");
    for (size_t i=0; i<Controller::getInstance().getGame()->getNbPlayers();i++){
        PlayerGreenValley* iPlayer=dynamic_cast<PlayerGreenValley*> (&Controller::getInstance().getGame()->getPlayer(i));
        if (iPlayer->getCards().count(renovatedCardPtr)){
            size_t nbCard=iPlayer->getCards().at(renovatedCardPtr);
            if (p.getId()!= i) Controller::getInstance().getGame()->getBank()->trade(p.getId(),i,nbCard);
            iPlayer->close(renovatedCardPtr);
        }
    }
}

void TechStartup::invest(Player* player, size_t amount) {
	if (player->getCards().count(this) && Controller::getInstance().getGame()->getBank()->getAccount(player->getId())->getSolde() >= 1 && Controller::getInstance().getInterface()->confirmationDialog("Do you want to invest on Tech Startup ?", "Yes", "No")) {
		investments[player]++;
		Controller::getInstance().getGame()->getBank()->debit(player->getId(), 1);
	}
}

void TechStartup::activation(Player &p) {
    if (investments.count(&p)){
        for (size_t i=0;i<Controller::getInstance().getGame()->getNbPlayers();i++){
            if (i!=p.getId()) Controller::getInstance().getGame()->getBank()->trade(p.getId(),i,investments.at(&p));
        }
    }
}

void InternationalExhibitHall::activation(Player &p) {
    if (Controller::getInstance().getInterface()->confirmationDialog("Do you want to activate another of your non-Major establishment card ?","Yes","No")){
        auto cardPtr= Controller::getInstance().getInterface()->selectOneEstablishmentCardFromPlayer(&p,"Which non-Major establishment card do you want to activate ?");
        cardPtr->activation(p);
        p.removeEstablishment(this);
        Controller::getInstance().getInterface()->printBasicMessage(cardPtr->getName() + " returned to the market.");
    }

}