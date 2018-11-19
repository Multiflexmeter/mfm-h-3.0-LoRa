#include "Settings.h"

int Settings::eepromTail = 0;

void Settings::Reset() {
    Settings::eepromTail = 0;
}

int Settings::ReserveSpace(int size) {
    Settings::eepromTail += size;
    if (Settings::eepromTail > EEPROM_END) {
        Settings::eepromTail = EEPROM_END;
        return -1;
    }
    return Settings::eepromTail - size;
}
