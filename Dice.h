#ifndef Dice_h
#define Dice_h

// Simple class that defines a binary dice using 3 Bits
// with each of the Bits representing a digit of the binary number
// with a decimal value from 1..6
class Dice {
 public:
   Dice(int led4, int led2, int led1); // initialized with Pins where the LEDs are connected
   void roll(); // roll the dice
 private:
   int _led4;
   int _led2;
   int _led1;
   void controlLED(int led, bool on); // internal method to turn a LED on or off
};

#endif
