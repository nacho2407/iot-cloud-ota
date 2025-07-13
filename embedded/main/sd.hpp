#ifndef COFFEE_SD_HPP
#define COFFEE_SD_HPP

#include <Arduino.h>

#include <FS.h>
#include <SD.h>
#include <SPI.h>

#define COFFEE_SD_CS 10
#define COFFEE_SD_MOSI 11
#define COFFEE_SD_SCK 12
#define COFFEE_SD_MISO 13

// ESP32 supports SPI clock up to 80MHz, but it can be unstable
// if SD card read / write is unstable, change this value to 40000000
#define COFFEE_SPI_CLK 80000000

namespace coffee
{
    /**
     * @brief initialize SD card
     * @return SD card initialization success
     */
    bool init_sd(void);

    /**
     * @brief list all files in a directory
     * @param fs file system to be read
     * @param dir directory in the file system to be read
     * @param depth depth in directories
     */
    void list_dir(fs::FS& fs, const char* dir, uint8_t depth);

    /**
     * @brief list all files in file system
     * @param fs file system to be read
     */
    void list_all(fs::FS& fs);
}
#endif
