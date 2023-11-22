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
        std::string lampID() const;
        void print_lamp() const;
        void status() const;
        // ----- Setters -----

        void set_id(houseCode HouseCode, short UnitCode);
        void turnOn();
        void turnOff();

        // ----- Getters -----

        bool is_on() const;
        std::pair<houseCode, short> id() const;

        // Destructor
        ~Lamp();

        // Disable copy and assigment
        // Lamp(Lamp const&)            = delete;
        // Lamp& operator=(Lamp const&) = delete;
        
    private:
        Device deviceID {houseCode::INVALID, 0};
        bool state {false};
    };
}

#endif // LAMP_H