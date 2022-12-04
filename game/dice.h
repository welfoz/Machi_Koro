//
// Created by jules on 12/11/2022.
//

#pragma once
#include "stdio.h"
#include <cstdlib>
using namespace std;

class Dice {
    friend class Game;
    const size_t throwDice() const;
public:
    Dice()= default;
    ~Dice()= default;
};
