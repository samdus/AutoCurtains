#ifndef __Pins_mapping_hpp__
#define __Pins_mapping_hpp__

#include <pins_arduino.h>

/* Digital pins */

// #define NOTHING 0
// #define NOTHING 1
#define REMOTE_RECV_PIN 2
// #define NOTHING 3
// #define NOTHING 4
// #define NOTHING 5
// #define NOTHING 6
// #define NOTHING 7
// #define NOTHING 8
// #define NOTHING 9
// #define NOTHING 10
// #define NOTHING 11
// #define NOTHING 12
// #define NOTHING 13

/* Analog pins */

// #define NOTHING A0
// #define NOTHING A1
// #define NOTHING A2
// #define NOTHING A3
#define UNO_SDA A4
#define UNO_SCL A5

/* IIC Mapping */
#define DISPLAY_SDA UNO_SDA
#define DISPLAY_SCL UNO_SCL

#define DISPLAY_LCD_ADDR 0x27

#endif