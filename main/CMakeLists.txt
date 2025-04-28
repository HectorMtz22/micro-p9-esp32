idf_component_register(
    SRCS "main.c"
    INCLUDE_DIRS "."
    REQUIRES Display7Seg
    REQUIRES Buttons 
    REQUIRES Ledc
    REQUIRES Leds
    REQUIRES Timer
)
