#ifndef PSEUDORANDOM_H
#define PSEUDORANDOM_H

#ifdef __cplusplus
extern "C" {
#endif

extern uint32_t pseudorandom_state;
void get_pseudorandom_bytes(void *buf, int len);
#define pseudorandom_set_seed(v) do { pseudorandom_state = (v); } while(0)

#ifdef __cplusplus
}
#endif

#endif
