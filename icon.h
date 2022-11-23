//#ifndef MACHI_KORO_PLAYER_H
//#define MACHI_KORO_PLAYER_H
#include<string>
using namespace std;

enum class Type { primaryIndustry, secondaryIndustry, restaurants, majorEstablishment, landmark};

string typeToString(Type type) {
	switch (type) {
	case Type::primaryIndustry:
		return "Primary Industry";
	case Type::secondaryIndustry:
		return "Secondary Industry";
	case Type::restaurants:
		return "Restaurants";
	case Type::majorEstablishment:
		return "Major Establishment";
	case Type::landmark:
		return "LandMark";
	default:
		return "Error unrecognized type\n";
	};
}


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
//#endif 
