#pragma once
#include "control.h"

class MarinaController : public Controller {

    void turn(Player* player) override;
public:
    static MarinaController& getInstance();
    MarinaController();
   
};
