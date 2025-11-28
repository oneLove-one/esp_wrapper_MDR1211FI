#include "../include/c_gpio.hpp"

void Core::GPIO::configureAsOutput() {
	
        port_->OE |= pinMask_;
        port_->ANALOG |= pinMask_;
        port_->PWR |= (1 << (pinNumber_ * 2));
        port_->FUNC &= ~pinMask_;
        port_->PULL &= ~(0x1 << 6); // No pull
        port_->PD &= ~pinMask_;
        port_->PD &= ~(pinMask_ << 16);
        port_->GFEN &= ~pinMask_;
	
}

void Core::GPIO::configureAsInput(PinPull pull) {
        port_->OE &= ~pinMask_;
        port_->ANALOG |= pinMask_;
        port_->PWR |= (1 << (pinNumber_ * 2));
        port_->FUNC &= ~pinMask_;
        
        if (pull == PinPull::PullUp) {
            port_->PULL |= (0x1 << 6);
        } else {
            port_->PULL &= ~(0x1 << 6);
        }
        
        port_->PD |= ((pinMask_) << 16);
        port_->GFEN |= pinMask_;
}