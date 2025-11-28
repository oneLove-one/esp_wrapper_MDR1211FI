#include "../include/c_timer.hpp"

void Core::Timer::initialize() {
	
				Drivers::Milandr::PeripheralRegistry::enableTimer1Clock();
        
        uint32_t prescaler = ((SYSTEM_CLOCK / DESIRED_FREQUENCY) - 1);
        uint32_t autoReload = (1000 - 1);
        
        auto timer = MDR_TIMER1;	
        MDR_RST_CLK->TIM_CLOCK = 0x01000000;
        timer->CNTRL = 0x00000000;
        timer->CNT = 0x00000000;
        timer->PSG = prescaler;
        timer->ARR = autoReload;
        timer->IE = 0x00000002;
        timer->CNTRL = 0x00000001;
	
}

void Core::Timer::delayMicroseconds(uint32_t microseconds) {
        auto timer = MDR_TIMER1;
        uint32_t startTime = timer->CNT;
        uint32_t elapsedTime = 0;

        while (elapsedTime < microseconds) {
            uint32_t currentTime = timer->CNT;
            
            if (currentTime >= startTime) {
                elapsedTime = currentTime - startTime;
            } else {
                elapsedTime = (0xFFFFFFFF - startTime) + currentTime + 1;
            }
            
            if (elapsedTime > 1000000) {
                break;
            }
        }
}

void Core::Timer::delayMilliseconds(uint32_t milliseconds) {
        for (uint32_t i = 0; i < milliseconds; i++) {
            delayMicroseconds(1000);
        }
}