#pragma once
#include <stdint.h>

namespace Drivers::Milandr::Pins {
    struct Pin {
        uint32_t number;
        uint32_t mask;
        
        constexpr Pin(uint32_t pinNum) : number(pinNum), mask(1u << pinNum) {}
    };
    
    // PB6 PB7 
    constexpr Pin PB6{6};
    constexpr Pin PB7{7};
}