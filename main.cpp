//#include "./extensions/Marina/marinaExtension.h"
#include "extensions/Deluxe/greenValleyExtension.h"
int main(int argc, const char* argv[]) {
    // insert code here...
    /*
    cout << "Hello, World!\n";
    cout << "Welcome to Machi Koro! Please choose the extension you want to play to:\n";
    char choice = '0';
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
        Marina::getInstance().match();
        break;
		// case 'G':
		//     #include "./extensions/Deluxe/greenValleyExtension.h"
		//     GreenValley::getInstance().match();
		//     break;
		// case 'D':
		//     #include "./extensions/deluxeExtension.h"
		//     Deluxe::getInstance().match();
		//     break;
    default:
        break;
    }*/
    GreenValley::getInstance().match();
    system("pause");
    return 0;
}
