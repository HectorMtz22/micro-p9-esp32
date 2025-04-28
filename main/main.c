#include <stdio.h>
#include "freertos/FreeRTOS.h"

// Own Components
#include "display.h"
#include "leds.h"

#define TIME_DELAY 500

void app_main() {
  // Desable interrupts
  esp_intr_disable(0);
  
  // Initialize the display and LED
  leds_init();
  disp_init();

  // Test before enabling interruptions
  xTaskCreate(leds_test, "LEDs Test", 2048, NULL, 3, NULL);
  disp_test();

  // Enable interrupts
  esp_intr_enable(0);

  while (true) {
    for (int counter = 0; counter <= 9; counter++) {
      disp_show(counter);
      vTaskDelay(pdMS_TO_TICKS(TIME_DELAY));
    }
  }
}
