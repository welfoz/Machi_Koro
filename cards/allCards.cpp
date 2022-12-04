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
    for (auto it=p.getCards().begin();it!=p.getCards().end();it++){
        if (it->first->getIcon()->getName()=="cow"){
            for (size_t i=0;i<it->second;i++) Game::getInstance().getBank()->credit(p.getId(),3);
        }
    }
}

void FurnitureFactory::activation(Player &p) {
    for (auto it=p.getCards().begin();it!=p.getCards().end(); it++){
        if (it->first->getIcon()->getName()=="gear"){
            cout<<"la quantité de cette carte est : "<<it->second<<endl;
            for (size_t i=0;i<it->second;i++) Game::getInstance().getBank()->credit(p.getId(),3);
        }//test
    }
}

void FruitVegetableMarket::activation(Player &p) {
    for (auto it=p.getCards().begin();it!=p.getCards().end(); it++){
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
        cout << "\n------ Player : " << Game::getInstance().getPlayer(j).getUsername()<< " - Money = " << Game::getInstance().getBank()->getAccount(j)->getSolde() << "------\n";
    }
    string name;
    Player* p2;
    bool loop=true;
    while(loop){
        try {
            cout << "\nType the name of the player you want to take 5 coins from :" << endl;
            cin >> name;
            p2 = Game::getInstance().getPlayerByName(name);
            if (p2 != &p) loop = false;
            else cout << "Impossible" << endl;
        } catch (string error) {
            cout << error << endl;
        }
    }
    Game::getInstance().getBank()->trade(p.getId(),p2->getId(),5);
}
void BusinessCenter::activation(Player &p) {
    string name;
    bool loop = true;
    Player *p2;
    while (loop) {
        try {
            cout << "\nType the name of the player you want to trade a card with :" << endl;
            cin >> name;
            p2 = Game::getInstance().getPlayerByName(name);
            if (p2 != &p) loop = false;
            else cout << "Impossible" << endl;
        } catch (string error) {
            cout << error << endl;
        }
    }
    p2->printCards();
    string takenCard;
    EstablishmentCard *takenCardPtr;
    loop = true;
    while (loop) {// we ask the user which card he want to take from that player
        try {
            cout << "Which card do want to take ? (by name)" << endl;
            fflush(stdin);
            getline(cin, takenCard);
            takenCardPtr = Game::getInstance().getCardByName(takenCard);
            if (takenCardPtr->getType() != Type::majorEstablishment) loop = false;
            else cout << "Untradable card" << endl;
        } catch (string &error) {
            cout << error << endl;
        }
    }
    Game::getInstance().getPlayer(p.getId()).printCards();
    string givenCard;
    EstablishmentCard *givenCardPtr;
    loop = true;
    while (loop) { // then we ask the card the user want to give
        try {
            cout << "Which card do you want to give ? (by name)" << endl;
            getline(cin, givenCard);
            givenCardPtr = Game::getInstance().getCardByName(givenCard);
            if (givenCardPtr->getType() != Type::majorEstablishment) loop = false;
            else cout << "Untradable card" << endl;
        } catch (string &error) {
            cout << error << endl;
        }
    }
    Game::getInstance().tradeCards(&p, p2, givenCardPtr, takenCardPtr);
}