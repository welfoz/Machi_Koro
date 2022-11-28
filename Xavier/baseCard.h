#ifndef MACHI_KORO_BASECARD_H
#define MACHI_KORO_BASECARD_H
#include "icon.h"
#include<string>
using namespace std;

class BaseCard {
private:
	string name; 
	size_t price; 
	string type; 
	Icon icon; 
	BaseCard(string name, size_t price, string type, Icon icon);

public : 
	const string getName() const; 
	const size_t getPrice() const; 
	const string getType() const;
	const Icon getIcon() const; 
};

#endif //MACHI_KORO_BASECARD_H