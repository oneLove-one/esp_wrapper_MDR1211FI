#include "../include/c_systemclock.hpp"

void Core::SystemClock::initialize() {
        auto rcc = MDR_RST_CLK;
        
        //HSE
        rcc->HS_CONTROL |= (1 << RST_CLK_HS_CONTROL_HSE_ON_Pos);
        rcc->HS_CONTROL &= ~(1 << RST_CLK_HS_CONTROL_HSE_BYP_Pos);

        //HSE
        uint32_t timeout = 100000;
        while ((RST_CLK_HSEstatus() == ERROR) && (timeout-- > 0)) {}
        
        if (timeout == 0) {
            while (true) {} 
        }

        //CPU clock
        rcc->CPU_CLOCK |= (0b11 << RST_CLK_CPU_CLOCK_CPU_C1_SEL_Pos);
        rcc->CPU_CLOCK &= ~(0b1 << RST_CLK_CPU_CLOCK_CPU_C2_SEL_Pos);
        rcc->CPU_CLOCK |= (0b1001 << RST_CLK_CPU_CLOCK_CPU_C1_SEL_Pos);
        rcc->CPU_CLOCK |= (0b01 << RST_CLK_CPU_CLOCK_HCLK_SEL_Pos);
    }

