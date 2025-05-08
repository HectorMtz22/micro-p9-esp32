// Author: Hector Flores

// Date: 2025-04-01

#ifndef DISPLAY_H
#define DISPLAY_H

#define DISP_7_SEG_A GPIO_NUM_22
#define DISP_7_SEG_B GPIO_NUM_23
#define DISP_7_SEG_C GPIO_NUM_21
#define DISP_7_SEG_D GPIO_NUM_19
#define DISP_7_SEG_E GPIO_NUM_18
#define DISP_7_SEG_F GPIO_NUM_5
#define DISP_7_SEG_G GPIO_NUM_17

enum DISP_VALUES {
    DISP_OFF,
    DISP_LOW    = 0b00111000,
    DISP_SAFE   = 0b01101101,
    DISP_HIGH   = 0b01110110,
    DISP_TEST   = 0b01111111,
    DISP_INVALID = 0b01111001
};

#define TEST_DELAY 200

void disp_init(void);
void disp_test(void);
void disp_show(enum DISP_VALUES);
int convert_to_display_value(int adc_value);

#endif
