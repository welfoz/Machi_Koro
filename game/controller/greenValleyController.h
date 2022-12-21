#pragma once
#include "control.h"
//#include "marinaController.h"
#include "../../extensions/Deluxe/greenValleyExtension.h"

class GreenValleyController : public virtual Controller {
protected:
    void turn(Player* player) override;
    void techStartupInvestment(Player* player);
   
public:
    static GreenValleyController& getInstance();
    GreenValleyController();
   
};
