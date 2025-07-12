#include "lcd.hpp"

PCA9557 out;

LGFX lcd;

bool init_lcd(void)
{
    // initialize touch driver
    Wire.begin(19, 20);
    out.reset();
    out.setMode(IO_OUTPUT);
    out.setState(IO0, IO_LOW);
    out.setState(IO1, IO_LOW);
    delay(20);
    out.setState(IO0, IO_HIGH);
    delay(100);
    out.setMode(IO1, IO_INPUT);

    // initialize lcd
    if(!lcd.begin())
        return false;

    lcd.fillScreen(TFT_BLACK);
    lcd.setTextSize(3);
    delay(100);

    return true;
}
