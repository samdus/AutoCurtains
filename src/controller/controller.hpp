#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP


#include <model/display/display.hpp>
#include <model/clock/clock.hpp>
#include <model/ir_remote/ir_remote.hpp>

class Controller {
    public:
        Clock *clock = 0;
        Display *display = 0;
        IrRemote *remote = 0;

        Controller(Clock *clock, Display *display, IrRemote *remote);

        void setup();
        void readIR();
        void refreshDisplay();
        void incrementTime();
};

#endif