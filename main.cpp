#include <iostream>
#include <cstdint>
#include <string>
#include <array>

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

    std::array<Lamp, 10> lamps{
        Lamp {{houseCode::A, 1}, false},
        Lamp {{houseCode::B, 2}, false},
        Lamp {{houseCode::C, 3}, false},
        Lamp {{houseCode::D, 4}, false},
        Lamp {{houseCode::E, 5}, false},
    };

    std::cout << "Size of array: " << lamps.size() << "\n";
    for (auto iterator = std::begin(lamps); iterator != std::end(lamps); iterator++){
        if (iterator->deviceID.houseCode != houseCode::INVALID){
            std::cout << "Current Lamp's Unit Code: " << iterator->deviceID.unitCode << "\n";
        }
    }
}