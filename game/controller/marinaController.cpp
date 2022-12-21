#include "marinaController.h"

MarinaController::MarinaController() : Controller() {
    delete game;
	game = dynamic_cast<Marina*>(new Marina);
};

MarinaController& MarinaController::getInstance()
{
    if (instance == nullptr)
        instance = new MarinaController;
    return dynamic_cast<MarinaController&>(*instance);
}

void MarinaController::turn(Player* player) {
    Controller::turn(player);
}
