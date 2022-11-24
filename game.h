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
using namespace std;

class Game{
protected:
    static Game* instance;
    vector<BaseCard*> cards;
    Board* board;
    Player* players[10];
    Bank* bank;
    Dice dice;
    Player* winner;
    vector<const Icon*> icons;

    Game* getInstance();
    void freeInstance();
    Game(const Game&) = delete;
    Game& operator=(const Game& g) = delete;

    // initialisation : toutes ces méthodes sont appellés dans le constructeur Game()
    void createBank();
    void createPlayer(string name, size_t id);
    virtual void createCards();
    virtual void createBoard();
    virtual void createIcons();

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
    const vector<Icon*> getIcons();
    void match();
};
