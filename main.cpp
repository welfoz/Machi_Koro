#include <QApplication>
#include "viewCard.h"
#include "viewSet.h"
#include "viewMonument.h"
#include "viewDice.h"
#include "game/game.h"
//#include "C:\Users\lemer\Documents\UTC\GI01\LO21\Projet\Projet Git\Machi_Koro\game\game.h"
//#include "C:\Users\lemer\Documents\UTC\GI01\LO21\Projet\Projet Git\Qt\Machi_Koro\players\player.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    ViewCard card;
    ViewDice dice;
    ViewSet set;
    Game::getInstance();
    ViewMonument monument;
    set.printCarte();
    set.show();
    //card.paintCard();
    //card.show();
    /*ViewMonument monument;
    monument.paintMonument();
    monument.show();*/
    return app.exec();
}
