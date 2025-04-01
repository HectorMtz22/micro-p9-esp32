#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/gpio.h" 

#define TIME_DELAY 300

#define DISP_7_SEG_A GPIO_NUM_22
#define DISP_7_SEG_B GPIO_NUM_23
#define DISP_7_SEG_C GPIO_NUM_21
#define DISP_7_SEG_D GPIO_NUM_19
#define DISP_7_SEG_E GPIO_NUM_18
#define DISP_7_SEG_F GPIO_NUM_5
#define DISP_7_SEG_G GPIO_NUM_17

#define BTNS_INCREMENT GPIO_NUM_2
#define BTNS_DECREMENT GPIO_NUM_15

void disp_init(void);
void disp_show(int number);

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
      vTaskDelay(TIME_DELAY / portTICK_PERIOD_MS);
    }

  }
}

void disp_init(void) {
  gpio_set_direction(DISP_7_SEG_A, GPIO_MODE_OUTPUT);
  gpio_set_direction(DISP_7_SEG_B, GPIO_MODE_OUTPUT);
  gpio_set_direction(DISP_7_SEG_C, GPIO_MODE_OUTPUT);
  gpio_set_direction(DISP_7_SEG_D, GPIO_MODE_OUTPUT);
  gpio_set_direction(DISP_7_SEG_E, GPIO_MODE_OUTPUT);
  gpio_set_direction(DISP_7_SEG_F, GPIO_MODE_OUTPUT);
  gpio_set_direction(DISP_7_SEG_G, GPIO_MODE_OUTPUT);
}

void disp_show(int number) {
  uint8_t segments[] = {
		0b00111111,
		0b00000110,
		0b01011011,
		0b01001111,
		0b01100110,
		0b01101101,
		0b01111101,
		0b00000111,
		0b01111111,
		0b01100111,
		0b01110111,
		0b01111100,
		0b00111001,
		0b01011110,
		0b01111001,
		0b01110001
	};

  int segment = segments[number];
  gpio_set_level(DISP_7_SEG_A, segment & 0b00000001);
  gpio_set_level(DISP_7_SEG_B, segment & 0b00000010);
  gpio_set_level(DISP_7_SEG_C, segment & 0b00000100);
  gpio_set_level(DISP_7_SEG_D, segment & 0b00001000);
  gpio_set_level(DISP_7_SEG_E, segment & 0b00010000);
  gpio_set_level(DISP_7_SEG_F, segment & 0b00100000);
  gpio_set_level(DISP_7_SEG_G, segment & 0b01000000);
  return;
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