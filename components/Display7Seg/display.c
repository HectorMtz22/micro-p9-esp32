#include <stdio.h>
#include "display.h"
#include "driver/gpio.h" 
#include "freertos/FreeRTOS.h"

void disp_init(void) {
  gpio_set_direction(DISP_7_SEG_A, GPIO_MODE_OUTPUT);
  gpio_set_direction(DISP_7_SEG_B, GPIO_MODE_OUTPUT);
  gpio_set_direction(DISP_7_SEG_C, GPIO_MODE_OUTPUT);
  gpio_set_direction(DISP_7_SEG_D, GPIO_MODE_OUTPUT);
  gpio_set_direction(DISP_7_SEG_E, GPIO_MODE_OUTPUT);
  gpio_set_direction(DISP_7_SEG_F, GPIO_MODE_OUTPUT);
  gpio_set_direction(DISP_7_SEG_G, GPIO_MODE_OUTPUT);
}

void disp_show(enum DISP_VALUES number) {
  gpio_set_level(DISP_7_SEG_A, number & 0b00000001);
  gpio_set_level(DISP_7_SEG_B, number & 0b00000010);
  gpio_set_level(DISP_7_SEG_C, number & 0b00000100);
  gpio_set_level(DISP_7_SEG_D, number & 0b00001000);
  gpio_set_level(DISP_7_SEG_E, number & 0b00010000);
  gpio_set_level(DISP_7_SEG_F, number & 0b00100000);
  gpio_set_level(DISP_7_SEG_G, number & 0b01000000);
  return;
}

void disp_test(void) {
  for (int i = 0; i < 3; i++) {
    disp_show(DISP_TEST);
    vTaskDelay(TEST_DELAY / portTICK_PERIOD_MS);
    disp_show(DISP_OFF);
    vTaskDelay(TEST_DELAY / portTICK_PERIOD_MS);
  }
  disp_show(0);
}

int convert_to_display_value(int adc_value) {
  if (adc_value < 0 || adc_value > 255) {
    return DISP_INVALID;
  } else if (adc_value <= 50) {
    return DISP_LOW;
  } else if (adc_value <= 100) {
    return DISP_SAFE;
  } else {
    return DISP_HIGH;
  }
}
