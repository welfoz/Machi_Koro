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
    for (auto it=p.getCards().begin();it!=p.getCards().end(); it++){
        if (it->first->getIcon()==it->first->getIconByName("ranch")){
            for (size_t i=0;i<it->second;i++) Game::getInstance().getBank()->credit(p.getId(),3);
        }
    }
}

void FurnitureFactory::activation(Player &p) {
    for (auto it=p.getCards().begin();it!=p.getCards().end(); it++){
        if (it->first->getIcon()==it->first->getIconByName("gear")){
            for (size_t i=0;i<it->second;i++) Game::getInstance().getBank()->credit(p.getId(),3);
        }
    }
}
