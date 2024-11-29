#include "LM35.h"
#include <Arduino.h>


LM35::LM35(int sensorPin, int buttonPin) 
    : _sensorPin(sensorPin), _buttonPin(buttonPin), _isCelsius(true) {
    pinMode(_sensorPin, INPUT);
    pinMode(_buttonPin, INPUT_PULLUP); 
}


float LM35::readTemperature() {
    if (_isCelsius) {
        return readCelsius();
    } else {
        return readFahrenheit();
    }
}


void LM35::toggleMode() {
    if (digitalRead(_buttonPin) == LOW) {
        _isCelsius = !_isCelsius;
        delay(200);
    }
}


float LM35::readCelsius() {
    int rawValue = analogRead(_sensorPin);
    float voltage = (rawValue / 1023.0) * 5.0;
    return voltage * 100.0;
}


float LM35::readFahrenheit() {
    float celsius = readCelsius();
    return (celsius * 9.0 / 5.0) + 32.0;
}
