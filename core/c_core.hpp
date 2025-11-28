#pragma once
#include "../include/c_gpio.hpp"
#include "../include/c_timer.hpp"
#include "../include/c_systemclock.hpp"
#include "../include/c_pindefinitions.hpp"

namespace Core {
class C_Core {
private:
    Core::GPIO statusLed_;
    Core::GPIO inputButton_;
    bool isRunning_;
    
public:
    C_Core() 
        : statusLed_(MDR_PORTB, 
                     Drivers::Milandr::Pins::PB7)
        , inputButton_(MDR_PORTB, 
                       Drivers::Milandr::Pins::PB6)
        , isRunning_(true) {}
    
    void initialize();
    void run();
    void stop();
};
} // namespace Core