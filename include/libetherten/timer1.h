#ifndef TIMER1_H
#define TIMER1_H

#ifdef __cplusplus
extern "C" {
#endif

volatile extern uint32_t time_epoch;
volatile extern uint32_t time_sec;
volatile extern uint16_t time_ms;
volatile extern uint16_t time_tick;

#ifdef __cplusplus
}
#endif

#endif
