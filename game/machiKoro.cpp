#include "./machiKoro.h"

void MACHI_KORO::play() {
    // here to add the code of Pol
    // to choose Cli or Gui
    //    Cli interface;
    Gui interface;
    switch (interface.chooseExtension()) {
    case (Interface::Extension::Base): {
        Controller::getInstance().match();
        break;
    }
    case (Interface::Extension::Marina): {
        MarinaController::getInstance().match();
        break;
    }
    case (Interface::Extension::GreenValley): {
        GreenValleyController::getInstance().match();
        break;
    }
    case (Interface::Extension::Deluxe): {
        DeluxeController::getInstance().match();
        break;
    }
    default:
        throw "error";
        break;
    }
}
