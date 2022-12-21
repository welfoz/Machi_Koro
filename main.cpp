
#include "./extensions/Marina/marinaExtension.h"
#include "extensions/Deluxe/greenValleyExtension.h"
#include "game/controller/control.h"
int main(int argc, const char* argv[]) {
    // insert code here...

    cout << "Hello, World!\n";
    cout << "Welcome to Machi Koro! Please choose the extension you want to play to:\n";
    char choice = '0';
    while ((choice != 'B') && (choice != 'M') && (choice != 'G') && (choice != 'D')){
        cout << "Available extensions: Basic (B), Marina (M), Green Valley (G), Deluxe (D).\n";
        cout << "Enter the name of the extension you want to play to (B/M/G/D): \n";
        cin >> choice;
        cin.ignore();
    }
    switch (choice)
    {
    case 'B':
        Controller::getInstance().match();
        break;
    case 'M':{
        MarinaController::getInstance().match();
        break;
    }

    case 'G':{
        GreenValleyController::getInstance().match();
        break;
    }
    case 'D':
        DeluxeController::getInstance().match();
		     break;
    default:
        break;
    }
    system("pause");
    return 0;
}
