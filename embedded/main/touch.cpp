#include "touch.hpp"

namespace coffee
{
    TAMC_GT911 touch = TAMC_GT911(COFFEE_GT911_SDA, COFFEE_GT911_SCL, COFFEE_GT911_INT, COFFEE_GT911_RST, max(COFFEE_MAP_X1, COFFEE_MAP_X2), max(COFFEE_MAP_Y1, COFFEE_MAP_Y2));

    bool init_touch(void)
    {
        if(!Wire.begin(COFFEE_GT911_SDA, COFFEE_GT911_SCL))
            return false;

        touch.begin();

        touch.setRotation(COFFEE_GT911_ROTATION);

        return true;
    }

    bool touched(void)
    {
        touch.read();

        if (touch.isTouched) {
            last_x = map(touch.points[0].x, COFFEE_MAP_X1, COFFEE_MAP_X2, 0, lcd.width() - 1);
            last_y = map(touch.points[0].y, COFFEE_MAP_Y1, COFFEE_MAP_Y2, 0, lcd.height() - 1);

            return true;
        } else
            return false;
    }
}
