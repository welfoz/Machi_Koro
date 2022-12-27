//
// Created by jules on 27/12/2022.
//

#ifndef MACHI_KORO_AI_H
#define MACHI_KORO_AI_H
#include "stdlib.h"
#include<vector>
#include <random>
class Ai {
public:
    Ai() = default;
    template<typename t> t getAiChoice(std::vector<t> options,std::vector<t> exceptions={}) const;
};


#endif //MACHI_KORO_AI_H
