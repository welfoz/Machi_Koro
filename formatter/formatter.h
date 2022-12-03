#include <string>
#include <vector>
#include "../cards/icon.h"

using namespace std;

class Formatter {
public:
	static string format(string text, unsigned int maxLenght);

	static string formatHeader(vector<pair<string, unsigned int>> texts);

};


