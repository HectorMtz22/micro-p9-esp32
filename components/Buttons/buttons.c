#include "buttons.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"

#include "leds.h"

uint8_t prev_state_btn = 0;
uint8_t actual_state_btn = 0;

volatile int leds_state = 1;

void btns_init(void) {
  // Configure buttons as interrupts
  gpio_config_t io_conf = {
      .intr_type = GPIO_INTR_POSEDGE, // Rising edge
      .mode = GPIO_MODE_INPUT,
      .pin_bit_mask = (1ULL << BTNS_INCREMENT) | (1ULL << BTNS_DECREMENT),
      .pull_down_en = GPIO_PULLDOWN_DISABLE,
      .pull_up_en = GPIO_PULLUP_DISABLE,
  };
  gpio_config(&io_conf);
  return;
}

void btns_isr_register(void) {
  // Register the ISR for the buttons
  gpio_install_isr_service(ESP_INTR_FLAG_LEVEL1);
  gpio_isr_handler_add(BTNS_INCREMENT, btns_isr_handler_more, NULL);
  gpio_isr_handler_add(BTNS_DECREMENT, btns_isr_handler_less, NULL);
}

// ISR for button more
void btns_isr_handler_more(void *arg) {
  leds_state = leds_state << 1;
  if (leds_state > 0b00100000) leds_state = 0b00100000;
  leds_set(leds_state);
}
// ISR for button 1
void btns_isr_handler_less(void *arg) {
  leds_state = leds_state >> 1;
  if (leds_state < 0b00000001) leds_state = 0b00000001;
  leds_set(leds_state);
}
