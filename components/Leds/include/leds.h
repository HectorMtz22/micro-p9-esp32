// Author: Hector Flores
// Date: 2025-04-07

#ifndef LEDS_H
#define LEDS_H

#define LEDS_1 GPIO_NUM_4

#define TEST_DELAY 200

void leds_init(void);
void leds_set(uint8_t);
void leds_test(void *);

#endif
