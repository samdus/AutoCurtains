#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <model/display/display.hpp>
#include <model/clock/clock.hpp>
#include <model/ir_remote/ir_remote.hpp>
#include <model/motor/motor.hpp>

//TODO: Create interfaces for models, then the class will start to be testable
class Controller {
    public:
        Clock *clock = 0;
        Display *display = 0;
        IrRemote *remote = 0;
        Motor *motor = 0;

        Controller(Clock *clock, Display *display, IrRemote *remote, Motor *motor);

        void setup();
        void readIR();
        void refreshDisplay();
        void incrementTime();
        void motorStep();
};

#endif