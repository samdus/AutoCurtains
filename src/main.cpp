#include <Arduino.h>

#include <controller/controller.hpp>

#include <model/display/display.hpp>
#include <model/clock/clock.hpp>
#include <model/ir_remote/ir_remote.hpp>
#include <model/motor/motor.hpp>

#define MS_BETWEEN_IR_READ 500
#define MS_BETWEEN_DISPLAY 500
#define MS_BETWEEN_CLOCK NB_MS_IN_MIN

#define DELAYED_CONTROLLER_CALL(NAME, TIME) \
  static unsigned long previous_##NAME = 0; \
  if(currentMillis - previous_##NAME >= TIME){ \
    controller.NAME(); \
    previous_##NAME += TIME; \
  }

Clock clock;
Display display;
IrRemote remote;
Motor motor;

Controller controller(&clock, &display, &remote, &motor);

void setup()
{
  controller.setup();
}

void loop()
{
  unsigned long currentMillis = 0;
  currentMillis = millis();
  
  DELAYED_CONTROLLER_CALL(readIR, MS_BETWEEN_IR_READ)
  DELAYED_CONTROLLER_CALL(refreshDisplay, MS_BETWEEN_IR_READ)
  DELAYED_CONTROLLER_CALL(incrementTime, MS_BETWEEN_CLOCK)
  controller.motorStep(); // This method is self-synchronized
}