#ifndef ADC_H
#define ADC_H

#include <stdint.h>

#define ADC_PRESCALER 7

#ifdef __cplusplus
extern "C" {
#endif

uint16_t adc_read(uint8_t channel, uint8_t ref);
void adc_init(void);

#ifdef __cplusplus
}
#endif

#endif
