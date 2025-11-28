#pragma once
#include <cstdint>
#include "c_peripheralregistry.hpp"
#include "MDR32FxQI_rst_clk.h"

namespace Core {
class SystemClock {
public:
    static void initialize();
};
} // namespace Core