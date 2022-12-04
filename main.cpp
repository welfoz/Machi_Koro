#include "./game/game.h"
int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Game::getInstance().match();
    system("pause");


    return 0;
}
