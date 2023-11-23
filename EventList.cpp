#include <EventList.h>

namespace Timing{
    EventList::EventList(){}

    bool EventList::add_event(Instant on, Instant off, Room room){
        if (next == std::end(eventlist))
            return false;

        *next = Event {on, off, room};
        ++next;
        return true;
    }

    void EventList::update_time(Instant current_time){
        for (auto& event : eventlist){
            event.do_action(current_time);
        }
    }
}