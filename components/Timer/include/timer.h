// Author: Hector Flores
// Date: 2025-04-28

#ifndef TIMER_H
#define TIMER_H

#define TIMER_DIVIDER 80 // 80MHz / 80 = 1MHz

void my_1seg_timer_init(void);
void timer_1seg_isr_handler(void *arg);

#endif
