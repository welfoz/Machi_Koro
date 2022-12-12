#include "interface.h"

Interface* Interface::createInterfaceFromOption(Type type)
{
	switch (type) {
	case Type::cli:
		return new Cli();
	case Type::gui:
		return new Gui();
	default:
		throw "sa mere";
	}
}

void Cli::printWelcomingMessage() {
    cout<< "\n\n";
    cout << "███    ███  █████   ██████ ██   ██ ██     ██   ██  ██████  ██████   ██████  \n";
    cout << "████  ████ ██   ██ ██      ██   ██ ██     ██  ██  ██    ██ ██   ██ ██    ██ \n";
    cout << "██ ████ ██ ███████ ██      ███████ ██     █████   ██    ██ ██████  ██    ██ \n";
    cout << "██  ██  ██ ██   ██ ██      ██   ██ ██     ██  ██  ██    ██ ██   ██ ██    ██ \n";
    cout << "██      ██ ██   ██  ██████ ██   ██ ██     ██   ██  ██████  ██   ██  ██████  \n";

    cout << ".   .__. _,  ,           .__. _,  _, \n";
    cout << "|   |  |'_) /|     ___   [__]'_) '_) \n";
    cout << "|___|__|/_. .|.          |  |/_. /_. \n\n";

    cout << "Made with ❤️  by MICHEL Fabien - BROSSARD Felix - TAVERNE Jules - CORTY Pol - LEMERLE Xavier\n\n";
}

string Cli::getInputText() {
	string text;
	cin >> text;
	return text;
}


// be careful! firstOption and secondOption HAS to be UTF-8. No accent.
bool Cli::isPlayerWantsToContinue(string message, string firstOption, string secondOption) {
	string stopAnswer = "";
	//while ((stopAnswer != "Y") && (stopAnswer != "y") && (stopAnswer != "N") && (stopAnswer != "n")) {
	while (Formatter::toLower(stopAnswer) != Formatter::toLower(firstOption) && Formatter::toLower(stopAnswer) != Formatter::toLower(secondOption)) {
		cout << message << " (" << firstOption << " | " << secondOption << ") ";
		cin >> stopAnswer;
	}
	if (Formatter::toLower(stopAnswer) == Formatter::toLower(secondOption)) {
		return false;
	}
	return true;
}

void Cli::printBasicMessage(string message) {
	cout << message;
}
