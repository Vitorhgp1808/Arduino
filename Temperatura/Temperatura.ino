#define pin_lm35 A0 //Pino o qual o sensor está conectado
#define button 10
#include <LiquidCrystal.h>
LiquidCrystal lcd ( 12, 11, 5, 4, 3, 2 );
bool trocar = false;


void setup() { 
  lcd.begin(16, 2); 
  Serial.begin(9600); // Inicia a comunicação com
  pinMode(pin_lm35, INPUT); // Define o sensor como uma entrada de sinal
  pinMode(button, INPUT);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("A temperatura eh ");

  float valor_analog_lm35 = float(analogRead(pin_lm35)); // Obtém o valor analógico que varia de 0 a 1023
  float tensao = (valor_analog_lm35 * 5) / 1023; // Vamos converter esse valor para tensão elétrica
  float temperatura = tensao / 0.010; // dividimos a tensão por 0.010 que representa os 10 mV
  float farenheit = (temperatura * 1.8) + 32;

  if (digitalRead(button) == HIGH){ 
    trocar = !trocar;
    delay(100);
  }
  
  if (trocar){
    lcd.setCursor(5,1);
    lcd.print(temperatura); // Mostra na serial a temperatura do sensor
  }
  else{
    lcd.setCursor(5,1);
    lcd.print(farenheit); // Mostra na serial a temperatura do sensor
  }

  delay(100); // aguarda 1 segundo

}

 
