#include "Lamp.h"
#include <iostream>


namespace Home{

    void print_lamp(const Lamp& lamp){
        std::cout << "Lamp(" 
            << HouseName[static_cast<int>(lamp.deviceID.HouseCode)] 
            << std::to_string(lamp.deviceID.UnitCode) << ")\n";
    }

    // Sets the state of the lamp to be on
    void lamp_on(Lamp& lamp){
        lamp.lampState = true;
        print_lamp(lamp);
        printf("Lamp(%c%i) has been turned on\n", HouseName[static_cast<int>(lamp.deviceID.HouseCode)], lamp.deviceID.UnitCode);
    }

    // Sets the state of the lamp to be off
    void lamp_off(Lamp& lamp){
        lamp.lampState = false;
        print_lamp(lamp);
        printf("Lamp(%c%i) has been turned off\n", HouseName[static_cast<int>(lamp.deviceID.HouseCode)], lamp.deviceID.UnitCode);
    }
}