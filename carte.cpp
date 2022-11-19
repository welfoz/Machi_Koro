#include "carte.h"

bool Carte::inActivationNumeros(size_t nombreTire) const {
    for (size_t i=0;i<number_of_numeros;i++){
        if (activation_numeros[i]==nombreTire) return true;
    }
    return false;
}
