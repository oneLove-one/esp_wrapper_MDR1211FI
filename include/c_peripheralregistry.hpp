#pragma once
#include "MDR32FxQI_port.h"
#include "MDR32FxQI_rst_clk.h"
#include "MDR32FxQI_timer.h"

namespace Drivers::Milandr {
	
    class PeripheralRegistry {
    public:
			
        static void enablePortBClock();
        static void enableTimer1Clock();
		
    };
		
}