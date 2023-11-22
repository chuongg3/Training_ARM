#include <iostream>
#include <array>
#include <Lamp.h>
#include <Room.h>

// #define PART_1
#define PART_2
#define PART_3
#define PART_4

using Home::Lamp;
using Home::Room;

constexpr unsigned size{ 10 };

void all_lamps_on(std::array<Lamp, size>& lamps);
void all_lamps_off(std::array<Lamp, size>& lamps);
unsigned count_lamps_on(std::array<Lamp, size>& lamps);

// Lamp statuses
#ifdef PART_1
void lamp_status(Lamp lamp) {
    std::cout << "The lamp object is " << (lamp.is_on() ? "on" : "off") << "\n";
}
#endif

#ifdef PART_2
void lamp_status(Lamp const *lamp){
    std::cout << "The lamp pointer is " << (lamp->is_on() ? "on" : "off") << "\n";
}
#endif

#ifdef PART_3
void lamp_status(Lamp &lamp) {
    std::cout << "The lamp reference is " << (lamp.is_on() ? "on" : "off") << "\n";
}
#endif

#ifdef PART_4
void lamp_status(Lamp const &lamp){
    std::cout << "The lamp constant reference is " << (lamp.is_on() ? "on" : "off") << "\n";
}
#endif

Lamp make_lamp(){
	int hs { rand()%8 + 1 };
	int id { rand()%4 + 1};
	return Lamp({static_cast<houseCode>(hs), static_cast<short>(id)});
}

Lamp make_lamp(houseCode hc, short uc){
	return Lamp({static_cast<houseCode>(hc), static_cast<short>(uc)});
}

int main(){
    Room room("Room 1");
    Lamp study {houseCode::A, 0};
    study.turnOn();
    
    room.add(study);
    room.status();

    Lamp bedLamp {houseCode::B, 1};
    room.add(bedLamp);
    room.status();
    room.all_on();
    room.status();

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