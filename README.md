# Motor DC with TIP12X

The objective on this project is to implement PWM:

- Control a DC motor with TIP12X transistor 

## Folder contents

The project **motortip** contains one source file in C language [main.c](main/main.c). The file is located in folder [main](main).

ESP-IDF projects are built using CMake. The project build configuration is contained in `CMakeLists.txt` files that provide set of directives and instructions describing the project's source files and targets (executable, library, or both).

Below is short explanation of remaining files in the project folder.


```
├── CMakeLists.txt
├── main
│   ├── CMakeLists.txt
│   └── main.c
├── components
│   ├── Adc
│   │   ├── adc.c
│   │   ├── CMakeLists.txt
│   │   └── include
│   │       └── adc.h
│   └── MotorTip
│       ├── motortip.c
│       ├── CMakeLists.txt
│       └── include
│           └── motortip.h
└── README.md                  This is the file you are currently reading
```

For more information on structure and contents of ESP-IDF projects, please refer to Section [Build System](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/build-system.html) of the ESP-IDF Programming Guide.

## Block Diagram

<center>

![Block Diagram with ESP32](/assets/images/block_diagram.png)

</center>

## Schematic Diagram

![Schematic Design in KiCad](/assets/images/schematic_design.png)

## Troubleshooting

* Program upload failure

    * Hardware connection is not correct: run `idf.py -p PORT monitor`, and reboot your board to see if there are any output logs.
    * The baud rate for downloading is too high: lower your baud rate in the `menuconfig` menu, and try again.
