#ifndef _SETTINGS_H_
#define _SETTINGS_H_

#include <Arduino.h>

#define EEPROM_END E2END

/**
 * Manages the eeprom with settings
 */
class Settings {
public:
    /**
     * Reserve x amount of space in the EEPROM
     * @param  size The amount of bytes to reserve
     * @return a pointer to starting point of the reserves space
     */
    static int ReserveSpace(int size);
    /**
     * Resets the eepromTail to zero, essentially restarting reservation and
     * losing all previous reservations.
     */
    static void Reset();
private:
    /** The end address of used space */
    static int eepromTail;
};

#endif /* end of include guard: _SETTINGS_H_ */
