#pragma once
#include "stdio.h"
#include <random>
using namespace std;

class Dice {
public:
    const size_t throwDice() const;
    Dice()= default;
    ~Dice()= default;
};
