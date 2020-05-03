#include "clock.hpp"

Clock::Clock(){
    minutes = 0;
}

void Clock::incrementTime() {
    minutes = (minutes + 1) % NB_MIN_IN_DAY;
}

void Clock::setTime(const unsigned short hour, const unsigned short minute){
    minutes = (hour * NB_MIN_IN_HOUR) + minute;
}

const unsigned short Clock::getHour() {
    return floor(minutes / NB_MIN_IN_HOUR);
}

const unsigned short Clock::getMin() {
    return floor(minutes % NB_MIN_IN_HOUR);
}