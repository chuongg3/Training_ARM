#include<Event.h>

namespace Timing{
    Event::Event(Instant onInstant, Instant offInstant, Room Room) : on {onInstant}, off {offInstant}, room {Room}{}

    void Event::do_action(const Instant& currentInstant){
        if (on.is_equal(currentInstant)){
            room.all_on();
        }
        else if (off.is_equal(currentInstant)){
            room.all_off();
        }
    }
}

