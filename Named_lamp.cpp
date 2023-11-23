#include <Named_lamp.h>

namespace Home {
    Named_lamp::Named_lamp(const char* Name) : name {Name}{
        std::cout << "Created lamp instance with an Invalid device ID with name " << Name << std::endl;
    }
    Named_lamp::Named_lamp(const char* Name, houseCode HouseCode, short UnitCode)
    :   Lamp {HouseCode, UnitCode},
        name {Name} {
            std::cout << "Created " << lampID() << " with name " << Name << ": In off state" << std::endl;
        }
    Named_lamp::Named_lamp(const char* Name, houseCode HouseCode, short UnitCode, bool State)
    :   Lamp {HouseCode, UnitCode, State},
        name {Name}{
            std::cout << "Created " << lampID() << " with name " << Name << ": In " << (State? "On" : "Off") << " state" << std::endl;
        }

    void Named_lamp::turnOn(){
        std::cout << name << ": ";
        Lamp::turnOn();
    }

    void Named_lamp::turnOff(){
        std::cout << name << ": ";
        Lamp::turnOff();
    }
}