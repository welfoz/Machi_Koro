#pragma once
#include "control.h"

class GreenValleyController : public Controller {

    void turn(Player* player) override;
public:
    static GreenValleyController& getInstance();
    GreenValleyController();
   
};
