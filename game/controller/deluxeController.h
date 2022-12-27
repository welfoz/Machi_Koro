#pragma once
#include "control.h"
#include "../../extensions/Deluxe/deluxeExtension.h"
#include "greenValleyController.h"
#include "marinaController.h"

class DeluxeController : public GreenValleyController, public MarinaController {
    void turn(Player* player) override;
public:
    static DeluxeController& getInstance(Interface* interface = nullptr);
    DeluxeController(Interface* interface);
};
