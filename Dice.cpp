#include <Dice.h>
#include <Arduino.h>

#define DEBUG
Dice::Dice(int led4, int led2, int led1) {
  _led4 = led4; // LED that represents MSBit
  _led2 = led2; // LED that represents medium Bit
  _led1 = led1; // LED that represents LSBit
  pinMode(_led4, OUTPUT); // all pins are OUTPUT pins
  pinMode(_led2, OUTPUT);
  pinMode(_led1, OUTPUT);
  randomSeed(analogRead(A0)); // read random value from analog A0 for initial seed
}

void Dice::roll() {
   int result = random(1,7); // get a random number from 1..6

#ifdef DEBUG
   Serial.print("dice value = ");
   Serial.println(result);
#endif

   controlLED(_led4, (1 == result / 4 )); // simple arithmetic

#ifdef DEBUG
   Serial.print("LED4 = ");
   Serial.println(1 == result / 4);
#endif

   result = result % 4;
   controlLED(_led2, (1 == result /  2));

#ifdef DEBUG
   Serial.print("LED2 = ");
   Serial.println(1 == result / 2);
#endif

   result = result % 2;
   controlLED(_led1, 1 ==  result);

#ifdef DEBUG
   Serial.print("LED1 = ");
   Serial.println(1 == result);
#endif
}

void Dice::controlLED(int led, bool on) {
  if (on)
    digitalWrite(led, HIGH);
  else
    digitalWrite(led, LOW);
}
