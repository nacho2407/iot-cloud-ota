#include "sd.hpp"

namespace coffee
{
    bool init_sd(void)
    {
        SPIClass spi_bus;

        spi_bus.begin(COFFEE_SD_SCK, COFFEE_SD_MISO, COFFEE_SD_MOSI, SD_CS);

        if (!SD.begin(SD_CS, spi_bus, COFFEE_SPI_CLK))
            return false;

        return true;
    }

    void list_dir(fs::FS& fs, const char* dir, uint8_t depth)
    {
        File root = fs.open(dir);

        if (!root || !root.isDirectory()) {
            Serial.printf("%*sfalied: not a directory, or cannot be opened(%s)\n", depth * 4, "", dir);

            return;
        }

        File file = root.openNextFile();

        while (file) {
            const char* file_name = file.name();
            
            Serial.printf("%*s", depth * 4, "");

            if (file.isDirectory()) {
                Serial.printf("dir: %s/\n", file_name);

                list_dir(fs, file.path(), depth + 1);
            } else
                Serial.printf("file: %s(%dB)\n", file_name, file.size());

            file = root.openNextFile();
        }
    }

    void list_all(fs::FS& fs)
    {
        Serial.println("root: /\n");
        
        list_dir(fs, "/", 0);
    }
}
