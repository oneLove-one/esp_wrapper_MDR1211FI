#pragma once
#include "types.hpp"
#include "c_peripheralregistry.hpp"
#include "c_pindefinitions.hpp"

namespace Core {
class GPIO {
private:
    decltype(MDR_PORTB) port_;
    uint32_t pinNumber_;
    uint32_t pinMask_;
    
public:
    GPIO(decltype(MDR_PORTB) port, const Drivers::Milandr::Pins::Pin& pin) 
        : port_(port), pinNumber_(pin.number), pinMask_(pin.mask) {}
    
    void configureAsOutput();
    void configureAsInput(PinPull pull = PinPull::None);
    
    void set() {
        port_->RXTX |= pinMask_;
    }
    
    void clear() {
        port_->RXTX &= ~pinMask_;
    }
    
    void toggle() {
        port_->RXTX ^= pinMask_;
    }
    
    PinState read() {
        return (port_->RXTX & pinMask_) ? PinState::High : PinState::Low;
    }
    
    // Fluent interface
    GPIO& asOutput() { configureAsOutput(); return *this; }
    GPIO& asInput(PinPull pull = PinPull::None) { configureAsInput(pull); return *this; }
    GPIO& high() { set(); return *this; }
    GPIO& low() { clear(); return *this; }
};
} // namespace Core