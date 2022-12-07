#include "greenValleyExtension.h"


GreenValley& GreenValley::getInstance() {
    if (instance == nullptr)
        instance = new GreenValley;
    return dynamic_cast<GreenValley&>(*instance);
}

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

void GreenValley::turn(Player* player){
    cout << "Green Valley \n\n";
    Game::turn(player);
}

map<EstablishmentCard *, bool> GreenValley::createClosed() {
    map<EstablishmentCard *, bool> closed;
    for (auto it: cards) {
        closed.insert({&(*it), false});
    }
    return closed;
}

void GreenValley::createPlayer(string name, size_t id) {
    players[id] = new Player(name, id, monuments, getPlayerStarterCards(),createClosed());
}
void GreenValley::action(Player *player) {
    size_t n = player->getCards().count(getCardByName("Loan Office"));
    Game::action(player);
    size_t n2=player->getCards().count(getCardByName("Loan Office"));
    if (n<n2) bank->credit(player->getId(),5);
}

void GreenValley::activationPurpleCards(Player *p, size_t n) {
    Game::activationPurpleCards(p,n);
    EstablishmentCard* card=getCardByName("Tech Startup");
    auto techStartup = dynamic_cast<TechStartup*> (card);
    if (p->getCards().count(techStartup)){
        string choice;
        cout<<"Do you want to invest on Tech Startup ? (Y/N)"<<endl;
        cin>>choice;
        if (choice=="Y" || choice=="y") techStartup->invest(p,1);
    }
}