#include <Arduino.h>

#include <driver.hpp>

#include <lvgl.h>
#include <demos/lv_demos.h>
#include <examples/lv_examples.h>

#define COFFEE_BAUD_RATE 115200

extern "C" void app_main(void)
{
    initArduino();
    Serial.begin((unsigned long) COFFEE_BAUD_RATE);

    coffee::init_driver();

    lv_demo_widgets();

    while (true)
    {
        lv_timer_handler(); /* let the GUI do its work */
        delay(10);
    }
}
