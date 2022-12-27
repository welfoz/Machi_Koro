//
// Created by jules on 27/12/2022.
//

#include "AI.h"

template<typename t>
t AI::getAiChoice(std::vector<t> options, std::vector<t> exceptions) const {
    if (exceptions.size() > 0)
        for (auto it: exceptions)
            if (count(options.begin(), options.end(), it)) std::remove(options.begin(), options.end(), it);
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, options.size() - 1);
    return options[dist(rng)]; // renvoie un élément situé à un index aléatoire entre le début et la fin du vector
}