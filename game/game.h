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
#include "../interface/interface.h"
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

class Game{
    friend class Controller;
protected:
    vector<EstablishmentCard*> cards;
    vector<Monument*> monuments;
    Board* board;
    Player* players[10];
    Bank* bank;
    Dice dice;
    Player* winner;
    vector<const Icon*> icons;
    size_t nbPlayers;
    size_t idCurrentPlayer;
    size_t diceValue;

    Game();
    Game(const Game&) = delete;
    Game& operator=(const Game& g) = delete;

    // initialisation : toutes ces méthodes sont appellés dans le constructeur Game()
    void createBank(size_t nbOfPlayers);
    virtual void createPlayer(string name, size_t id);
    virtual void createEstablishmentCards();
    virtual void createMonumentCards();
    virtual void createBoard();
    virtual void createIcons();
    vector<EstablishmentCard*> getPlayerStarterCards();

    void setDiceValue(size_t nb, size_t* throws);
    
    void activation(Player* p, size_t number);
    virtual void activationRedCards(Player* p, size_t n);
    virtual void activationGreenAndBlueCards(Player* p, size_t n);
    virtual void activationPurpleCards(Player* p, size_t n);
    void activateShoppingMall(Player* p, vector<EstablishmentCard*> cards);

    size_t* throwDices(size_t nb) const;
    bool isWinner(Player* player) const;

    bool isPlayerAbleToPayEstablishmentCard(Player* p);
    bool isPlayerAbleToPayMonument(Player* p);
    bool canAddNewPlayer() const;

public:
    virtual ~Game();

    // getter
    const size_t getDiceValue() const {
        return diceValue;
    };
    const size_t& getNbPlayers() const {return nbPlayers;}
    Bank* getBank() const {return bank;}
    virtual Player& getPlayer(size_t id) const {return *players[id];}; //pourquoi il y avait *players[id-1] ?
    const size_t& getIdCurrentPlayer() const {return idCurrentPlayer;}
    EstablishmentCard* getCardByName(string name) const;
    Monument* getMonumentByName(string name) const;
    Player* getPlayerByName(string name) const;
    vector<const Icon*> getIcons() const {return this->icons;};
    const Board* const getBoard() const {
        return board;
    }

    void tradeCards(Player* p1, Player* p2,EstablishmentCard* cardP1, EstablishmentCard* cardP2);
};

