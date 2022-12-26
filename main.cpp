#include <QApplication>
#include "game/machiKoro.h"

int main(int argc, char* argv[]) {

    QApplication app(argc, argv);

    MACHI_KORO::play(Interface::Option::gui);

    return app.exec();
}
