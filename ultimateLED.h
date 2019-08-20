/* Blink
   Boolean LEDs
   Linear Fade LEDs
   Logarithmic Fade LEDs
   Repeating Patterns of above

   Created by Samuel Witt on 07/30/19.
   Copyright © 2019 Samuel Witt. All rights reserved. */



#ifndef ultimateLED_h
#define ultimateLED_h

#include <Arduino.h>

class LED {

    private:
        unsigned int _arraySize;        // Size of pattern array
        unsigned int* _blinkPattern = nullptr;    // Pointer to array containing delay pattern
        unsigned int _pin;              // Output pin to LED
        bool _running;
        unsigned int _currentMillis;
        unsigned int _previousMillis;
        unsigned int _delayMillis;
        unsigned int _delayIndex;

    public:
        // Construct LED object
        LED(unsigned int pin, unsigned int arraySize, unsigned int &blinkPattern);
        // Initialize pin
        void begin();
        // Run state machine for blinking functionality
        void run();
        // Start blinking
        void start();
        // Stop blinking
        void stop();
        // Turn on
        void on();
        // Turn on and set brightness using PWM
        void on(unsigned int pwm);
        // Turn off
        void off();

        //linearFadeOn();   // fade to on
        //linearFadeOff();  // fade to off
        //logFadeOn();  // fade to on
        //logFadeOff(); // fade to off
        //linearFadePattern(); // need a start and stop
        //logFadePattern(); // need a start and stop
        //blinkPattern();

};

#endif