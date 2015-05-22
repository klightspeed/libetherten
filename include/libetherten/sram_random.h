#ifndef SRAM_RANDOM_H
#define SRAM_RANDOM_H

#ifdef __cplusplus
extern "C" {
#endif

extern uint32_t sram_random_seed;
#define sram_get_random_seed() (sram_random_seed)

#ifdef __cplusplus
}
#endif

#endif
