#include "game.h"

int main(int argc, const char* argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    Game game;
    game.createAll();

    // example creation Icone
    Icon icon1("wheat", "wheat.png", Type::primaryIndustry);

    // example create carte 
    WheatField wheatfield;
    cout << wheatfield.getName() << '\n';
    cout << wheatfield.getEffetDescription() << '\n';
    cout << wheatfield.getNumberActivation() << '\n';
    cout << wheatfield.getPrice() << '\n';
    cout << wheatfield.getType() << '\n';
    size_t* a = wheatfield.getActivationNumbers();
    for (size_t i = 0; i < 3; i++) {
        cout << *a << '\n';
        a++;
    }
    cout << wheatfield.getIcon()->getImage() << '\n';
    cout << wheatfield.getIcon()->getName() << '\n';
    cout << typeToString(wheatfield.getIcon()->getType()) << '\n';

    system("pause");


    return 0;
}
