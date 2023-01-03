#include "greenValleyController.h"

GreenValleyController::GreenValleyController(Interface* interface) : Controller(interface) {
    delete game;
	game = dynamic_cast<GreenValley*>(new GreenValley);
};

GreenValleyController& GreenValleyController::getInstance(Interface* interface){
    if (instance == nullptr)
        instance = new GreenValleyController(interface);
    return dynamic_cast<GreenValleyController&>(*instance);
}

void GreenValleyController::turn(Player* player) {
    Controller::turn(player);
    techStartupInvestment(player);
}

void GreenValleyController::techStartupInvestment(Player* player) {
    auto *techStartup = dynamic_cast<TechStartup *>(game->getCardByName("Tech Startup"));
    if (techStartup->isAbleToInvest(player) && proxy->getInterface()->confirmationDialog("Do you want to invest on Tech Startup ?", "Yes", "No")) {
		techStartup->invest(player, 1);
    }
}

