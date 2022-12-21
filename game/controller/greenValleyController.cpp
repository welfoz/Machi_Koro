#include "greenValleyController.h"

GreenValleyController::GreenValleyController() : Controller() {
    delete game;
	game = dynamic_cast<GreenValley*>(new GreenValley);
};

GreenValleyController& GreenValleyController::getInstance()
{
    if (instance == nullptr)
        instance = new GreenValleyController;
    return dynamic_cast<GreenValleyController&>(*instance);
}

void GreenValleyController::turn(Player* player) {
    Controller::turn(player);
}
