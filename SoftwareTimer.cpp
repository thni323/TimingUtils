#include "SoftwareTimer.h"

SoftwareTimer::SoftwareTimer() : Process() {
    active = false;
    startTime = 0;
    intervalTime = 1000;
}

SoftwareTimer::SoftwareTimer(unsigned long interval) : Process() {
    active = false;
    startTime = 0;
    intervalTime = interval;
}

void SoftwareTimer::onProcess() {
    if (active && isElapsed()) {
        startTime = millis();
        onTimeout();
        // Wait atleast for one interval until executed again
        if (isElapsed()) {
            startTime = millis();
        }
    }
}

void SoftwareTimer::start() {
    startTime = millis();
    active = true;
}

void SoftwareTimer::stop() {
    active = false;
}

void SoftwareTimer::setInterval(unsigned long interval) {
    intervalTime = interval;
}

bool SoftwareTimer::isElapsed() {
    if (intervalTime < getElapsedTime()) {
        return true;
    }
    return false;
}

unsigned long SoftwareTimer::getElapsedTime() {
    unsigned long elapsedTime;
    unsigned long currentTime = millis();
    if (currentTime < startTime)
    {
        elapsedTime = ULONG_MAX - startTime;
        elapsedTime += currentTime;
    } else {
        elapsedTime = currentTime - startTime;
    }
    return elapsedTime;
}
