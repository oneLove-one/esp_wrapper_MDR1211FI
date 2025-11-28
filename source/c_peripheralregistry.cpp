#include "../include/c_peripheralregistry.hpp"

void Drivers::Milandr::PeripheralRegistry::enablePortBClock() {
	MDR_RST_CLK->PER_CLOCK |= (1 << 22);
}

void Drivers::Milandr::PeripheralRegistry::enableTimer1Clock() {
	MDR_RST_CLK->PER_CLOCK |= (1 << 14);
}

