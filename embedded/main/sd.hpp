#ifndef COFFEE_SD_HPP
#define COFFEE_SD_HPP

#include <Arduino.h>

#include <FS.h>
#include <SD.h>
#include <SPI.h>

#define SD_CS 10
#define SD_MOSI 11
#define SD_SCK 12
#define SD_MISO 13

// ESP32 supports SPI clock up to 80MHz, but it can be unstable
// If SD card read / write is unstable, use a stable one
#define COFFEE_SPI_CLK 80000000
#define COFFEE_SPI_CLK_STABLE 40000000

extern SPIClass sd_spi;

/**
 * @brief Initialize TF card
 * @return SD card initialization success
 */
bool init_sd(void);

/**
 * @brief List all files in a directory
 * @param fs 설명 추가 예정
 * @param dir_name 설명 추가 예정
 * @param level 설명 추가 예정
 */
void list_dir(fs::FS& fs, const char* dir_name, uint8_t level);
#endif
