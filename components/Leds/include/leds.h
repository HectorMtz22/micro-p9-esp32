
#ifndef LEDS_H
#define LEDS_H

#define LEDS_1 GPIO_NUM_14
#define LEDS_2 GPIO_NUM_27
#define LEDS_3 GPIO_NUM_26
#define LEDS_4 GPIO_NUM_25
#define LEDS_5 GPIO_NUM_33
#define LEDS_6 GPIO_NUM_32

void leds_init(void);
void leds_set(uint8_t);
void leds_test(void);

#endif