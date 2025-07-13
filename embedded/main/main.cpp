#include <Arduino.h>

#include "display.hpp"
#include "tests.hpp"

#define COFFEE_BAUD_RATE 115200

extern "C" void app_main(void)
{
    initArduino();
    Serial.begin(COFFEE_BAUD_RATE);

    if(!coffee::init_lcd()) {
        Serial.println("LCD initialization failed");
        
        return;
    }

    // coffee::test1();
    coffee::test2();
}
