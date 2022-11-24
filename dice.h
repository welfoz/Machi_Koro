//
// Created by jules on 12/11/2022.
//

#pragma once
#include "stdio.h"
using namespace std;

class Dice {
    friend class Game;
    static const int min = 1;
    static const int max = 6;
    const size_t throwDice() const{
        return 0;
    };
    public:
        Dice() {};
};
