/*
 Library written for use with Common-Anode & Common-Cathode displays. Full description of the library is available on the 
 github readme file.

 Written by: Ali Kabeel
 Data: 21/1/2021
 */

#ifndef SevenSegmentDisplay_H
#define SevenSegmentDisplay_H

#include "Arduino.h"

class SevenSegmentDisplay
{
public:
    SevenSegmentDisplay(int pinA, int pinB, int pinC, int pinD, int pinE, int pinF, int pinG, int pinDP, boolean anode);
    void displayDecimalPoint(boolean on);
    void displayCharacter(char character);
    void testDisplay();

private:
    int pins[8];
    int anodeDisplay;
};

#endif
