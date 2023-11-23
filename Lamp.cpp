#include "Lamp.h"
#include <iostream>

namespace Home{
    // Constructors
    Lamp::Lamp(){
        std::cout << "Created lamp instance with an Invalid device ID" << std::endl;
    };

    Lamp::Lamp(houseCode hc, short uc) {
        set_id(hc, uc);
        std::cout << "Created " << printDeviceID() << ": In off state" << std::endl;
    };

    Lamp::Lamp(houseCode hc, short uc, bool State) {
        set_id(hc, uc);
        set_state(State);
        std::cout << "Created " << printDeviceID() << ": In " << (State? "On" : "Off") << " state" << std::endl;
    };

    // Destructor
    Lamp::~Lamp(){
        set_state(false);
        std::cout << "Deleting " << printDeviceID() << ": In off state" << std::endl;
    }

    // Methods
    void Lamp::turnOn(){
        set_state(true);
        print_lamp();
    }

    void Lamp::turnOff(){
        set_state(false);
        print_lamp();
    }

    void Lamp::print_lamp() const{
        std::cout << "Lamp (" << printDeviceID() << ") is currently " << (is_on()? "on" : "off") << "\n";
    }
}