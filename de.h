//
// Created by jules on 12/11/2022.
//

#ifndef MACHI_KORO_DE_H
#define MACHI_KORO_DE_H

class De {
    friend class Jeu;
    static const int min = 1;
    static const int max = 6;
    const int tirer() const;
};

#endif //MACHI_KORO_DE_H
