#pragma once
#include "establishmentCard.h"
#include "player.h"
bool EstablishmentCard::inActivationNumbers(size_t diceNumber) const {
    for (size_t i=0;i<numberActivation;i++){
        if (activationNumbers[i]==diceNumber) return true;
    }
    return false;
}
