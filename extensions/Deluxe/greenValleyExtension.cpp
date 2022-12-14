#include "greenValleyExtension.h"


//GreenValley& GreenValley::getInstance() {
//    if (instance == nullptr)
//        instance = new GreenValley();
//    return dynamic_cast<GreenValley&>(*instance);
//}

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

//void GreenValley::turn(Player* player){
//    cout << "Green Valley \n\n";
//    Game::turn(player);
//}

void GreenValley::createPlayer(string name, size_t id) {
    if (!canAddNewPlayer()) {
        throw out_of_range("limit_players_reached");
    }

    for (unsigned int i = 0; i < this->nbPlayers; i++) {
        if (players[i]->getUsername() == name) {
			throw invalid_argument("two_players_homonyme");
        }
    }
    players[id] = new PlayerGreenValley(name, id, monuments, getPlayerStarterCards());

    this->nbPlayers += 1;
}
//void GreenValley::action(Player *player) {
//    size_t n = player->getCards().count(getCardByName("Loan Office"));
//    Game::action(player);
//    size_t n2=player->getCards().count(getCardByName("Loan Office"));
//    if (n<n2) bank->credit(player->getId(),5);
//    EstablishmentCard* card=getCardByName("Tech Startup");
//    auto techStartup = dynamic_cast<TechStartup*> (card);
//    if (player->getCards().count(techStartup)){
//        string choice;
//        cout<<"Do you want to invest on Tech Startup ? (Y/N)"<<endl;
//        cin>>choice;
//        if (choice=="Y" || choice=="y") techStartup->invest(player,1);
//    }
//}

PlayerGreenValley& GreenValley::getPlayer(size_t id) const {
    return dynamic_cast<PlayerGreenValley&>(*players[id]);
}
