// Author: Héctor Flores
// Date: 2025-05-07

#include "adc.h"
#include "freertos/FreeRTOS.h"
#include "driver/adc.h"

void adc_init() {
    adc2_config_channel_atten(ADC2_CHANNEL_3, ADC_ATTEN_DB_0);
}

int adc_read() {
    int adc_value = 0;
    esp_err_t ret = adc2_get_raw(ADC2_CHANNEL_3, ADC_WIDTH_BIT_12, &adc_value);

    // Retornar el valor ADC en 8 bits
    if (ret == ESP_OK) {
        return adc_value = adc_value >> 4; // Desplazar 4 bits a la derecha para obtener el valor en 8 bits
    } else {
        return -1; // Error al leer el ADC
    }
}