#include "clock.hpp"

Clock::Clock(){
    this->minutes = 0;
}

void Clock::init() {}

void Clock::incrementTime() {
    this->minutes = (this->minutes + 1) % NB_MIN_IN_DAY;
}

void Clock::setTime(const unsigned short hour, const unsigned short minute){
    this->minutes = (hour * NB_MIN_IN_HOUR) + minute;
}

const unsigned short Clock::getHour() {
    return floor(this->minutes / NB_MIN_IN_HOUR);
}

const unsigned short Clock::getMin() {
    return floor(this->minutes % NB_MIN_IN_HOUR);
}