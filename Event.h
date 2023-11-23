#ifndef EVENT_H
#define EVENT_H

#include <Instant.h>
#include <Room.h>

using Home::Room;

namespace Timing{
    class Event{
    public:
        Event() = default;
        Event(Instant onInstant, Instant offInstant, Room Room);

        void do_action(const Instant& currentInstant);


    private:
        Instant on {};
        Instant off {};
        Room room {};
    };
}

#endif