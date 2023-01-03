#pragma once
#include "control.h"
#include "../../extensions/Marina/marinaExtension.h"

class MarinaController : public virtual Controller {
protected:
    void turn(Player* player) override;
    void activateAirport(Player* player);
    size_t activateHarbor(size_t diceValue, Player* player);
    void activateCityHall(Player* player);
public:
    static MarinaController& getInstance(Interface* interface = nullptr);
    MarinaController(Interface* interface);
};

