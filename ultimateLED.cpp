#include <Arduino.h>
#include <ultimateLED.h>

LED::LED(unsigned int pin, unsigned int arraySize, unsigned int &blinkPattern) {

    _arraySize = arraySize;
    _blinkPattern = &blinkPattern;
    _pin = pin;
    _running = false;
    _currentMillis = 0;
    _previousMillis = 0;
    _delayMillis = 0;
    _delayIndex = 0;

}

void LED::begin() {

    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);

}

void LED::run() {

    if (_running) {
        _currentMillis = millis();
        if (abs(_currentMillis - _previousMillis) >= _delayMillis) {
            // If index is odd (that is, if there is a remainder), turn LED off.
            if (_delayIndex % 2) digitalWrite(13, LOW);
            // If index is even, turn LED on.
            else digitalWrite(13, HIGH);
            // Set delay for current HIGH/LOW state of LED.
            _delayMillis = _blinkPattern[_delayIndex];
            // If index will remain within the array, increment it.
            if (_delayIndex + 1 < _arraySize) _delayIndex++;
            // If _delayIndex reaches the end of that range, reset it to 0.
            else _delayIndex = 0;
            _previousMillis = _currentMillis;
        }
    }

}

void LED::start() {

    _running = true;

}

void LED::stop() {

    _running = false;
    _currentMillis = 0;
    _previousMillis = 0;
    _delayMillis = 0;
    _delayIndex = 0;

}

void LED::on() {

    digitalWrite(_pin, HIGH);

}

void LED::on(unsigned int pwm) {

    analogWrite(_pin, pwm);

}

void LED::off() {

    digitalWrite(_pin, LOW);

}