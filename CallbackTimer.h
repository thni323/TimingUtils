#ifndef CALLBACK_TIMER_H
#define CALLBACK_TIMER_H

#include "SoftwareTimer.h"

class CallbackTimer : public SoftwareTimer {
    public:
        CallbackTimer() : SoftwareTimer() {
            callbackFunction = nullptr;
        };

        CallbackTimer(void (*callback)(void), unsigned long interval) : SoftwareTimer(interval) {
            callbackFunction = callback;
        };

        void setCallback(void (*callback)(void)) {
            callbackFunction = callback;
        };

    protected:
        void onTimeout() override {
            if (callbackFunction != nullptr) {
                callbackFunction();
            }
        };

    private:
        void (*callbackFunction)(void);

};

#endif