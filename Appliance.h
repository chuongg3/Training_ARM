#ifndef APPLIANCE_H
#define APPLIANCE_H

#include <Module.h>

namespace Home{
    class Appliance : public Module {
    public:
        Appliance();
        Appliance(houseCode HouseCode, short UnitCode);
        Appliance(houseCode HouseCode, short UnitCode, bool State);

        void turnOn() override;
        void turnOff() override;

        void print_appliance() const;

        ~Appliance() = default;
    };
}

#endif