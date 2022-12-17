#include "greenValleyExtensionCards.h"
#include "../../game/controller/control.h"

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
    // interface.selectPlayerToGiveHimAEstablishementCard(Player& currentPlayer)
    string name;
    bool loop = true;
    Player *p2= nullptr;
    while (loop) {
        try {
            cout << "\nType the name of the player you want to give a card to :" << endl;
            cin.ignore();
            getline(cin,name);
            p2 = Controller::getInstance().getGame()->getPlayerByName(name);
            if (p2->getId() != *&p.getId()) loop = false;
            else cout << "Impossible" << endl;
        } catch (string error) {
            cout << error << endl;
        }
    }
    // interface.selectEstablishementCard(Player& p)
    Controller::getInstance().getInterface()->printCards(&p);
    string givenCard;
    EstablishmentCard *givenCardPtr;
    loop = true;
    while (loop) { // then we ask the card the user want to give
        try {
            cout << "Which non-major Establishment card do you want to give ? (by name)" << endl;
            cin.ignore();
            getline(cin, givenCard);
            givenCardPtr = Controller::getInstance().getGame()->getCardByName(givenCard);
            if (givenCardPtr->getType() != Type::majorEstablishment) loop = false;
            else cout << "Untradable card" << endl;
        } catch (string &error) {
            cout << error << endl;
        }
    }
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
    if (p.getNbMonumentsActivated()==0) return;
    Controller::getInstance().getInterface()->printMonuments(&p);
    string monument;
    Monument*monumentPtr;
    bool loop = true;
    while (loop) {// we ask the user which monument he wants to demolish
        try {
            cout << "Which monument do you want to demolish ? (by name)" << endl;
            cin.ignore();
            getline(cin, monument);
            monumentPtr = Controller::getInstance().getGame()->getMonumentByName(monument);
            if (p.getMonument(monument)) loop = false;
            else cout << "You haven't built this monument" << endl;
        } catch (string &error) {
            cout << error << endl;
        }
    }
    p.removeMonument(monumentPtr);
    Controller::getInstance().getGame()->getBank()->credit(p.getId(),8);
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
    string closedCard;
    EstablishmentCard *closedCardPtr;
    bool loop = true;
    while (loop) { // then we ask the card the user want to give
        try {
            //print all cards owned by all players
            cout << "Which non-major Establishment card do you want to renovate ? (by name)" << endl;
            cin.ignore();
            getline(cin, closedCard);
            closedCardPtr = Controller::getInstance().getGame()->getCardByName(closedCard);
            if (closedCardPtr->getType() != Type::majorEstablishment) loop = false;
            else cout << "Non-renovable establishment" << endl;
        } catch (string &error) {
            cout << error << endl;
        }
    }
    for (size_t i=0; i<Controller::getInstance().getGame()->getNbPlayers();i++){
        //PlayerGreenValley* iPlayer= &Controller::getInstance().getGame()->getPlayer(i);
        //if (iPlayer->getCards().count(closedCardPtr)){
        //    size_t nbCard=iPlayer->getCards().at(closedCardPtr);
        //    if (p.getId()!= i) Controller::getInstance().getGame()->getBank()->trade(p.getId(),i,nbCard);
        //    iPlayer->close(closedCardPtr);
        //}
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
    bool stop =false;
    string choice;
    while (!stop){
        cout<<"Do you want to activate another of your non-major establishments ? (Y/N)"<<endl;
        cin>>choice;
        if (choice=="Y" || choice=="y") stop=true;
        if (choice=="n" || choice =="Y") {
            stop = true; return;
        }
        choice="";
    }
    string card;
    EstablishmentCard *cardPtr;
    bool loop = true;
    while (loop) { // then we ask the card the user want to give
        try {
            Controller::getInstance().getInterface()->printCards(&p);
            cout << "Which card do you want to activate ? (by name)" << endl;
            cin.ignore();
            getline(cin, card);
            cardPtr = Controller::getInstance().getGame()->getCardByName(card);
            if (cardPtr->getType() != Type::majorEstablishment && cardPtr->getType() != Type::restaurants ) loop = false;
            else cout << "Select another establishment" << endl;
        } catch (string &error) {
            cout << error << endl;
        }
    }
    cardPtr->activation(p);
    p.removeEstablishment(this);
    cout<<"\n"<<cardPtr->getName()<<" returned to the market.\n";
}