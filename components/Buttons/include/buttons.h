// Author : Hector Flores
// Date : 2025-04-01

// Description : Header file for button handling
#ifndef BUTTONS_H
#define BUTTONS_H

#define BTNS_INCREMENT GPIO_NUM_4
#define BTNS_DECREMENT GPIO_NUM_2

void btns_init(void);

// ISR functions
void btns_isr_handler_more(void *arg);
void btns_isr_handler_less(void *arg);

#endif // BUTTONS_H
