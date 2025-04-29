// Author: Hector Flores
// Date: 2025-04-06

#include <stdio.h>
#include "leds.h"

#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"

void leds_init(void) {
    uint64_t ledmask = (1ULL << LEDS_1);
    gpio_config_t io_conf = {
        .intr_type = GPIO_INTR_DISABLE,
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = ledmask,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .pull_up_en = GPIO_PULLUP_DISABLE,
    };

    gpio_config(&io_conf); // Configure GPIO with the given settings

    return;
}

void leds_set(uint8_t led) {
    gpio_set_level(LEDS_1, led);
    return;
}

void leds_test(void *pvParameters) {
    for (int i = 0; i < 3; i++) {
        leds_set(1); // Turn on all LEDs
        vTaskDelay(pdMS_TO_TICKS(TEST_DELAY));
        leds_set(0); // Turn off all LEDs
        vTaskDelay(pdMS_TO_TICKS(TEST_DELAY));
    }
    // Initial Sequence
    leds_set(0);
    vTaskDelete(NULL); // Delete the task when done
}
