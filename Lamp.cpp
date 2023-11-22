#include "Lamp.h"
#include <iostream>

namespace Home{
    // Constructors
    Lamp::Lamp(){
        std::cout << "Created lamp instance with an Invalid device ID" << std::endl;
    };

    Lamp::Lamp(houseCode hc, short uc) : deviceID {hc, uc} {
        std::cout << "Created " << lampID() << ": In off state" << std::endl;
    };

    Lamp::Lamp(houseCode hc, short uc, bool State) : deviceID {hc, uc} , state {State} {
        std::cout << "Created " << lampID() << ": In " << (State? "On" : "Off") << " state" << std::endl;
    };

    // Destructor
    Lamp::~Lamp(){
        state = false;
        std::cout << "Deleting " << lampID() << ": In off state" << std::endl;
    }

    // Methods
    std::string Lamp::lampID() const{
        return HouseName[static_cast<int>(deviceID.HouseCode)] + std::to_string(deviceID.UnitCode);
    }

    void Lamp::print_lamp() const{
        std::cout << "Lamp(" << lampID() << ")\n";
    }

    void Lamp::status() const{
        std::cout << "Lamp(" << lampID() << " is currently " << (state? "on" : "off") << ")\n";
    }

    void Lamp::set_id(houseCode hc, short uc){
        deviceID.HouseCode = hc;
        deviceID.UnitCode = uc;
    }

    void Lamp::turnOn(){
        state = true;
        status();
    }

    void Lamp::turnOff(){
        state = false;
        status();
    }

    bool Lamp::is_on() const{
        return state;
    }

    std::pair<houseCode, short> Lamp::id() const{
        return std::pair<houseCode, short> (deviceID.HouseCode, deviceID.UnitCode);
    }
}