#ifndef MODULE_H
#define MODULE_H

#include <Device.h>
#include <iostream>
#include <string>

namespace Home{
    class Module{
    public:
        // Return lamp device ID in string format
        std::string printDeviceID() const;
        void status() const;

        // ----- Setters -----
        void set_id(houseCode HouseCode, short UnitCode);
        void set_state(bool new_state);
        virtual void turnOn() = 0;
        virtual void turnOff() = 0;

        // ----- Getters -----
        bool is_on() const;
        std::pair<houseCode, short> id() const;

        virtual ~Module() = default;
    private:
        Device deviceID {houseCode::INVALID, 0};
        bool state {false};
    };
}

#endif