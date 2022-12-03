#include "dice.h"

const size_t Dice::throwDice() const {
	size_t dice = rand() % max + min;
	return dice;
};