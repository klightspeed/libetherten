#ifndef WDT_H
#define WDT_H

#ifdef __cplusplus
extern "C" {
#endif

extern void (*wdt_int_vector)(void);
volatile extern uint16_t wdt_tick;
volatile extern uint8_t wdt_triggered;
void wdt_get_random_bytes(void *buf, int len);
void wdt_reset_mcu(void) __attribute__((noreturn));

#ifdef __cplusplus
}
#endif

#endif
