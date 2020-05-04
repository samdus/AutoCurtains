#include "motor.hpp"

Motor::Motor() : Stepper(MOTOR_STEPS_PER_INTERNAL_REVOLUTION, MOTOR_IN_1, MOTOR_IN_3, MOTOR_IN_2, MOTOR_IN_4) {
    this->init();
}

void Motor::init() {
    this->setSpeed(MOTOR_DEFAULT_SPEED);
    this->steps_left = 0;
    this->last_step_time = 0;
}

void Motor::startRotation(short rotations) {
    if (rotations > 0) { this->direction = 1; }
    if (rotations < 0) { this->direction = 0; }

    this->steps_left = abs(rotations) * MOTOR_STEPS_PER_SHAFT_REVOLUTION;
}

void Motor::step() {
    /*
        This code was extracted from the original library
        so it will be asynchronous
    */
    if (steps_left > 0)
    {
        unsigned long now = micros();
        // move only if the appropriate delay has passed:
        if (now - this->last_step_time >= this->step_delay)
        {
            // get the timeStamp of when you stepped:
            this->last_step_time = now;
            // increment or decrement the step number,
            // depending on direction:
            if (this->direction == 1)
            {
                this->step_number++;
                if (this->step_number == this->number_of_steps) {
                    this->step_number = 0;
                }
            }
            else
            {
                if (this->step_number == 0) {
                    this->step_number = this->number_of_steps;
                }
                this->step_number--;
            }
            // decrement the steps left:
            steps_left--;
            // step the motor to step number 0, 1, ..., {3 or 10}
            if (this->pin_count == 5)
                stepMotor(this->step_number % 10);
            else
                stepMotor(this->step_number % 4);
        }
    }
    else {
        this->off();
    }
}

void Motor::off(){
    digitalWrite(this->motor_pin_1, LOW);
    digitalWrite(this->motor_pin_2, LOW);
    digitalWrite(this->motor_pin_3, LOW);
    digitalWrite(this->motor_pin_4, LOW);
}