#include "deluxeExtension.h"


void Deluxe::createBoard(){
    Marina::createBoard();
};
void Deluxe::createIcons(){
    Marina::createIcons();
    GreenValley::createIcons();
    remove_duplicates(icons);
};

void Deluxe::createEstablishmentCards() {
    Marina::createEstablishmentCards();
    GreenValley::createEstablishmentCards();
    remove_duplicates(cards);
}
void Deluxe::createMonumentCards() {
    Marina::createMonumentCards();
    GreenValley::createMonumentCards();
    remove_duplicates(monuments);
}

void Deluxe::createPlayer(string name, size_t id) {
    Marina::createPlayer(name,id);
    players[id]=dynamic_cast<PlayerGreenValley*>(players[id]);
}

template<typename t>
void Deluxe::remove_duplicates(vector<t> vector) {
    auto end = vector.end();
    for (auto it = vector.begin(); it != end; ++it) {
        end = std::remove(it + 1, end, *it);
    }

    vector.erase(end, vector.end());
}
PlayerGreenValley& Deluxe::getPlayer(size_t id) const{
    GreenValley::getPlayer(id);
}
//void Deluxe::turn(Player* player){};