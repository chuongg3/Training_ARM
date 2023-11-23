#ifndef SWITCHABLE_H
#define SWITCHABLE_H

namespace Home{
    class Switchable{
    public:
        virtual void turnOn() = 0;
        virtual void turnOff() = 0;
        virtual bool is_on() const = 0;

        virtual ~Switchable() = default;
    };
}

#endif