// Author: Hector Flores
// Date: 2025-05-14

#include <stdio.h>
#include "motortip.h"
#include "freertos/FreeRTOS.h"

// Motor DC with PWM
#include "driver/gpio.h"
#include "driver/ledc.h"

void motortip_init() {
  ledc_timer_config_t ledc_timer = {
    .speed_mode       = LEDC_MODE,
    .timer_num        = LEDC_TIMER,
    .duty_resolution  = LEDC_DUTY_RES,
    .freq_hz          = LEDC_FREQUENCY,  // Set output frequency at 5 kHz
    .clk_cfg          = LEDC_AUTO_CLK
  };
  ledc_timer_config(&ledc_timer);

  // Prepare and then apply the LEDC PWM channel configuration
  ledc_channel_config_t ledc_channel = {
    .speed_mode     = LEDC_MODE,
    .channel        = LEDC_CHANNEL,
    .timer_sel      = LEDC_TIMER,
    .intr_type      = LEDC_INTR_DISABLE,
    .gpio_num       = LEDC_OUTPUT_IO,
    .duty           = 0, // Set duty to 0%
    .hpoint         = 0
  };
  ledc_channel_config(&ledc_channel);
}

void set_motor_speed(uint8_t speed) {
  ledc_set_duty(LEDC_MODE, LEDC_CHANNEL, speed);
  ledc_update_duty(LEDC_MODE, LEDC_CHANNEL);
}
