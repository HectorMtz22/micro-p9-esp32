#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "driver/timer.h"

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
  my_0_5seg_timer_init(); // Initialize the timer

  uint64_t overflow_count_timer_2 = 0;
  uint64_t previous_count = 0;
  uint8_t led_state = 0;

  while (1) {
    timer_get_counter_value(TIMER_GROUP_1, TIMER_0, &overflow_count_timer_2); // Polling rate
    if (overflow_count_timer_2 - previous_count >= 500000) { // 1Mhz / 2 = 0.5 seconds
      led_state ^= 1;
      leds_set(led_state);
      previous_count = overflow_count_timer_2; // Update the previous count
    }
    vTaskDelay(10 / portTICK_PERIOD_MS); // Espera para no bloquear el CPU
  }
}
