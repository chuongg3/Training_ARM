#ifndef NAMEDLAMP_H
#define NAMEDLAMP_H

#include <Lamp.h>
#include <string_view>
#include <iostream>

namespace Home{
    class Named_lamp : public Lamp{
    public:
        Named_lamp(const char* Name);
        Named_lamp(const char* Name, houseCode HouseCode, short UnitCode);
        Named_lamp(const char* Name, houseCode HouseCode, short UnitCode, bool State);

        void turnOn() override;
        void turnOff() override;

    private:
        std::string_view name {};
    };
}

#endif