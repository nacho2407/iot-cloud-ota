#ifndef COFFEE_TESTS_HPP
#define COFFEE_TESTS_HPP

#include <Arduino.h>

#include "display.hpp"

namespace coffee
{
    /**
     * @brief 시리얼 통신을 테스트합니다
     * 
     *        tests serial communication
     */
    void test1(void);

    /**
     * @brief LCD 출력을 테스트합니다
     * 
     *        tests LCD output
     */
    void test2(void);
}
#endif
