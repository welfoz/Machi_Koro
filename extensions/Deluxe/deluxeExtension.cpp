#include "deluxeExtension.h"


void Deluxe::createBoard(){
    Marina::createBoard();
};
void Deluxe::createIcons(){
    Marina::createIcons();
    GreenValley::createIcons();
    removeDuplicates(icons);
};

void Deluxe::createEstablishmentCards() {
    Marina::createEstablishmentCards();
    GreenValley::createEstablishmentCards();
    removeDuplicates(cards);

}
void Deluxe::createMonumentCards() {
    Marina::createMonumentCards();
}

void Deluxe::createPlayer(string name, size_t id) {
    GreenValley::createPlayer(name,id);
    players[id]->purchaseMonument(getMonumentByName("City Hall"));
}

PlayerGreenValley& Deluxe::getPlayer(size_t id) const{
    GreenValley::getPlayer(id);
}

template<typename t>
void Deluxe::removeDuplicates(vector<t>& vtr) {
    for (auto it = vtr.begin(); it != vtr.end(); it++) {
        for (auto it2= next(it,1);it2!=vtr.end();it2++){
            if (**it==**it2){
                auto old=*it2;
                vtr.erase(it2);
                delete old;
            }
        }
    }
}
