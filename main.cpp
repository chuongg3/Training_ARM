#include <iostream>
#include <array>
#include <Lamp.h>

using Home::Lamp;

constexpr unsigned size{ 8 };

void all_lamps_on(std::array<Lamp, size>& lamps);
void all_lamps_off(std::array<Lamp, size>& lamps);
unsigned count_lamps_on(std::array<Lamp, size>& lamps);

Lamp make_lamp(){
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
        << std::to_string(lamp.deviceID.UnitCode) << ")";
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