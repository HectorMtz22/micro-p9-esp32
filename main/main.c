#include <stdio.h>
#include "freertos/FreeRTOS.h"

// Own Components
#include "display.h"
#include "leds.h"

#include "driver/timer.h"

#define TIMER_DIVIDER 80 // 80MHz / 80 = 1MHz

volatile uint8_t led_state = 1;

void timer_1seg_isr_handler(void *arg);

void my_1seg_timer_init() {
  timer_config_t config = {
    .divider = TIMER_DIVIDER,           // Prescaler (divide el clock base)
    .counter_dir = TIMER_COUNT_UP,      // Contar hacia arriba
    .counter_en = TIMER_PAUSE,          // Empezar en pausa
    .alarm_en = TIMER_ALARM_EN,         // Habilitar alarma
    .auto_reload = TIMER_AUTORELOAD_EN, // Recargar automáticamente
  };

  timer_init(TIMER_GROUP_0, TIMER_0, &config);            // Inicializar el timer
  timer_set_counter_value(TIMER_GROUP_0, TIMER_0, 0);     // Inicializar el contador a 0
  timer_set_alarm_value(TIMER_GROUP_0, TIMER_0, 1000000); // Establecer el valor de la alarma (1 segundo)
  timer_enable_intr(TIMER_GROUP_0, TIMER_0);              // Habilitar interrupciones
  timer_isr_register(TIMER_GROUP_0, TIMER_0, timer_1seg_isr_handler, NULL, ESP_INTR_FLAG_IRAM, NULL); // Registrar la ISR
  timer_start(TIMER_GROUP_0, TIMER_0);                    // Iniciar el timer
}

void IRAM_ATTR timer_1seg_isr_handler(void *arg) {
  // Eliminar la interrupción
  timer_group_clr_intr_status_in_isr(TIMER_GROUP_0, TIMER_0);
  // Vuelve a habilitar la alarma
  timer_group_enable_alarm_in_isr(TIMER_GROUP_0, TIMER_0);
  led_state ^= 1;
  leds_set(led_state);
}

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
