#include "joueur.h"

void Joueur::activateRedCards(size_t nombreTire) {
    for(size_t i=0;i<cartes.size();i++){
        if (cartes[i]->getType()=="Restaurents" && cartes[i]->inActivationNumeros(nombreTire)) cartes[i]->activation(*this);
    }
}
void Joueur::activateBlueCards(size_t nombreTire){
    for(size_t i=0;i<cartes.size();i++){
        if (cartes[i]->getType()=="Primary Industrie" && cartes[i]->inActivationNumeros(nombreTire)) cartes[i]->activation(*this);
    }
}
void Joueur::activateGreenCards(size_t nombreTire){
    for(size_t i=0;i<cartes.size();i++){
        if (cartes[i]->getType()=="Secondary Industrie" && cartes[i]->inActivationNumeros(nombreTire)) cartes[i]->activation(*this);
    }
}
void Joueur::activatePurpleCards(size_t nombreTire){
    for(size_t i=0;i<cartes.size();i++){
        if (cartes[i]->getType()=="Major Establishment" && cartes[i]->inActivationNumeros(nombreTire)) cartes[i]->activation(*this);
    }
}