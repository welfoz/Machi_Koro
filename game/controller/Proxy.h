//
// Created by jules on 29/12/2022.
//
#pragma once
#ifndef MACHI_KORO_PROXY_H
#define MACHI_KORO_PROXY_H
#include "../interface/Ai.h"

class Proxy {
    Interface* interface;
    Ai* aiInterface;
public:
    Proxy(Interface* interface);
    ~Proxy();
    Interface* getInterface(bool gameCreation=false) const; //with player permet de ne pas appeller l'ia lorsqu'on a besoin de l'interface pour imprimer les cartes par exemple (alors que le joueur actuel serait AI)
};


#endif //MACHI_KORO_PROXY_H
