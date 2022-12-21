#pragma once
#include "../../game/game.h"
#include "greenValleyExtensionCards.h"
#include "PlayerGreenValley.h"

class GreenValley : public virtual Game {
protected:
    void createEstablishmentCards() override;
    //monuments remain the same as standard edition
    void createPlayer(string name, size_t id) override;
    //board remain the same as standard edition
    void createIcons() override;
    void purchaseOneEstablismentCard(Player* player, EstablishmentCard* card) override;
	void undoPurchaseOneEstablismentCard(Player* player, EstablishmentCard* card) override;
public :
    PlayerGreenValley& getPlayer(size_t id) const override;
    GreenValley() : Game(){};
};
