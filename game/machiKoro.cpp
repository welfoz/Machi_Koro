#include "./machiKoro.h"

void MACHI_KORO::play(Interface::Option option) {
    Interface* interface = nullptr;

    switch (option) {
    case Interface::Option::cli:
        interface = new Cli();
        break;
    case Interface::Option::gui:
        interface = new Gui();
        break;
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
