// Author: Hector Flores
// Date: 2025-04-06

#include <stdio.h>
#include "leds.h"

#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"

void leds_init(void) {
    uint64_t ledmask = (1ULL << LEDS_1) | (1ULL << LEDS_2) | (1ULL << LEDS_3) | (1ULL << LEDS_4) | (1ULL << LEDS_5) | (1ULL << LEDS_6);
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
    uint8_t led1 = (led >> 0) & 0x01; // LED 1
    uint8_t led2 = (led >> 1) & 0x01; // LED 2
    uint8_t led3 = (led >> 2) & 0x01; // LED 3
    uint8_t led4 = (led >> 3) & 0x01; // LED 4
    uint8_t led5 = (led >> 4) & 0x01; // LED 5
    uint8_t led6 = (led >> 5) & 0x01; // LED 6

    gpio_set_level(LEDS_1, led1);
    gpio_set_level(LEDS_2, led2);
    gpio_set_level(LEDS_3, led3);
    gpio_set_level(LEDS_4, led4);
    gpio_set_level(LEDS_5, led5);
    gpio_set_level(LEDS_6, led6);
    return;
}

void leds_test(void *pvParameters) {
    for (int i = 0; i < 3; i++) {
        leds_set(0xFF); // Turn on all LEDs
        vTaskDelay(pdMS_TO_TICKS(TEST_DELAY));
        leds_set(0x00); // Turn off all LEDs
        vTaskDelay(pdMS_TO_TICKS(TEST_DELAY));
    }
    // Initial Sequence
    leds_set(0b00000001);
    vTaskDelete(NULL); // Delete the task when done
}