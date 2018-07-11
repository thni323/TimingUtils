# TimingUtils
Helpful utilities to organize multiple regular tasks in arduino projects.

## Managing regular tasks using CallbackTimer
```
  #include <Arduino.h>
  #include <CallbackTimer.h>

  CallbackTimer timerA, timerB;

  void callbackA() {
      // Code placed here will be executed every 1000 ms
      Serial.println("Callback Timer A");
  }

  void callbackB() {
      // Code placed here will be executed every 2000 ms
      Serial.println("Callback Timer B");
  }

  void setup() {
      Serial.begin(9600);

      timerA.setInterval(1000);
      timerA.setCallback(callbackA);

      timerB.setInterval(2000);
      timerB.setCallback(callbackB);

      CallbackTimer::init();

      timerA.start();
      timerB.start();
  }

  void loop() {
      CallbackTimer::process();
  }
```
