#include <Module.h>

namespace Home{
    std::string Module::printDeviceID() const{
        return HouseName[static_cast<int>(deviceID.HouseCode)] + std::to_string(deviceID.UnitCode);
    }

    void Module::status() const{
        std::cout << "Module (" << printDeviceID() << ") is currently " << (state? "on" : "off") << "\n";
    }

    void Module::set_id(houseCode hc, short uc){
        deviceID.HouseCode = hc;
        deviceID.UnitCode = uc;
    }

    void Module::set_state(bool new_state){
        state = new_state;
    }

    bool Module::is_on() const{
        return state;
    }

    std::pair<houseCode, short> Module::id() const{
        return std::make_pair(deviceID.HouseCode, deviceID.UnitCode);
    }
}