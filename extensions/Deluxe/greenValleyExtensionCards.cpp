#include "greenValleyExtensionCards.h"

void CornField::activation(Player &p) {
    if (p.getNbMonumentsActivated()<2) GreenValley::getInstance().getBank()->credit(p.getId(),1);
}
void Vineyard::activation(Player &p) {
    GreenValley::getInstance().getBank()->credit(p.getId(),3);
}
void GeneralStore::activation(Player &p) {
    if(p.getNbMonumentsActivated()<2) GreenValley::getInstance().getBank()->credit(p.getId(),2);
}
void MovingCompany::activation(Player &p) {
    string name;
    bool loop = true;
    Player *p2= nullptr;
    while (loop) {
        try {
            cout << "\nType the name of the player you want to give a card to :" << endl;
            cin.ignore();
            getline(cin,name);
            p2 = Game::getInstance().getPlayerByName(name);
            if (p2->getId() != *&p.getId()) loop = false;
            else cout << "Impossible" << endl;
        } catch (string error) {
            cout << error << endl;
        }
    }
    p.printCards();
    string givenCard;
    EstablishmentCard *givenCardPtr;
    loop = true;
    while (loop) { // then we ask the card the user want to give
        try {
            cout << "Which non-major Establishment card do you want to give ? (by name)" << endl;
            cin.ignore();
            getline(cin, givenCard);
            givenCardPtr = Game::getInstance().getCardByName(givenCard);
            if (givenCardPtr->getType() != Type::majorEstablishment) loop = false;
            else cout << "Untradable card" << endl;
        } catch (string &error) {
            cout << error << endl;
        }
    }
    p.removeEstablishment(givenCardPtr);
    p2->purchaseEstablishment(givenCardPtr);
    GreenValley::getInstance().getBank()->credit(p.getId(),4);
}

void LoanOffice::activation(Player &p) {
    GreenValley::getInstance().getBank()->debit(p.getId(),2);
}
void Winery::activation(Player &p) {
    auto cards=p.getCards();
    for (auto it : cards){
        if (it.first->getName()=="Vineyard"){
            for (size_t i=0;i<it.second;i++) {
                GreenValley::getInstance().getBank()->credit(p.getId(),6);
                p.close(it.first);
            }
        }
    }
}

void DemolitionCompany::activation(Player &p) {
    if (p.getNbMonumentsActivated()==0) return;
    p.printMonuments();
    string monument;
    Monument*monumentPtr;
    bool loop = true;
    while (loop) {// we ask the user which monument he wants to demolish
        try {
            cout << "Which monument do you want to demolish ? (by name)" << endl;
            cin.ignore();
            getline(cin, monument);
            monumentPtr = Game::getInstance().getMonumentByName(monument);
            if (p.getMonument(monument)) loop = false;
            else cout << "You haven't built this monument" << endl;
        } catch (string &error) {
            cout << error << endl;
        }
    }
    p.removeMonument(monumentPtr);
    GreenValley::getInstance().getBank()->credit(p.getId(),8);
}
void SodaBottlingPlant::activation(Player &p) {
    for (size_t j=0;j<GreenValley::getInstance().getNbPlayers();j++){
        auto cards=GreenValley::getInstance().getPlayer(j).getCards();
        for (auto it : cards) if (it.first->getIcon()->getName()=="cup"){
            for (size_t i=0;i<it.second;i++) GreenValley::getInstance().getBank()->credit(p.getId(),1);
        }
    }
}

void FrenchRestaurant::activation(Player &p) {
    size_t idCurrentPlayer=GreenValley::getInstance().getIdCurrentPlayer();
    if (GreenValley::getInstance().getPlayer(idCurrentPlayer).getNbMonumentsActivated()>=2){
        GreenValley::getInstance().getBank()->trade(p.getId(),idCurrentPlayer,5);
    }
}
void MembersOnlyClub::activation(Player &p) {
    size_t idCurrentPlayer=GreenValley::getInstance().getIdCurrentPlayer();
    if (GreenValley::getInstance().getPlayer(idCurrentPlayer).getNbMonumentsActivated()>=3){
        size_t totalSolde=GreenValley::getInstance().getBank()->getAccount(idCurrentPlayer)->getSolde();
        GreenValley::getInstance().getBank()->trade(p.getId(),idCurrentPlayer,totalSolde);
    }
}
void Park::activation(Player &p) {
    size_t nbPlayers=GreenValley::getInstance().getNbPlayers();
    size_t totalMoney=0;
    for (size_t i=0;i<nbPlayers;i++){
        totalMoney+=GreenValley::getInstance().getBank()->getAccount(i)->getSolde();
    }
    size_t equalShare=ceil(totalMoney/nbPlayers);
    for (size_t i=0;i<nbPlayers;i++){
        size_t solde=GreenValley::getInstance().getBank()->getAccount(i)->getSolde();
        GreenValley::getInstance().getBank()->debit(i,solde);
        GreenValley::getInstance().getBank()->credit(i,equalShare);
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
            closedCardPtr = Game::getInstance().getCardByName(closedCard);
            if (closedCardPtr->getType() != Type::majorEstablishment) loop = false;
            else cout << "Non-renovable establishment" << endl;
        } catch (string &error) {
            cout << error << endl;
        }
    }
    for (size_t i=0; i<GreenValley::getInstance().getNbPlayers();i++){
        Player* iPlayer=&GreenValley::getInstance().getPlayer(i);
        if (iPlayer->getCards().count(closedCardPtr)){
            size_t nbCard=iPlayer->getCards().at(closedCardPtr);
            if (p.getId()!= i) GreenValley::getInstance().getBank()->trade(p.getId(),i,nbCard);
            iPlayer->close(closedCardPtr);
        }
    }
}

void TechStartup::activation(Player &p) {
    if (investments.count(&p)){
        for (size_t i=0;i<GreenValley::getInstance().getNbPlayers();i++){
            if (i!=p.getId()) GreenValley::getInstance().getBank()->trade(p.getId(),i,investments.at(&p));
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
            p.printCards();
            cout << "Which card do you want to activate ? (by name)" << endl;
            cin.ignore();
            getline(cin, card);
            cardPtr = Game::getInstance().getCardByName(card);
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