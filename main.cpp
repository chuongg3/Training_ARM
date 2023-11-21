#include <iostream>
#include <cstdint>
#include <string>
#include <array>
#include <algorithm>

enum class houseCode : std::uint8_t {
    INVALID, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O
};

const char* HouseName = "~ABCDEFGHIJKLMNO";

enum class State {On, Off};

struct Device{
    houseCode HouseCode;
    short unitCode;
};

struct Lamp {
    Device deviceID;
    bool lampState;
};

constexpr unsigned size{ 8 };

// Output a Lamp's data:
void print_lamp(const Lamp& lamp);
void all_lamps_on(std::array<Lamp, size>& lamps);
void all_lamps_off(std::array<Lamp, size>& lamps);
unsigned count_lamps_on(std::array<Lamp, size>& lamps);

// Sets the state of the lamp to be on
void lamp_on(Lamp& lamp){
    lamp.lampState = true;
    print_lamp(lamp);
    printf("Lamp(%c%i) has been turned on\n", HouseName[static_cast<int>(lamp.deviceID.HouseCode)], lamp.deviceID.unitCode);
}

// Sets the state of the lamp to be off
void lamp_off(Lamp& lamp){
    lamp.lampState = false;
    print_lamp(lamp);
    printf("Lamp(%c%i) has been turned off\n", HouseName[static_cast<int>(lamp.deviceID.HouseCode)], lamp.deviceID.unitCode);
}

Lamp make_lamp()
{
	int hs { rand()%8 + 1 };
	int id { rand()%4 + 1};
	return Lamp{ { static_cast<houseCode>(hs), static_cast<short>(id) }, false };
}

int main(){
    
    Lamp desk_lamp{ { houseCode::A, 1 }, false };
    auto lamp = make_lamp();

    lamp_on(desk_lamp);
    lamp_on(lamp);

    lamp_off(lamp);
    lamp_off(desk_lamp);
}

void print_lamp(const Lamp& lamp)
{
    std::cout << "Lamp(" 
        << HouseName[static_cast<int>(lamp.deviceID.HouseCode)] 
        << std::to_string(lamp.deviceID.unitCode) << ")";
}

void all_lamps_on(std::array<Lamp, size>& lamps)
{
    for (auto& lamp : lamps) {
        if (lamp.deviceID.HouseCode != houseCode::INVALID) { 
            lamp_on(lamp); 
        }
    }
}

void all_lamps_off(std::array<Lamp, size>& lamps)
{
    for (auto& lamp : lamps) {
        if (lamp.deviceID.HouseCode != houseCode::INVALID) { 
            lamp_off(lamp); 
        }
    }
}

unsigned count_lamps_on(std::array<Lamp, size>& lamps)
{
    unsigned count {};
    for (auto& lamp : lamps) {
        if (lamp.deviceID.HouseCode != houseCode::INVALID && lamp.lampState) {
            ++count;
        }
    }
    return count;
}