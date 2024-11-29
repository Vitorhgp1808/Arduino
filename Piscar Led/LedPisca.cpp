#include <arduino.h>
#include "LedPisca.h"

Led_Piscar::Led_Pisca(int pin){
    ledPin = pin;
    pinMode(ledPin, OUTPUT);

    onTime = 500;
    offTime = 500;

    ledState = LOW;
    previousMillis = 0;
}

void Led_Pisca::Update(){
    unsigned long currentMillis = millis();

    if((ledState == HIGH) && (currentMillis - previousMillis >= onTime)){
        ledState = LOW;
        previousMillis = currentMillis;
        digitalWrite(ledPin, ledState);
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
    else if((ledState == LOW) && (currentMillis - previousMillis >= offTime)){
        ledState = HIGH;
        previousMillis = currentMillis;
        digitalWrite(ledPin, ledState);
    }

    void setOnTime(long on){
        onTime = on;
    }
    void setOffTime(long off){
        offTime = off;
    }
    long getOnTime(){
        return onTime;
    }
    long getOffTime(){
        return offTime;
    }
}