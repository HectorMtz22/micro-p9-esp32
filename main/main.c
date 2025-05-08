#include <stdio.h>
#include "freertos/FreeRTOS.h"

// Own Components
#include "display.h"
#include "adc.h"

void app_main() {
  // Initialize the display and LED
  disp_init();
  adc_init();

  // Test before enabling interruptions
  disp_test();
  int adc_value = 0;

  while (1) {
    adc_value = adc_read();
    disp_show(adc_value); // Muestra el valor ADC en el display
    vTaskDelay(100 / portTICK_PERIOD_MS); // Espera para no bloquear el CPU
  }
}
