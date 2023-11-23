#ifndef LAMP_H
#define LAMP_H

#include <Device.h>
#include <Module.h>

#include <string>

namespace Home{  
    class Lamp : public Module{
    public:
        // Constructors
        Lamp();
        Lamp(houseCode HouseCode, short UnitCode);
        Lamp(houseCode HouseCode, short UnitCode, bool State);

        // ----- Setters -----
        virtual void turnOn() override;
        virtual void turnOff() override;

        void print_lamp() const;
        
        // Destructor
        ~Lamp();
    };
}

#endif // LAMP_H