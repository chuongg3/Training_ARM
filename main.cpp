#include <iostream>
#include <array>
#include <Lamp.h>

using Home::Lamp;

constexpr unsigned size{ 10 };

void all_lamps_on(std::array<Lamp, size>& lamps);
void all_lamps_off(std::array<Lamp, size>& lamps);
unsigned count_lamps_on(std::array<Lamp, size>& lamps);

Lamp make_lamp(){
	int hs { rand()%8 + 1 };
	int id { rand()%4 + 1};
	return Lamp({static_cast<houseCode>(hs), static_cast<short>(id)});
}

int main(){
    std::array<Lamp, size> lamps {make_lamp(), make_lamp(), make_lamp(), make_lamp(), make_lamp()};

    lamps[0].turnOn(); 
    lamps[2].turnOn();

    for (auto& lamp : lamps) {
        if (lamp.id().first != houseCode::INVALID) { 
            lamp.status();
        }
    }

}

void all_lamps_on(std::array<Lamp, size>& lamps)
{
    for (auto& lamp : lamps) {
        if (lamp.id().first != houseCode::INVALID) { 
            lamp.turnOn(); 
        }
    }
}

void all_lamps_off(std::array<Lamp, size>& lamps)
{
    for (auto& lamp : lamps) {
        if (lamp.id().first != houseCode::INVALID) { 
            lamp.turnOff(); 
        }
    }
}

unsigned count_lamps_on(std::array<Lamp, size>& lamps)
{
    unsigned count {};
    for (auto& lamp : lamps) {
        if (lamp.id().first != houseCode::INVALID && lamp.is_on()) {
            ++count;
        }
    }
    return count;
}