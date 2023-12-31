#include <iostream>
#include <array>
#include <Lamp.h>
#include <Room.h>
#include <Instant.h>
#include <Event.h>
#include <EventList.h>
#include <Named_lamp.h>
#include <Appliance.h>

// #define PART_1
#define PART_2
#define PART_3
#define PART_4

using Home::Lamp;
using Home::Room;

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
    Home::Named_lamp desk_lamp {"Desk", houseCode::A, 2 };
    Home::Named_lamp standard_lamp {"Standard", houseCode::A, 3 };
    Home::Named_lamp bedside_lamp {"Bedside", houseCode::B, 1 };
    Home::Appliance bedside_appliance {houseCode::B, 1};
    Home::Room lounge { };
    desk_lamp.turnOn();
    lounge.add(desk_lamp);
    
    lounge.add(standard_lamp);
    
    Home::Room bedroom { };
    
    bedroom.add(bedside_lamp);
    
    
    bedroom.add(bedside_appliance);
    bedside_appliance.turnOn();

    Timing::EventList events { };
    events.add_event(Timing::Instant { 00, 01 }, Timing::Instant { 00, 10 }, lounge);
    events.add_event(Timing::Instant { 00, 05 }, Timing::Instant { 00, 10 }, bedroom);
    events.update_time(Timing::Instant {00,00});
    events.update_time(Timing::Instant {00,01});
    events.update_time(Timing::Instant {00,03});
    events.update_time(Timing::Instant {00,05});
    events.update_time(Timing::Instant {00,10});
}