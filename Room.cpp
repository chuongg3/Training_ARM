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

    bool Room::add(Switchable& newModule){
        if (next == std::end(devices))
            return false;
        *next = &newModule;
        ++next;
        return true;
    }

    void Room::all_on(){
        for (auto& module : devices){
            if (module){
                module->turnOn();
            }
        }
    }

    void Room::all_off(){
        for (auto& module : devices){
            if (module){
                module->turnOff();
            }
        }
    }

    void Room::set_name(std::string_view new_name){
        name = new_name;
    }

    unsigned Room::count_module_state(bool state) const{
        unsigned count = 0;
        for (auto* module : devices){
            if (module){
                count++;
            }
        }
        return count;
    }

    void Room::status() const{
        if (!name.empty()){
            std::cout << "In room <" << name << ">";
        }
        std::cout << " there are currently " << std::to_string(count_module_state(true)) << " modules on and " << std::to_string(count_module_state(false)) << " modules off.\n";
    }
}