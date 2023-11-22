#ifndef ROOM_H
#define ROOM_H

#include <array>
#include <Lamp.h>
#include <string_view>

namespace Home{
    class Room{
        public:
            Room();
            Room(std::string_view name);
            ~Room();

            bool add(Lamp& lamp);
            void all_on();
            void all_off();
            void set_name(std::string_view new_name);

            unsigned count_lamp_state(bool state) const;
            void status() const;

        private:
            std::string name {};
            std::array<Lamp, 4> devices {};
    };
}




#endif