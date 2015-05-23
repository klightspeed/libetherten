#ifndef EEPROM_H
#define EEPROM_H

#include "config.h"
#include <stdint.h>
#include <avr/eeprom.h>
#include "w5100.h"
#include "dhcp.h"

#ifdef __cplusplus
extern "C" {
#endif

struct eeprom_boot_data {
    uint8_t sig[2];
    uint8_t structlen;
    struct dhcp_ifconfig ifconfig;
    uint8_t usedhcp;
    struct {
        uint32_t epoch;
        uint32_t sec;
    } startup_time;
    char firmware_filename[64];
};

#define EEPROM_BOOT_DATA_START ((void *)0x380)

void load_eeprom_data(struct eeprom_boot_data *eeprom_boot_data);
void save_eeprom_data(struct eeprom_boot_data *eeprom_boot_data);
void init_eeprom_data(struct eeprom_boot_data *eeprom_boot_data);

#ifdef __cplusplus
}
#endif

#endif
