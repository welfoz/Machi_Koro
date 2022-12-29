
#include "game/controller/deluxeController.h"
#include "game/controller/greenValleyController.h"
#include "game/controller/marinaController.h"
#include "game/controller/control.h"
#include "interface/cli.h"

// comment to play in cli
//#include <QApplication>
#include "interface/gui.h"

namespace MACHI_KORO {

void play(Interface::Option option) {
    Interface* interface = nullptr;

    switch (option) {
    case Interface::Option::cli:
        interface = new Cli();
        break;
   /* case Interface::Option::gui:
        // comment to play in cli
        interface = new Gui();
        break;*/
    case Interface::Option::cliGreenValley:
        interface = new GreenValleyCli();
        break;
    default:
        throw "sa mere";
        break;
    }

    switch (interface->chooseExtension()) {
    case (Interface::Extension::Base): {
        Controller::getInstance(interface).match();
        break;
    }
    case (Interface::Extension::Marina): {
        MarinaController::getInstance(interface).match();
        break;
    }
    case (Interface::Extension::GreenValley): {
        GreenValleyController::getInstance(interface).match();
        break;
    }
    case (Interface::Extension::Deluxe): {
        DeluxeController::getInstance(interface).match();
        break;
    }
    default:
        throw "error";
        break;
    }
    delete interface;
}

}

// to play in CLI
//int main(int argc, char* argv[]) {

//    MACHI_KORO::play(Interface::Option::cli);

//    return 0;
//}

// to play in GUI
int main(int argc, char* argv[]) {

    //QApplication app(argc, argv);

    MACHI_KORO::play(Interface::Option::cli);

    //return app.exec();
}
