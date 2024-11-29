int ledPin = 13;

// Para o modo 1 troque a variavel mode para 1, para 2 mode 2, para 3 mode 3! 
int modes = 3;
boolean terceiroModo = false;


void setupTimer()
{
  if (terceiroModo) {
    switch (modes) {
       case 1:
        modes = 2;
        break;
       case 2:
        modes = 1;
        break;
    }
  }
    
  switch (modes) {
    case 1:
      TCNT1 = 0xC2F7;
      break;
    case 2:
      TCNT1 = 0x7A12;
      break;
  }
}
 
void setup()
{
  pinMode(ledPin, OUTPUT);
 
  // Configuração do timer1 
  TCCR1A = 0;                        //confira timer para operação normal pinos OC1A e OC1B desconectados
  TCCR1B = 0;                        //limpa registrador
  TCCR1B |= (1<<CS10)|(1 << CS12);   // configura prescaler para 1024: CS12 = 1 e CS10 = 1

  if (modes == 3) {
    terceiroModo = true;
    modes = 2;
  }

  setupTimer();   // incia timer com valor para que estouro ocorra em 1 segundo
                                     // 65536-(16MHz/1024/1Hz) = 49911 = 0xC2F7

  TCNT1 = 0x7A12;
  
  TIMSK1 |= (1 << TOIE1);           // habilita a interrupção do TIMER1
}

void loop() {} 
 
ISR(TIMER1_OVF_vect)                              //interrupção do TIMER1 
{
  setupTimer();                     // Renicia TIMER
  digitalWrite(ledPin, digitalRead(ledPin) ^ 1); //inverte estado do led
}