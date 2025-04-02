// Author : Hector Flores
// Date : 2025-04-01

// Description : Header file for button handling
#ifndef BUTTONS_H
#define BUTTONS_H

#define BTNS_INCREMENT GPIO_NUM_2
#define BTNS_DECREMENT GPIO_NUM_15

void btns_init(void);
int btns_increment_debounce(void);
int btns_decrement(void);

#endif // BUTTONS_H
