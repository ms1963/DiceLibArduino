// defining DEBUG enables debug output on Serial port
#define DEBUG 
#include "Dice.h"

// Dice with LEDs on digital Pins 9, 10, 11
Dice myDice(9,10,11);

void setup() {
  Serial.begin(9600);
}


void loop() {
  myDice.roll();  // roll the dice
  delay(2000);
} 
