#pragma once
#include <string>
#include <iostream>
#include "../formatter/formatter.h"


using namespace std;

class Interface {
protected:
	Interface() = default;
	virtual ~Interface() = default;


public:
	enum Type {cli, gui};
	static Interface* createInterfaceFromOption(Type type);
	virtual void printWelcomingMessage() = 0;
	virtual string getInputText() = 0;
	virtual bool isPlayerWantsToContinue(string message, string firstOption, string secondOption) = 0;
	virtual void printBasicMessage(string message) = 0;
}; 

class Cli : public Interface {
public:
	Cli() : Interface() {};
	~Cli() {};
	void printWelcomingMessage() override;
	string getInputText() override;
	bool isPlayerWantsToContinue(string message, string firstOption, string secondOption) override;
	void printBasicMessage(string message) override;
};

class Gui : public Interface {
public:
	Gui() : Interface() {};
	~Gui() {};
	void printWelcomingMessage() override {};
	string getInputText() override { return ""; };
	bool isPlayerWantsToContinue(string message, string firstOption, string secondOption) override { return true; };
	void printBasicMessage(string message) override {};
};
