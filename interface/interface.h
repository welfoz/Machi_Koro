#include <string>
#include <iostream>

using namespace std;

class Interface {
protected:
	Interface() = default;
	virtual ~Interface() = default;


public:
	enum Type {cli, gui};
	static Interface* createInterfaceFromOption(Type type);
	virtual void printWelcomingMessage() = 0;
};

class Cli : public Interface {
public:
	Cli() : Interface() {};
	~Cli() {};
	void printWelcomingMessage() override;
};

class Gui : public Interface {
public:
	Gui() : Interface() {};
	~Gui() {};
	void printWelcomingMessage() override {};
};
