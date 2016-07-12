#include <Dice.h>
#include <Arduino.h>


Dice::Dice(int led4, int led2, int led1) {
  _led4 = led4;
  _led2 = led2;
  _led1 = led1;
  pinMode(_led4, OUTPUT);
  pinMode(_led2, OUTPUT);
  pinMode(_led1, OUTPUT);
  randomSeed(analogRead(A0));
}

void Dice::roll() {
   int result = random(1,7);
#ifdef DEBUG
   Serial.print(“result = “);
   Serial.println(result);
#endif

   controlLED(_led4, (1 == result / 4 ));

#ifdef DEBUG
   Serial.print(“led4 = “); 
   Serial.println(1 == result / 4);
#endif

   result = result % 4;
   controlLED(_led2, (1 == result /  2));

#ifdef DEBUG
   Serial.print(“led2 = “); 
   Serial.println(1 == result / 2);
#endif

   result = result % 2;
   controlLED(_led1, 1 ==  result);

#ifdef DEBUG
   Serial.print(“led1 = “); 
   Serial.println(1 == result);
#endif
}

void Dice::controlLED(int led, bool on) {
  if (on)
    digitalWrite(led, HIGH);
  else
    digitalWrite(led, LOW);
}
