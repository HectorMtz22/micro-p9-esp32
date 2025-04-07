#include <stdio.h>
#include "freertos/FreeRTOS.h"

// Own Components
#include "display.h"
#include "buttons.h"
#include "ledc.h"
#include "leds.h"

#define TIME_DELAY 500

void app_main() {
  // Initialize the display, buttons, and LED
  leds_init();
  disp_init();
  btns_init();
  ledc_init();

  xTaskCreate(leds_test, "LEDs Test", 2048, NULL, 3, NULL);
  disp_test();

  while (true) {
    for (int counter = 9; counter >= 0; counter--) {
      disp_show(counter);
      ledc_update(counter);
      vTaskDelay(pdMS_TO_TICKS(TIME_DELAY));
    }
  }
}
