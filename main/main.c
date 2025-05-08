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
  int display_value = 0;

  while (1) {
    adc_value = adc_read();
    display_value = convert_to_display_value(adc_value);

    disp_show(display_value); // Muestra el valor ADC en el display
    //printf("ADC Value: %d, Display Value: %d\n", adc_value, display_value);
    vTaskDelay(100 / portTICK_PERIOD_MS); // Espera para no bloquear el CPU
  }
}
