#ifndef LAMP_H
#define LAMP_H

#include <Device.h>

#include <string>

namespace Home{  
    class Lamp {
    public:
        // Constructors
        Lamp();
        Lamp(houseCode HouseCode, short UnitCode);
        Lamp(houseCode HouseCode, short UnitCode, bool State);

        // Return lamp device ID in string format
        std::string lampID();
        void print_lamp();
        void status();
        // ----- Setters -----

        void set_id(houseCode HouseCode, short UnitCode);
        void turnOn();
        void turnOff();

        // ----- Getters -----

        bool is_on();
        std::pair<houseCode, short> id();

        // Destructor
        ~Lamp();

    private:
        Device deviceID {houseCode::INVALID, 0};
        bool state {false};
    };
}

#endif // LAMP_H