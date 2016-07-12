#ifndef Dice_h
#define Dice_h


class Dice {
 public:
   Dice(int led4, int led2, int led1);
   void roll();
 private:
   int _led4;
   int _led2;
   int _led1;
   void controlLED(int led, bool on);
};

#endif