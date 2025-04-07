idf_component_register(
    SRCS "buttons.c"
    PRIV_REQUIRES esp_driver_gpio 
    REQUIRES Leds
    INCLUDE_DIRS "include"
)
