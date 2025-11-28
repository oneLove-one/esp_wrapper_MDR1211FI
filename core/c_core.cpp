#include "c_core.hpp"

void Core::C_Core::initialize() {
	Core::SystemClock::initialize();
        
  Drivers::Milandr::PeripheralRegistry::enablePortBClock();
  statusLed_.asOutput().low();
  inputButton_.asInput(Core::PinPull::PullUp);
						
  Core::Timer::initialize();
}

void Core::C_Core::run() {
	
	while (isRunning_) {
					
            statusLed_.high();
            Core::Timer::delayMilliseconds(5000);
            
            statusLed_.low();
            Core::Timer::delayMilliseconds(5000);

	}
	
}

void Core::C_Core::stop() {
	isRunning_ = false;
  statusLed_.low();
}