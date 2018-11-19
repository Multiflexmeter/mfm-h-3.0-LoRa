#ifndef _SETTINGS_H_
#define _SETTINGS_H_

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
    static void Reset();
private:
    static int eepromTail;
    // E2END defines last address
};

#endif /* end of include guard: _SETTINGS_H_ */
