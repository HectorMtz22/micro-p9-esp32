idf_component_register(
    SRCS "main.c"
    INCLUDE_DIRS "."
    PRIV_REQUIRES driver
    REQUIRES Adc
    REQUIRES MotorTip
)
