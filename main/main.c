#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Own Components
#include "display.h"
#include "buttons.h"
#include "ledc.h"
#include "leds.h"

#define TIME_DELAY 300

void app_main() {
  // Initialize the display, buttons, and LED
  leds_init();
  disp_init();
  btns_init();
  ledc_init();

  xTaskCreate(leds_test, "LEDs Test", 2048, NULL, 3, NULL);
  disp_test();

  int state = 0;
  while (true) {
    disp_show(state);
    ledc_update(state);
    if (btns_increment_debounce()) {
      if (++state >= 0x0F) state = 0x0F;
    }
    if (btns_decrement()) {
      if (--state <= 0) state = 0;
      disp_show(state);
      vTaskDelay(TIME_DELAY / portTICK_PERIOD_MS);
    }
  }
}
