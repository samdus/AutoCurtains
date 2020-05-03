#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <model/i_model.hpp>
#include <math.h>
#include <stdio.h>

#define NB_MIN_IN_DAY 1440
#define NB_SEC_IN_DAY 86400
#define NB_MIN_IN_HOUR 60
#define NB_MS_IN_MIN 60000

class Clock : public IModel {
    public:
        unsigned short minutes;

        Clock();

        void init();
        void setTime(const unsigned short hour, const unsigned short minute);
        void incrementTime();
        const unsigned short getHour();
        const unsigned short getMin();
};

#endif