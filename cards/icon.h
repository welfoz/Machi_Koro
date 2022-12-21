#pragma once
#include<string>
using namespace std;

enum class Type { primaryIndustry, secondaryIndustry, restaurants, majorEstablishment, landmark};


class Icon {
	string name;
	string image;
	Type type;
public: 
	Icon(string n, string i, Type t) : name(n), image(i), type(t) {};

	const string& getName() const {
		return name;
	}

	const string& getImage() const {
		return image;
	}

	const Type getType() const {
		return type;
	}
    bool operator==(const Icon& i)const {return (this->name==i.name && this->type==i.getType());}
};
