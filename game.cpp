#include "game.h"

Game* Game::getInstance()
{
    if (instance == nullptr)
        instance = new Game;
    return instance;
}

void Game::freeInstance()
{
    delete instance;
    instance = nullptr;
}

Game* Game::instance = nullptr;

Game::Game() : dice(Dice()), winner(nullptr), bank(nullptr), board(nullptr), players() {
    cout << "You're going to start a Machi Koro part\n";

    // create all players
    // ask number of players and their names
    unsigned int cpt = 1;
    string name;
    bool stop = false;
    string stopAnswer;
    while (cpt <= 10 && !stop) {
		cout << "Enter the name of the player number " << cpt << '\n';
        cin >> name;
		createPlayer(name, cpt);
        cout << "\n";
        cout << "Do you want to add another player ? (Y/N)";
        cin >> stopAnswer;
        if (stopAnswer == "y" || stopAnswer == "Y") {
            stop = true;
        }
		cpt++;
    }
 
    //createBoard();
    //createCards();
    //createIcons();
    //createBank();
};

void Game::createBank() {};

void Game::createPlayer(string name, size_t id) {};
void Game::createCards() {};
void Game::createIcons() {};
void Game::createBoard() {};
void Game::turn(Player* player) {}

Game::~Game() {};