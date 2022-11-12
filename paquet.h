#ifndef MACHI_KORO_PAQUET_H
#define MACHI_KORO_PAQUET_H
#include "carte.h"

class Paquet
{
private:
    int CartesRestantes;
    Carte** Paquet;
public:
    Carte& retirer_carte(Carte& carteARetirer);
    afficherPaquet();
};

#endif //MACHI_KORO_PAQUET_H
