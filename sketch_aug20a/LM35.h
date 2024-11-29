#ifndef LM35_H
#define LM35_H


class LM35 {
public:

    LM35(int sensorPin, int buttonPin);

    float readTemperature();

    void toggleMode();

private:
    int _sensorPin;
    int _buttonPin;
    bool _isCelsius:

    float readCelsius();
    float readFahrenheit();
};

#endif
