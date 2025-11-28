#pragma once
#include <cstdint>

namespace Core {
	
    enum class PinState {
        Low = 0,
        High = 1
    };

    enum class PinDirection {
        Input,
        Output,
        Alternate
    };

    enum class PinPull {
        None,
        PullUp,
        PullDown
    };
		
}