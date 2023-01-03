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

void Deluxe::createPlayer(string name, size_t id, bool isAi) {
    GreenValley::createPlayer(name,id,isAi);
    players[id]->purchaseMonument(getMonumentByName("City Hall"));
}

PlayerGreenValley& Deluxe::getPlayer(size_t id) const{
    return GreenValley::getPlayer(id);
}

template<typename t>
void Deluxe::removeDuplicates(vector<t>& vtr) {
    vector<t> duplicates;

    for (auto it = vtr.begin(); it != vtr.end(); it++) {
        for (auto it2= next(it,1);it2!=vtr.end();it2++){
            if (**it==**it2){
                duplicates.push_back(*it2);
            }
        }
    }

    for (auto it = duplicates.begin(); it != duplicates.end(); it++) {
        auto itDuplicate = std::find(vtr.begin(), vtr.end(), *it);
        if (itDuplicate != vtr.end()) {
            vtr.erase(itDuplicate);
        }
    }

}
