#include <stdio.h>
#include "freertos/FreeRTOS.h"

// Own Components
#include "adc.h"
#include "motortip.h"

void app_main() {
  adc_init();
  motortip_init();

  int adc_value = 0;

  while (1) {
    adc_value = adc_read();
    // printf("ADC Value: %d\n", adc_value);
    set_motor_speed(adc_value); // Set motor speed based on ADC value

    vTaskDelay(100 / portTICK_PERIOD_MS); // Espera para no bloquear el CPU
  }
}
