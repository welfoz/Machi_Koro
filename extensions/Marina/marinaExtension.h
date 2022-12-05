#ifndef MACHI_KORO_MARINAEXTENSION_H
#define MACHI_KORO_MARINAEXTENSION_H
#include "game.h"
class Marina: public Game {
protected:
    void createEstablishmentCards() override;
    void createMonumentCards() override;
    void createPlayer(string name, size_t id) override;
    void createBoard() override;
    void createIcons() override;
    void turn(Player* player) override;
};




#endif //MACHI_KORO_MARINAEXTENSION_H
