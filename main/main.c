#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/gpio.h" 
#include "display.h"

#define TIME_DELAY 300

#define BTNS_INCREMENT GPIO_NUM_2
#define BTNS_DECREMENT GPIO_NUM_15

void btns_init(void);
int btns_debounce(void);

uint8_t prev_state_btn = 0;
uint8_t actual_state_btn = 0;

void app_main() {
  disp_init();
  btns_init();
  int state = 0;
  while (true) {
    disp_show(state);
    if (btns_debounce()) {
      if (++state >= 0x0F) state = 0x0F;
    }
    if (gpio_get_level(BTNS_DECREMENT)) {
      if (--state <= 0) state = 0;
      disp_show(state);
      vTaskDelay(TIME_DELAY / portTICK_PERIOD_MS);
    }

  }
}

void btns_init(void) {
  gpio_set_direction(BTNS_INCREMENT, GPIO_MODE_INPUT);
  gpio_set_direction(BTNS_DECREMENT, GPIO_MODE_INPUT);
  return;
}

int btns_debounce(void) {
  vTaskDelay(10 / portTICK_PERIOD_MS);
  prev_state_btn = actual_state_btn;
  actual_state_btn = gpio_get_level(BTNS_INCREMENT);

  return !prev_state_btn && actual_state_btn;
}