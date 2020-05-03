#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <model/i_model.hpp>
#include <pins_mapping.hpp>
#include <LiquidCrystal_I2C.h>

#if !defined(DISPLAY_SDA) || !defined(DISPLAY_SCL) || !defined(DISPLAY_LCD_ADDR)
#   error Must define SDA and SCL pins for display
#endif

// These pins are hardwired in the LCMI 602 IIC module
#define DISPLAY_EN_PIN 2
#define DISPLAY_RW_PIN 1
#define DISPLAY_RS_PIN 0
#define DISPLAY_D4_PIN 4
#define DISPLAY_D5_PIN 5
#define DISPLAY_D6_PIN 6
#define DISPLAY_D7_PIN 7
#define DISPLAY_BACKLIGHT_PIN 3
#define DISPLAY_BACKPOL_DEFAULT POSITIVE

class Display : public IModel, public LiquidCrystal_I2C {
    public:
        using LiquidCrystal_I2C::LiquidCrystal_I2C;

        Display(t_backlighPol backlighPol) : LiquidCrystal_I2C(DISPLAY_LCD_ADDR, DISPLAY_EN_PIN, DISPLAY_RW_PIN, DISPLAY_RS_PIN, DISPLAY_D4_PIN, DISPLAY_D5_PIN, DISPLAY_D6_PIN, DISPLAY_D7_PIN, DISPLAY_BACKLIGHT_PIN, backlighPol) {};
        Display() : Display(DISPLAY_BACKPOL_DEFAULT){};

        void init();
        void printTime(unsigned short hour, unsigned short min);
        void printTime(unsigned short hour, unsigned short min, unsigned short sec);
};

#endif