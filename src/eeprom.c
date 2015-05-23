#include "libetherten/eeprom.h"
#include "libetherten/util.h"

void load_eeprom_data(struct eeprom_boot_data *eeprom_boot_data) {
    eeprom_read_block(eeprom_boot_data, EEPROM_BOOT_DATA_START, sizeof(struct eeprom_boot_data));
}

void save_eeprom_data(struct eeprom_boot_data *eeprom_boot_data) {
    eeprom_update_block(&eeprom_boot_data, EEPROM_BOOT_DATA_START, sizeof(struct eeprom_boot_data));
}


