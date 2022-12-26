#include "deluxeController.h"

DeluxeController::DeluxeController(Interface* interface) :  Controller(interface),
    GreenValleyController(interface),
    MarinaController(interface)
{
    if (interface == nullptr) {
        throw "error";
    }
    delete game;
    game = dynamic_cast<Deluxe*>(new Deluxe());
};

DeluxeController& DeluxeController::getInstance(Interface* interface) {
    if (instance == nullptr)
        instance = new DeluxeController(interface);
    return dynamic_cast<DeluxeController&>(*instance);
}

void DeluxeController::turn(Player* player){
    MarinaController::turn(player);
    techStartupInvestment(player);
}
