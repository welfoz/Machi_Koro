#include "formatter.h"

string Formatter::format(string text, unsigned int maxLenght) {
    string spaces(maxLenght - text.length(), ' ');
    string separator = " | ";
	return text + spaces + separator;
};

string Formatter::formatHeader(vector<pair<string, unsigned int>> texts) {
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

string Formatter::toLower(string text) {
    std::transform(text.begin(), text.end(), text.begin(),
        [](unsigned char c) { return std::tolower(c); });
    return text;
}
