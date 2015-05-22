#ifndef PORTS_H_
#define PORTS_H_

#include <avr/io.h>

#define PORT(pin) (((pin) < 8) ? PORTD : ((pin) < 16) ? PORTB : PORTC)
#define PIN(pin) (((pin) < 8) ? PIND : ((pin) < 16) ? PINB : PINC)
#define DDR(pin) (((pin) < 8) ? DDRD : ((pin) < 16) ? DDRB : DDRC)
#define PBIT(pin) (((pin) < 8) ? (pin) : ((pin) < 16) ? (pin) - 8 : (pin) - 16)
#define PORT_SET(pin) (PORT(pin) |= _BV(PBIT(pin)))
#define PORT_CLR(pin) (PORT(pin) &= ~_BV(PBIT(pin)))
#define PORT_TOGGLE(pin) (PIN(pin) |= _BV(PBIT(pin)))
#define DDR_OUT(pin) (DDR(pin) |= _BV(PBIT(pin)))
#define DDR_IN(pin) (DDR(pin) &= ~_BV(PBIT(pin)))
#define PIN_VAL(pin) (!!(PIN(pin) & _BV(PBIT(pin))))

#endif /* PORTS_H_ */