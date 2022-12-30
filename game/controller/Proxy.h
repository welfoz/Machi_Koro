//
// Created by jules on 29/12/2022.
//
#pragma once
#include "../../interface/Ai.h"

class Ai;

class Proxy {
    Interface* interface;
    Ai* aiInterface;
public:
    Proxy(Interface* interface);
    ~Proxy();
    Interface* getInterface(bool gameCreation=false) const;
};
