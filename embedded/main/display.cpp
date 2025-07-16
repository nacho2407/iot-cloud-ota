#include "display.hpp"

namespace coffee
{
    LCD lcd;

    // TODO: 아래 정적 전역 변수들 이름 바꾸기
    // 참고로 lv_color_t는 lv_disp_draw_buf_t에 저장되는 실제 픽셀 값 버퍼이므로 PSRAM에 할당
    static lv_color_t* disp_draw_buf;
    static lv_disp_draw_buf_t draw_buf;

    static lv_disp_drv_t disp_drv;

    LCD::LCD(void)
    {
        {
            auto cfg = _panel.config();
            cfg.memory_width = COFFEE_DISPLAY_WIDTH;
            cfg.memory_height = COFFEE_DISPLAY_HEIGHT;
            cfg.panel_width = COFFEE_DISPLAY_WIDTH;
            cfg.panel_height = COFFEE_DISPLAY_HEIGHT;
            cfg.offset_x = 0;
            cfg.offset_y = 0;
            _panel.config(cfg);
        }

        {
            auto cfg = _bus.config();
            cfg.panel = &_panel;

            cfg.pin_d0 = GPIO_NUM_15;
            cfg.pin_d1 = GPIO_NUM_7;
            cfg.pin_d2 = GPIO_NUM_6;
            cfg.pin_d3 = GPIO_NUM_5;
            cfg.pin_d4 = GPIO_NUM_4;

            cfg.pin_d5 = GPIO_NUM_9;
            cfg.pin_d6 = GPIO_NUM_46;
            cfg.pin_d7 = GPIO_NUM_3;
            cfg.pin_d8 = GPIO_NUM_8;
            cfg.pin_d9 = GPIO_NUM_16;
            cfg.pin_d10 = GPIO_NUM_1;

            cfg.pin_d11 = GPIO_NUM_14;
            cfg.pin_d12 = GPIO_NUM_21;
            cfg.pin_d13 = GPIO_NUM_47;
            cfg.pin_d14 = GPIO_NUM_48;
            cfg.pin_d15 = GPIO_NUM_45;

            cfg.pin_henable = GPIO_NUM_41;
            cfg.pin_vsync = GPIO_NUM_40;
            cfg.pin_hsync = GPIO_NUM_39;
            cfg.pin_pclk = GPIO_NUM_0;
            cfg.freq_write = 15000000;

            cfg.hsync_polarity    = 0;
            cfg.hsync_front_porch = 40;
            cfg.hsync_pulse_width = 48;
            cfg.hsync_back_porch  = 40;
            
            cfg.vsync_polarity    = 0;
            cfg.vsync_front_porch = 1;
            cfg.vsync_pulse_width = 31;
            cfg.vsync_back_porch  = 13;

            cfg.pclk_active_neg = 1;
            cfg.de_idle_high = 0;
            cfg.pclk_idle_high = 0;

            _bus.config(cfg);
        }
            
        _panel.setBus(&_bus);

        setPanel(&_panel);
    }

    bool init_lcd(void)
    {
        static PCA9557 pca9557;

        // initialize pca9557 driver
        Wire.begin(19, 20);
        pca9557.reset();
        pca9557.setMode(IO_OUTPUT);
        pca9557.setState(IO0, IO_LOW);
        pca9557.setState(IO1, IO_LOW);
        delay(20);
        pca9557.setState(IO0, IO_HIGH);
        delay(100);
        pca9557.setMode(IO1, IO_INPUT);

        // initialize lcd
        if (!lcd.begin())
            return false;

        lcd.fillScreen(TFT_BLACK);
        lcd.setTextSize(3);
        delay(100);

        return true;
    }

    void turn_on_bl(void)
    {
        ledcSetup(1, 300, 8);

        ledcAttachPin(COFFEE_BACKLIGHT, 1);

        // 두 번째 매개변수를 수정하여 화면 밝기를 조절할 수 있습니다(0-255)
        // Screen brightness can be modified by adjusting second parameter(0-255)
        ledcWrite(1, 0);

        pinMode(COFFEE_BACKLIGHT, OUTPUT);

        digitalWrite(COFFEE_BACKLIGHT, LOW);
        delay(500);

        digitalWrite(COFFEE_BACKLIGHT, HIGH);

        lcd.fillScreen(TFT_BLACK);
    }
}
