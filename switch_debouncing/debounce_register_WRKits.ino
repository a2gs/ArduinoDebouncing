/*
 * Code from WR Kits, video: INDISPENSÁVEL! CÓDIGO PROFISSIONAL PARA LEITURA DE BOTÃO | Curso de Arduino #257
 * (https://youtu.be/GE13ovG3omw)
 */

#define bt1 (1<<4) // Pino 12
#define led (1<<5) // Pino 13

void setup()
{
  Serial.begin(9600);

  DDRB  &= ~bt1; // Configura entrada para botao
  PORTB |=  bt1; // Habilita pull-up interno
  DDRB  |=  led; // Configura saida para led
}

void loop()
{
  bool bt1_flag = false;

  while(1){

    Serial.print("Checking button pin: ");
    if(!(PINB & bt1)){
      Serial.println("DOWN. Set flag to TRUE.");

      bt1_flag = true;
    }else
      Serial.println("UP. Unchange flag..");

    Serial.print("Pin button released and flag TRUE? ");
    if((PINB & bt1) && (bt1_flag == true)){
      Serial.println("YES. Changing led status.");

      bt1_flag  = false;
      PORTB    ^= led;
    }else
      Serial.println("NO.");
  }
}
