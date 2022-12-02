#include "global.h"

string format(string text, unsigned int maxLenght) {
    string spaces(maxLenght - text.length(), ' ');
    string separator = " | ";
	return text + spaces + separator;
};

string formatHeader(vector<pair<string, unsigned int>> texts) {
    string header;
    string separator = " | ";
    string lineSeparator;
    for (auto it = texts.begin(); it != texts.end(); it++) {
        if (it->second == 0) {
            header += it->first;
            lineSeparator += string(20, '-');
        }
        else {
			header += it->first + string(it->second - it->first.length(), ' ') + separator;
            lineSeparator += string(it->second + separator.length(), '-');
        }
    }
    return header + "\n" + lineSeparator + "\n";
}

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

