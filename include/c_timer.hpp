#pragma once
#include <cstdint>
#include "c_peripheralregistry.hpp"

namespace Core {
class Timer {
private:
	
    static constexpr uint32_t SYSTEM_CLOCK = 4000000UL;
    static constexpr uint32_t DESIRED_FREQUENCY = 1000000UL;
    
public:
	
    static void initialize();
    static void delayMicroseconds(uint32_t microseconds);
    static void delayMilliseconds(uint32_t milliseconds);

};
} // namespace Core