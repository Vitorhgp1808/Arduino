#include "LM35.h"

const int sensorPin = A0;
const int buttonPin = 8;

LM35 sensor(sensorPin, buttonPin);

void setup() {
    Serial.begin(9600);
}

void loop() {
    sensor.toggleMode();

    float temperature = sensor.readTemperature();

    Serial.print("Temperatura: ");
    Serial.println(temperature);

    delay(1000);
}
