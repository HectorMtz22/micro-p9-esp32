idf_component_register(
    SRCS "leds.c"
    PRIV_REQUIRES esp_driver_gpio
    INCLUDE_DIRS "include"
)