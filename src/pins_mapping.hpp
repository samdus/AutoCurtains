#ifndef __Pins_mapping_hpp__
#define __Pins_mapping_hpp__

#include <pins_arduino.h>

/* Digital pins */

// #define NOTHING 0
// #define NOTHING 1
#define LED_PIN_A 2
#define LED_PIN_B 3
#define LED_PIN_C 4
#define LED_PIN_D 5
#define LED_PIN_E 6
#define LED_PIN_F 7
#define LED_PIN_G 8
#define LED_PIN_D1 9
#define LED_PIN_D2 10
#define LED_PIN_D3 11
#define LED_PIN_D4 12
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