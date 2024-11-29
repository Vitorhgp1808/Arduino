#include "Led_Pisca.h"
LedPisca lp(13);
void setup(){
    Serial.begin(9600);
    Serial.println("Usando Classes");
}

void loop(){
    lp.Update();
    delay(100);
};