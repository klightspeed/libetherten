#include "libetherten/eeprom.h"
#include "libetherten/util.h"

struct eeprom_boot_data eeprom_boot_data;

void load_eeprom_data(void) {
    eeprom_read_block(&eeprom_boot_data, EEPROM_BOOT_DATA_START, sizeof(eeprom_boot_data));
}

void save_eeprom_data(void) {
    eeprom_update_block(&eeprom_boot_data, EEPROM_BOOT_DATA_START, sizeof(eeprom_boot_data));
}


