#ifndef COFFEE_DISPLAY_HPP
#define COFFEE_DISPLAY_HPP

#include <driver/i2c.h>

#include <Arduino.h>
#include <Wire.h>

#define LGFX_USE_V1
#include <LovyanGFX.hpp>
#include <lgfx/v1/platforms/esp32s3/Panel_RGB.hpp>
#include <lgfx/v1/platforms/esp32s3/Bus_RGB.hpp>

#include <lvgl.h>

#include <PCA9557.h>

#define COFFEE_DISPLAY_WIDTH 800
#define COFFEE_DISPLAY_HEIGHT 480

#define COFFEE_BACKLIGHT 2

namespace coffee
{
    class LCD: public lgfx::LGFX_Device
    {
    public:
        lgfx::Panel_RGB _panel;

        lgfx::Bus_RGB _bus;

        LCD(void);
    };

    extern LCD lcd;

    /**
     * @brief LCD를 초기화합니다
     * 
     *        initializes the LCD
     * 
     * @return LCD 초기화 성공 여부
     * 
     *         LCD initialization success
     */
    bool init_lcd(void);

    /**
     * @brief 백라이트를 켭니다
     * 
     *        turns on the backlight
     */
    void turn_on_bl(void);
}
#endif
