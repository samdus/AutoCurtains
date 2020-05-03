#include "controller.hpp"

Controller::Controller(Clock *clock, Display *display, IrRemote *remote) {
    this->clock = clock;
    this->display = display;
    this->remote = remote;
}

void Controller::setup() {
  this->clock->init();
  this->display->init();
  this->remote->init();

  this->clock->setTime(15, 28);

  this->display->setCursor(0,0);
  this->display->print("Current time v11");

  this->display->setCursor(0,1);
  this->display->printTime(clock->getHour(), clock->getMin());
}

void Controller::readIR() {
    if (this->remote->decode()){
      this->clock->incrementTime();
    }
}

void Controller::refreshDisplay() {
    this->display->setCursor(0,1);
    this->display->printTime(clock->getHour(), clock->getMin());
}

void Controller::incrementTime() {
    this->clock->incrementTime();
}