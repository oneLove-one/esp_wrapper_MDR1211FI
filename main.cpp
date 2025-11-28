#include "core/c_core.hpp"

int main() {
    Core::C_Core app;
    
    app.initialize();
    app.run();
    
    return 0;
}