#include <iostream>
#include <cstdint>
#include <string>

enum class houseCode : std::uint8_t {
    INVALID, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O
};

enum class State {On, Off};

const char* HouseName = "~ABCDEFGHIJKLMNO";

struct Device{
    houseCode houseCode;
    short unitCode;
};

struct Lamp {
    Device deviceID;
    bool lampState;
};

int main(){
    
    Lamp lamp;
    lamp.deviceID = Device {houseCode::A, 10};
    lamp.lampState = false;

    std::cout << "Lamp House Code: " << HouseName[static_cast<uint8_t>(lamp.deviceID.houseCode)] << "\n";
    std::cout << "Lamp Unit Code: " << std::to_string(lamp.deviceID.unitCode) << "\n";
    std::cout << "Lamp State: " << (lamp.lampState? "On" : "Off") << "\n";
}