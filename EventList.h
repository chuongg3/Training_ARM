#ifndef EVENTLIST_H
#define EVENTLIST_H

#include <array>
#include <Event.h>

namespace Timing{
    class EventList{
    public:
        EventList();

        bool add_event(Instant on, Instant off, Room room);
        void update_time(Instant current_time);
    private:
        std::array<Event, 16> eventlist;

        std::array<Event, 16>::iterator next{std::begin(eventlist)};
    };
}

#endif