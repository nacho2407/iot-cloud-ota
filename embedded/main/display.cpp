#include "display.hpp"

coffee::LCD lcd;

bool coffee::init_lcd(void)
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
    if(!lcd.begin())
        return false;

    lcd.fillScreen(TFT_BLACK);
    lcd.setTextSize(3);
    delay(100);

    return true;
}
