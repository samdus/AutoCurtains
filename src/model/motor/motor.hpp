#ifndef MOTOR_HPP
#define MOTOR_HPP

#include <Arduino.h>

#include <pins_mapping.hpp>
#include <model/i_model.hpp>

#if !defined(MOTOR_IN_1) || !defined(MOTOR_IN_2) || !defined(MOTOR_IN_3) || !defined(MOTOR_IN_4)
#   error Must define the four motor input pins
#endif

#include <Stepper.h>

// Number of steps per revolution of INTERNAL motor in 4-step mode
#define MOTOR_STEPS_PER_INTERNAL_REVOLUTION 32   

// Number of steps per revolution of OUTPUT SHAFT (= gear reduction; 32 * 64 steps)
#define MOTOR_STEPS_PER_SHAFT_REVOLUTION 2048

#define MOTOR_DEFAULT_SPEED 1000

class Motor : public IModel, public Stepper {
    public:
        int steps_left;

        Motor();

        void init();
        void startRotation(short rotations);
        void step();
        void off();
};

#endif