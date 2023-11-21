#ifndef LAMP_H
#define LAMP_H

#include <Device.h>

namespace Home{
    struct Lamp {
        Device deviceID;
        bool lampState;
    };

    // Output a Lamp's data:
    void print_lamp(const Lamp& lamp);

    // Sets the state of the lamp to be on
    void lamp_on(Lamp& lamp);

    // Sets the state of the lamp to be off
    void lamp_off(Lamp& lamp);
}

#endif // LAMP_H