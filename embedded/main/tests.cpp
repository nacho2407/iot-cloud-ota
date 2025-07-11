#include "tests.hpp"

void test1(void)
{
    Serial.println("Hello, world!");
}

void test2(void)
{
    lcd.fillScreen(TFT_BLUE);
    delay(1000);

    lcd.fillScreen(TFT_YELLOW);
    delay(1000);

    lcd.fillScreen(TFT_GREEN);
    delay(1000);

    lcd.fillScreen(TFT_WHITE);
    delay(1000);

    lcd.fillScreen(TFT_BLACK);

    lcd.fillCircle(100, 100, 50, TFT_YELLOW);

    lcd.setCursor((int32_t) screen_width / 2, (int32_t) screen_height / 2);
    lcd.print("Hello, world!");

    Serial.println("Hi, LCD!");
}