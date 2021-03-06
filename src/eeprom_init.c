#include "libetherten/eeprom.h"
#include "libetherten/random.h"
#include "libetherten/util.h"

void init_eeprom_data(struct eeprom_boot_data *eeprom_boot_data) {
    if (eeprom_boot_data->sig[0] != 0x55 || 
        eeprom_boot_data->sig[1] != 0xAA || 
	eeprom_boot_data->structlen != sizeof(struct eeprom_boot_data) ||
	eeprom_boot_data->ifconfig.ethconfig.hwaddr.octet[1] == 0xFF ||
	eeprom_boot_data->firmware_filename[0] >= 0x7F ||
	eeprom_boot_data->firmware_filename[0] <= 0x20) {
#ifdef CONFIG_RANDOM_HWADDR
        zero_x_const (eeprom_boot_data, sizeof(struct eeprom_boot_data));
        get_random_bytes(&eeprom_boot_data->ifconfig.ethconfig.hwaddr, 6);
        eeprom_boot_data->ifconfig.ethconfig.hwaddr.octet[0] = 0xFE;
#else
        zero_x_const (eeprom_boot_data, offsetof(struct eeprom_boot_data, ifconfig.ethconfig.hwaddr));
	copy_const_zx_const (&eeprom_boot_data->ifconfig.ethconfig.hwaddr, PSTR("\xDE\xAD\xC0\xDE\xCA\xFE"), 6);
	zero_x_const (&eeprom_boot_data->ifconfig.ethconfig.ipaddr, sizeof(struct eeprom_boot_data) - offsetof(struct eeprom_boot_data, ifconfig.ethconfig.ipaddr));
#endif
        eeprom_boot_data->sig[0] = 0x55;
        eeprom_boot_data->sig[1] = 0xAA;
        eeprom_boot_data->structlen = sizeof(struct eeprom_boot_data);
        eeprom_boot_data->usedhcp = 1;
        copy_const_zx_str_const(eeprom_boot_data->firmware_filename, PSTR(DEFAULT_FW_FILENAME), sizeof(eeprom_boot_data->firmware_filename));
        save_eeprom_data(eeprom_boot_data);
    }
}
