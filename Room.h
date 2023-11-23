#ifndef ROOM_H
#define ROOM_H

#include <array>
#include <string_view>
#include <Module.h>

namespace Home{
    class Room{
        public:
            Room();
            Room(std::string_view name);
            ~Room();

            bool add(Module& module);
            void all_on();
            void all_off();
            void set_name(std::string_view new_name);

            unsigned count_module_state(bool state) const;
            void status() const;

        private:
            std::string name {};
            std::array<Module* , 4> devices {};

            std::array<Module* , 4>::iterator next = std::begin(devices);
    };
}




#endif