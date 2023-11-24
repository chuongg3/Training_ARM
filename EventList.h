#ifndef EVENTLIST_H
#define EVENTLIST_H

#include <array>
#include <Event.h>
#include <memory>

namespace Timing{
    class EventList{
    public:
        EventList();

        bool add_event(Instant on, Instant off, Room room);
        void update_time(Instant current_time);
    private:
        std::array<std::unique_ptr<Event>, 16> eventlist {};

        std::array<std::unique_ptr<Event>, 16>::iterator next{std::begin(eventlist)};
    };
}

#endif