#include <EventList.h>

namespace Timing{
    EventList::EventList(){}

    bool EventList::add_event(Instant on, Instant off, Room room){
        try{
            eventlist.push_back(std::make_unique<Event>(on, off, room));
        }
        catch (std::exception& e){
            return false;
        }
        return true;
    }

    void EventList::update_time(Instant current_time){
        for (auto& event : eventlist){
            if (event){
                event->do_action(current_time);
            }
        }
    }
}