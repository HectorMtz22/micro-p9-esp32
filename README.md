# Counter with Buttons (Debounce and Delay)

This project consists in a counter that increment or decrement by one and shows the output in a 7-Segment Display.

In this project I'm working with the difference between using a Debounce with software or a typical delay for the buttons.

## Folder contents

The project **button_debounce** contains one source file in C language [main.c](main/main.c). The file is located in folder [main](main).

ESP-IDF projects are built using CMake. The project build configuration is contained in `CMakeLists.txt` files that provide set of directives and instructions describing the project's source files and targets (executable, library, or both).

Below is short explanation of remaining files in the project folder.

PWM signal is based on this example: [LEDC Basic Example](https://github.com/espressif/esp-idf/tree/v5.4.1/examples/peripherals/ledc/ledc_basic)

```
├── CMakeLists.txt
├── main
│   ├── CMakeLists.txt
│   └── main.c
├── components 
│   ├── Buttons 
│   │   ├── buttons.c
│   │   ├── CMakeLists.txt
│   │   └── include
│   │       └── buttons.h
│   ├── Display7Seg
│   │   ├── display.c
│   │   ├── CMakeLists.txt
│   │   └── include
│   │       └── display.h
│   └── Ledc
│       ├── ledc.c
│       ├── CMakeLists.txt
│       └── include
│           └── ledc.h
└── README.md                  This is the file you are currently reading
```

For more information on structure and contents of ESP-IDF projects, please refer to Section [Build System](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/build-system.html) of the ESP-IDF Programming Guide.

## Block Diagram

![Block Diagram with ESP32](/assets/images/P5_diagrama_bloques.png)

## Schematic Diagram

![Schematic Design in KiCad](/assets/images/P5_schematic_design.png)

## Troubleshooting

* Program upload failure

    * Hardware connection is not correct: run `idf.py -p PORT monitor`, and reboot your board to see if there are any output logs.
    * The baud rate for downloading is too high: lower your baud rate in the `menuconfig` menu, and try again.
