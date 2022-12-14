#pragma once
#include "../game.h"
#include "../../extensions/Deluxe/greenValleyExtension.h"
#include "../../extensions/Marina/marinaExtension.h"

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

};

class MarinaController : public Controller {

    void turn(Player* player) override;
public:
    static MarinaController& getInstance();
    MarinaController();
   
};


class GreenValleyController : public Controller {

    void turn(Player* player) override;
public:
    static GreenValleyController& getInstance();
    GreenValleyController();
   
};
