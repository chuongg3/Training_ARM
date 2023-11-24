#ifndef EVENTLIST_H
#define EVENTLIST_H

#include <array>
#include <Event.h>
#include <memory>
#include <vector>

namespace Timing{
    class EventList{
    public:
        EventList();

        bool add_event(Instant on, Instant off, Room room);
        void update_time(Instant current_time);
    private:
        using Container = std::vector<std::unique_ptr<Event>>;
        Container eventlist {};
    };
}

#endif