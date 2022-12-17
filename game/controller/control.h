#pragma once
//#include "../game.h"
//#include "../../extensions/Deluxe/greenValleyExtension.h"
//#include "../../extensions/Marina/marinaExtension.h"
#include "../extensions/Deluxe/deluxeExtension.h"
class Controller {
protected:
    Game* game;
    static Controller* instance;
    Interface* const interface;
    static void freeInstance();
    virtual void turn(Player* player);
    virtual void createAll();
    Controller(Interface::Option type = Interface::Option::cli);
    const size_t getNbDiceChosen(Player& p);
    virtual void action(Player* player);
	size_t* activateRadioTower(Player* player, size_t nb, size_t* throws) const;
	void activateAmusementPark(Player* p, size_t nb, size_t* throws);

public:
    virtual ~Controller();

    static Controller& getInstance();
    Interface* const getInterface() const {
        return interface;
    }

    void match();
    Game* getGame() {
        return game;
    }

    void tradeTwoEstablishmentCards(Player* p1, Player* p2, EstablishmentCard* card1, EstablishmentCard* card2);
};

class MarinaController : public virtual Controller {
protected:
    void turn(Player* player) override;
    void activateAirport(Player* player);
    size_t activateHarbor(size_t diceValue, Player* player);
    void activateCityHall(Player* player);
public:
    static MarinaController& getInstance();
    MarinaController();
   
};


class GreenValleyController : public virtual Controller {
protected:
    void turn(Player* player) override;
    void techStartupInvestment(Player* player);
    void hasBoughtLoanOffice(Player* player);
public:
    static GreenValleyController& getInstance();
    GreenValleyController();
   
};
class DeluxeController : public GreenValleyController, public MarinaController{
    void turn(Player* player) override;
public:
    static DeluxeController& getInstance();
    DeluxeController();
};