#pragma once
#include "../../game/game.h"
#include "Proxy.h"

class Controller {
protected:
    Game* game;
    static Controller* instance;
    Proxy* proxy;
    static void freeInstance();
    virtual void turn(Player* player);
    virtual void createAll();
    Controller(Interface* interface);
    const size_t getNbDiceChosen(Player& p);
    virtual void action(Player* player);
	size_t* activateRadioTower(Player* player, size_t nb, size_t* throws) const;
	void activateAmusementPark(Player* p, size_t nb, size_t* throws);

public:
    virtual ~Controller();


    static Controller& getInstance(Interface* interface = nullptr);

    const Proxy* getProxy() const { return proxy;}
    void match();
    Game* getGame() {
        return game;
    }

    void tradeTwoEstablishmentCards(Player* p1, Player* p2, EstablishmentCard* card1, EstablishmentCard* card2);
};
