#include <Arduino.h>

#include <Wire.h>

#include "lcd.hpp"
#include "tests.hpp"

#define COFFEE_BAUD_RATE 115200

extern "C" void app_main(void)
{
    initArduino();
    Serial.begin(COFFEE_BAUD_RATE);

    if(!init_lcd()) {
        Serial.println("LCD initialization failed");
        
        return;
    }

    // test1();
    test2();
}
