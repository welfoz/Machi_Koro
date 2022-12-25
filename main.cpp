#include <QApplication>
#include "game/machiKoro.h"

int main(int argc, char* argv[]) {

    QApplication app(argc, argv);

    MachiKoro machiKoro;
    machiKoro.play();

    return app.exec();
}
