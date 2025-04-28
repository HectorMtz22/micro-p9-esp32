#include <stdio.h>
#include "freertos/FreeRTOS.h"

// Own Components
#include "display.h"
#include "leds.h"
#include "timer.h"

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

  my_1seg_timer_init(); // Initialize the timer
}
