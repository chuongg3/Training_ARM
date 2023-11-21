#ifndef DEVICE_H
#define DEVICE_H

#include <cstdint>


enum class houseCode : std::uint8_t {
    INVALID, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O
};

static const char* HouseName = "~ABCDEFGHIJKLMNO";

struct Device{
    houseCode HouseCode;
    short UnitCode;
};

#endif // DEVICE_H