#include "controller.hpp"

Controller::Controller(Clock *clock, Display *display, IrRemote *remote, Motor *motor) {
    this->clock = clock;
    this->display = display;
    this->remote = remote;
    this->motor = motor;
}

void Controller::setup() {
  this->clock->init();
  this->display->init();
  this->remote->init();
  this->motor->init();

  this->clock->setTime(15, 28);

  this->display->setCursor(0,0);
  this->display->print("Current time v11");

  this->display->setCursor(0,1);
  this->display->printTime(clock->getHour(), clock->getMin());
}

void Controller::readIR() {
    if (this->remote->decode()){
      this->clock->incrementTime();
      if(this->motor->steps_left == 0) {
        this->motor->startRotation(5);
      }
    }
}

void Controller::refreshDisplay() {
    this->display->setCursor(0,1);
    this->display->printTime(clock->getHour(), clock->getMin());
}

void Controller::incrementTime() {
    this->clock->incrementTime();
}

void Controller::motorStep() {
  this->motor->step();
}