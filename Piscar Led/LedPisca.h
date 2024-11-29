#ifndef LED_PISCA
#define LED_PISCA
#include <Arduino.h>

class Led_Pisca{
    private: 
        int ledPin;
        long onTime;
        long offTime;

        int ledState;
        unsigned long previousMillis;

    public:
        Led_Pisca(int pin, long on, long off);
        void Update();
        void On();
        void Off();
        void SetInterval(long on, long off);
        void SetOnTime(long on);
        void SetOffTime(long off);
        long GetOnTime();
        long GetOffTime();
}