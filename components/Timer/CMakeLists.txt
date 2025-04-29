idf_component_register(
    SRCS "timer.c"
    PRIV_REQUIRES driver
    PRIV_REQUIRES Leds
    PRIV_REQUIRES Display7Seg
    INCLUDE_DIRS "include"
)