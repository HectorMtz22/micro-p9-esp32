// Author: Hector Flores
// Date: 2025-05-13

#ifndef MOTORTIP_H
#define MOTORTIP_H

#define LEDC_TIMER              LEDC_TIMER_0
#define LEDC_MODE               LEDC_LOW_SPEED_MODE
#define LEDC_OUTPUT_IO          (2) // Define the output GPIO
#define LEDC_CHANNEL            LEDC_CHANNEL_0
#define LEDC_DUTY_RES           LEDC_TIMER_8_BIT // Set duty resolution to 8 bits from 0 to 255
#define LEDC_FREQUENCY          (5000) // Frequency in Hertz. Set frequency at 5 kHz


void motortip_init();
void set_motor_speed(uint8_t speed);

#endif
