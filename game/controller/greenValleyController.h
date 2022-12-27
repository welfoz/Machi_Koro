#pragma once
#include "control.h"
#include "../../extensions/Deluxe/greenValleyExtension.h"

class GreenValleyController : public virtual Controller {
protected:
    void turn(Player* player) override;
    void techStartupInvestment(Player* player);
   
public:
    static GreenValleyController& getInstance(Interface* interface = nullptr);
    GreenValleyController(Interface* interface);
   
};
