//
// Created by jules on 12/11/2022.
//

#pragma once
#include "stdio.h"
#include <cstdlib>
using namespace std;

class Dice {
public:
    const size_t throwDice() const;
    Dice()= default;
    ~Dice()= default;
};
