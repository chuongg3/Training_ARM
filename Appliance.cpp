#include <Appliance.h>

namespace Home{
    Appliance::Appliance(){
        std::cout << "Created Appliance instance with an Invalid device ID" << std::endl;
    };

    Appliance::Appliance(houseCode hc, short uc) {
        set_id(hc, uc);
        std::cout << "Created " << printDeviceID() << ": In off state" << std::endl;
    };

    Appliance::Appliance(houseCode hc, short uc, bool State) {
        set_id(hc, uc);
        set_state(State);
        std::cout << "Created " << printDeviceID() << ": In " << (State? "On" : "Off") << " state" << std::endl;
    };

    void Appliance::turnOn(){
        set_state(true);
        print_appliance();
    }

    void Appliance::turnOff(){
        set_state(false);
        print_appliance();
    }

    void Appliance::print_appliance() const{
        std::cout << "Appliance (" << printDeviceID() << ") is currently " << (is_on()? "on" : "off") << "\n";
    }
}