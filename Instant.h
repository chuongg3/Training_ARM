#ifndef INSTANT_H
#define INSTANT_H

#include <cstdint>
#include <utility>

namespace Timing{
    class Instant{
    public:
        Instant() = default;
        Instant(uint8_t Hour, uint8_t Minute);

        std::pair<uint8_t, uint8_t> getHrMin() const;

        bool is_equal(const Instant& rhs);

    private:
        uint8_t hour {0};
        uint8_t minute {0};
    };
}

#endif