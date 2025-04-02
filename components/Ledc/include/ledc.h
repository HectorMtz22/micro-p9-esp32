// Author : Hector Flores
// Date : 2025-04-01

#ifndef LEDC_H
#define LEDC_H

#define LEDC_TIMER              LEDC_TIMER_0
#define LEDC_MODE               LEDC_LOW_SPEED_MODE
#define LEDC_OUTPUT_IO          (4) // Define the output GPIO
#define LEDC_CHANNEL            LEDC_CHANNEL_0
#define LEDC_DUTY_RES           LEDC_TIMER_4_BIT // Set duty resolution to 4 bits from 0 to 0x0F 
#define LEDC_FREQUENCY          (5000) // Frequency in Hertz. Set frequency at 5 kHz

void ledc_init();
void ledc_update(int);

#endif