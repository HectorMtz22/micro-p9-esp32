#include "buttons.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

uint8_t prev_state_btn = 0;
uint8_t actual_state_btn = 0;


void btns_init(void) {
  gpio_set_direction(BTNS_INCREMENT, GPIO_MODE_INPUT);
  gpio_set_direction(BTNS_DECREMENT, GPIO_MODE_INPUT);

  // Configure GPIOs as interrupts
  gpio_set_intr_type(BTNS_INCREMENT, GPIO_INTR_HIGH_LEVEL); // Rising edge
  gpio_set_intr_type(BTNS_DECREMENT, GPIO_INTR_HIGH_LEVEL); // Rising edge
  return;
}

int btns_increment_debounce(void) {
  vTaskDelay(10 / portTICK_PERIOD_MS);
  prev_state_btn = actual_state_btn;
  actual_state_btn = gpio_get_level(BTNS_INCREMENT);

  return !prev_state_btn && actual_state_btn;
}

int btns_decrement(void) {
  return gpio_get_level(BTNS_DECREMENT);
}
