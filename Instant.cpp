#include <Instant.h>

namespace Timing{
    Instant::Instant(uint8_t Hour, uint8_t Minute){
        if ((00 <= Hour <= 23) && (0 <= Minute < 60)){
            this->hour = Hour;
            this->minute = Minute;
        }
    }

    std::pair<uint8_t, uint8_t> Instant::getHrMin() const{
        return std::make_pair(this->hour, this->minute);
    }

    bool Instant::is_equal(const Instant& rhs){
        auto [rhsHour, rhsMinute] = rhs.getHrMin();
        return (this->hour == rhsHour) && (this->minute == rhsMinute);
    }
}