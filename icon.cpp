#include "icon.h"

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

