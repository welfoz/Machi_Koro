#pragma once
#include "../bank/account.h"
#include "../cards/allCards.h"
#include "../bank/bank.h"
#include "../cards/baseCard.h"
#include "board.h"
#include "../cards/cardColor.h"
#include "dice.h"
#include "../cards/establishmentCard.h"
#include "../cards/icon.h"
#include "../cards/monument.h"
#include "../players/player.h"
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
    size_t nbPlayers;

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
    void activation(Player* p, size_t number);
    void activationRedCards(Player* p, size_t n);
    void activationGreenAndBlueCards(Player* p, size_t n);
    void activationPurpleCards(Player* p, size_t n);
    void action(Player* player);
    const size_t getNbDiceChosen(Player& p);


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
    Monument* getMonumentByName(string name) const;

};
