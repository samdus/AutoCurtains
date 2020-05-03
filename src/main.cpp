#include <Arduino.h>

#include <controller/controller.hpp>

#include <model/display/display.hpp>
#include <model/clock/clock.hpp>
#include <model/ir_remote/ir_remote.hpp>

#define MS_BETWEEN_IR_READ 500
#define MS_BETWEEN_DISPLAY 500
#define MS_BETWEEN_CLOCK NB_MS_IN_MIN

#define CONTROLLER_TIMED_FUNCTION(NAME, TIME) void NAME() { \
  static unsigned long previous_##NAME = 0; \
  if(currentMillis - previous_##NAME >= TIME){ \
    controller.NAME(); \
    previous_##NAME += TIME; \
  } \
}

Clock clock;
Display display;
IrRemote remote;

Controller controller(&clock, &display, &remote);

unsigned long currentMillis = 0;

CONTROLLER_TIMED_FUNCTION(readIR, MS_BETWEEN_IR_READ)
CONTROLLER_TIMED_FUNCTION(refreshDisplay, MS_BETWEEN_IR_READ)
CONTROLLER_TIMED_FUNCTION(incrementTime, MS_BETWEEN_CLOCK)

void setup()
{
  controller.setup();
}

void loop()
{
  currentMillis = millis();
  
  readIR();
  refreshDisplay();
  incrementTime();
}