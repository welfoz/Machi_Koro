#ifndef MACHIKORO_H
#define MACHIKORO_H
#include "./controller/deluxeController.h"
#include "./controller/greenValleyController.h"
#include "./controller/marinaController.h"
#include "./controller/control.h"
#include "../interface/interface.h"
class MachiKoro {
public:
    MachiKoro() = default;
    void play() const;
};
#endif // MACHIKORO_H
