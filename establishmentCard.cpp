#include "establishmentCard.h"
#include "player.h"
bool EstablishmentCard::inActivationNumbers(size_t nombreTire) const {
    for (size_t i=0;i<numberActivation;i++){
        if (activationNumbers[i]==nombreTire) return true;
    }
    return false;
}
