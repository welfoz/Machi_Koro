#pragma once
#include<string>
using namespace std;

enum class Type { primaryIndustry, secondaryIndustry, restaurants, majorEstablishment, landmark};


string typeToString(Type type);


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
};
