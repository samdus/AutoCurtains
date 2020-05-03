#include <Arduino.h>

#include <display/display.hpp>
#include <clock/clock.hpp>
 
Clock clock;
Display display;

void setup()
{
  clock.setTime(15, 28);

  display.init();
  display.setCursor(0,0);
  display.print("Current time v09");

  display.setCursor(0,1);
  display.printTime(clock.getHour(), clock.getMin());
}
 
void loop()
{
  delay(NB_MS_IN_MIN);
  clock.incrementTime();
  display.setCursor(0,1);
  display.printTime(clock.getHour(), clock.getMin());
}