#pragma once
#include <string>
#include <vector>
#include "../cards/icon.h"
#include <algorithm>
#include <cctype>

using namespace std;

class Formatter {
public:
	static string format(string text, unsigned int maxLenght);

	static string formatHeader(vector<pair<string, unsigned int>> texts);
	 
	static string toLower(string text);

};


