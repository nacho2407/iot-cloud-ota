#ifndef COFFEE_TOUCH_HPP
#define COFFEE_TOUCH_HPP

#include <Arduino.h>
#include <Wire.h>

#include <TAMC_GT911.h>

#include "display.hpp"

#define COFFEE_GT911
#define COFFEE_GT911_SCL 20
#define COFFEE_GT911_SDA 19
#define COFFEE_GT911_INT 3
#define COFFEE_GT911_RST 4
#define COFFEE_GT911_ROTATION ROTATION_NORMAL
#define COFFEE_MAP_X1 800
#define COFFEE_MAP_X2 0
#define COFFEE_MAP_Y1 480
#define COFFEE_MAP_Y2 0

namespace coffee
{
    extern TAMC_GT911 touch;

    int last_x = 0;
    int last_y = 0;

    /**
     * @brief 터치 스크린을 초기화합니다
     * 
     *        initializes the touch screen
     * 
     * @return 터치 스크린 초기화 성공 여부
     * 
     *         touch screen initialization success
     */
    bool init_touch(void);

    /**
     * @brief 터치를 감지하면 마지막으로 터치된 위치를 last_x와 last_y에 저장합니다
     * 
     *        detects touch and stores the last touched position in last_x and last_y
     * 
     * @return 터치 감지 여부
     * 
     *         Whether touch is detected
     */
    bool touched(void);
}
#endif
