#define DEBUG
#include "Dice.h"


Dice myDice(9,10,11);

void setup() {
  Serial.begin(9600);
}


void loop() {
  myDice.roll();
  delay(2000);
} 
