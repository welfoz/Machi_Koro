#include "./game/game.h"
int main(int argc, const char* argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    cout << "Welcome to Machi Koro! Please choose the extension you want to play to:\n";
    char choice;
    while ((choice != 'B') && (choice != 'M') && (choice != 'G') && (choice != 'D')){
        cout << "Available extensions: Basic (B), Marina (M), Green Valley (G), Deluxe (D).\n";
        cout << "Enter the name of the extension you want to play to (B/M/G/D): \n";
        cin >> choice;
    }
    switch (choice)
    {
    case 'B':
        Game::getInstance().match();
        break;
    case 'M':
        #include "./extensions/marinaExtension.h"
        Marina::getInstance().match();
        break;
    // case 'G':
    //     #include "./extensions/greenValleyExtension.h"
    //     GreenValley::getInstance().match();
    //     break;
    // case 'D':
    //     #include "./extensions/deluxeExtension.h"
    //     Deluxe::getInstance().match();
    //     break;
    
    default:
        break;
    } 
    
    system("pause");
    return 0;
}
