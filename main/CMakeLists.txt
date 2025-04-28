idf_component_register(
    SRCS "main.c"
    PRIV_REQUIRES driver
    INCLUDE_DIRS "."
    REQUIRES Display7Seg
    REQUIRES Buttons 
    REQUIRES Ledc
    REQUIRES Leds
)
