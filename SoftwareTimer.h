#ifndef SOFTWARETIMER_H
#define SOFTWARETIMER_H

#include <Arduino.h>
#include <limits.h>

#include "Process.h"

class SoftwareTimer : public Process {
    public:
        SoftwareTimer();
        SoftwareTimer(unsigned long interval);

        void setInterval(unsigned long interval);
        void start();
        void stop();

    protected:
        virtual void onTimeout() = 0;
        void onInit() override {};
        void onProcess() override; 

    private:
        bool isElapsed();
        unsigned long getElapsedTime();

        bool active;

        unsigned long startTime;
        unsigned long intervalTime;
};

#endif