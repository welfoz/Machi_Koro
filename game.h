#pragma once
#include "account.h"
#include "allCards.h"
#include "bank.h"
#include "baseCard.h"
#include "board.h"
#include "cardColor.h"
#include "dice.h"
#include "establishmentCard.h"
#include "icon.h"
#include "monument.h"
#include "player.h"
#include <vector>
#include <algorithm>
using namespace std;

class Game{
protected:
    static Game* instance;
    vector<EstablishmentCard*> cards;
    vector<Monument*> monuments;
    Board* board;
    Player* players[10];
    Bank* bank;
    Dice dice;
    Player* winner;
    vector<const Icon*> icons;

    static Game* getInstance();
    static void freeInstance();
    Game(const Game&) = delete;
    Game& operator=(const Game& g) = delete;

    // initialisation : toutes ces méthodes sont appellés dans le constructeur Game()
    void createBank(size_t nbOfPlayers);
    void createPlayer(string name, size_t id);
    virtual void createEstablishmentCards();
    virtual void createMonumentCards();
    virtual void createBoard();
    virtual void createIcons();

    vector<EstablishmentCard*> getPlayerStarterCards();
    //match methods
    virtual void turn(Player* player);
    int throwDice(size_t numberOfDices);
    void activation(size_t number);
    void activationRedCards(size_t n);
    void activationGreenCards(size_t n);
    void activationPurpleCards(size_t n);
    void activationBlueCards(size_t n);
    void action();
    void buildEstablishment(BaseCard& card);
    void buildMonument(Monument& monument);



public:
    Game();
    ~Game();

    // we can't call virtual functions in the constructor
    void createAll();
    
    const vector<Icon*> getIcons();
    void match();

    // getter
    Player& getPlayer(size_t id) const {
        return *players[id - 1];
    };
    EstablishmentCard* getCardByName(string name) const;

};
