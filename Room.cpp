#include <Room.h>
#include <iostream>

namespace Home{
    Room::Room(){}
    Room::Room(std::string_view Name) : name {Name}{
        std::cout << "Created room (" << Name << ")\n";
    }
    Room::~Room(){
        if (!name.empty())
            std::cout << "Deleting room <" << name << ">\n";
        else 
            std::cout << "Deleting room\n";
    }

    bool Room::add(Lamp& newLamp){
        for (auto& lamp : devices){
            auto [HouseCode, UnitCode] = lamp.id();
            if (HouseCode == houseCode::INVALID){
                lamp = newLamp;
                return true;
            }
        }
        return false;
    }

    void Room::all_on(){
        for (auto& lamp : devices){
            auto [HouseCode, UnitCode] = lamp.id();
            if (HouseCode != houseCode::INVALID){
                lamp.turnOn();
            }
        }
    }

    void Room::all_off(){
        for (auto& lamp : devices){
            auto [HouseCode, UnitCode] = lamp.id();
            if (HouseCode != houseCode::INVALID){
                lamp.turnOff();
            }
        }
    }

    void Room::set_name(std::string_view new_name){
        name = new_name;
    }

    unsigned Room::count_lamp_state(bool state) const{
        unsigned count = 0;
        for (auto& lamp : devices){
            auto [HouseCode, UnitCode] = lamp.id();
            if (lamp.is_on() == state && HouseCode != houseCode::INVALID){
                count++;
            }
        }
        return count;
    }

    void Room::status() const{
        if (!name.empty()){
            std::cout << "In room <" << name << ">";
        }
        std::cout << " there are currently " << std::to_string(count_lamp_state(true)) << " lamps on and " << std::to_string(count_lamp_state(false)) << " lamps off.\n";
    }
}