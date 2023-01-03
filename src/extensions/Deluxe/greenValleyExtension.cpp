#include "greenValleyExtension.h"

void GreenValley::createEstablishmentCards(){
    Game::createEstablishmentCards();
    cards.push_back(new CornField());
    cards.push_back(new Vineyard());
    cards.push_back(new GeneralStore());
    cards.push_back(new MovingCompany());
    cards.push_back(new LoanOffice());
    cards.push_back(new Winery());
    cards.push_back(new DemolitionCompany());
    cards.push_back(new SodaBottlingPlant());
    cards.push_back(new FrenchRestaurant());
    cards.push_back(new MembersOnlyClub());
    cards.push_back(new Park());
    cards.push_back(new RenovationCompany());
    cards.push_back(new TechStartup());
    cards.push_back(new InternationalExhibitHall());
}


void GreenValley::createIcons(){
    Game::createIcons();
    icons.push_back(new Icon("suitcase","suitcase.png",Type::secondaryIndustry));
}

void GreenValley::createPlayer(string name, size_t id, bool isAi) {
    if (!canAddNewPlayer()) {
        throw out_of_range("limit_players_reached");
    }

    for (unsigned int i = 0; i < this->nbPlayers; i++) {
        if (players[i]->getUsername() == name) {
			throw invalid_argument("two_players_homonyme");
        }
    }
    players[id] = new PlayerGreenValley(name, id, monuments, getPlayerStarterCards(), isAi);

    this->nbPlayers += 1;
}

PlayerGreenValley& GreenValley::getPlayer(size_t id) const {
    return dynamic_cast<PlayerGreenValley&>(*players[id]);
}

void GreenValley::purchaseOneEstablismentCard(Player* player, EstablishmentCard* card) {
    Game::purchaseOneEstablismentCard(player, card);

    if (card->getName() == "Loan Office") {
		this->bank->credit(player->getId(), 5);
    }
}

void GreenValley::undoPurchaseOneEstablismentCard(Player* player, EstablishmentCard* card) {
    Game::undoPurchaseOneEstablismentCard(player, card);

    if (card->getName() == "Loan Office") {
		this->bank->debit(player->getId(), 5);
    }
}
