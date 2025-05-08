#include <stdio.h>
#include "freertos/FreeRTOS.h"

// Own Components
#include "display.h"
#include "adc.h"

void app_main() {
  // Initialize the display and LED
  disp_init();

  // Test before enabling interruptions
  disp_test();

  while (1) {
    vTaskDelay(10 / portTICK_PERIOD_MS); // Espera para no bloquear el CPU
  }
}
