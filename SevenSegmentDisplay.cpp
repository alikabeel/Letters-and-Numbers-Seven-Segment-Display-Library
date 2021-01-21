/*
 Library written for use with Common-Anode & Common-Cathode displays. Full description of the library is available on the
 github readme file.

 Written by: Ali Kabeel
 Data: 21/1/2021
 */

#include "Arduino.h"
#include "SevenSegmentDisplay.h"




SevenSegmentDisplay::SevenSegmentDisplay(int pinA, int pinB, int pinC, int pinD, int pinE, int pinF, int pinG, int pinDP, boolean anode) {
    if (anode) {
        anodeDisplay = 1;
    }
    else {
        anodeDisplay = 0;
    }
    pins[0] = pinA;
    pins[1] = pinB;
    pins[2] = pinC;
    pins[3] = pinD;
    pins[4] = pinE;
    pins[5] = pinF;
    pins[6] = pinG;
    pins[7] = pinDP;


    for (int i = 0; i < 8; i++) {
        pinMode(pins[i], OUTPUT);
        if (anodeDisplay) {
            digitalWrite(pins[i], HIGH);
        }
        else {
            digitalWrite(pins[i], LOW);
        }
        
    }
}

void SevenSegmentDisplay::displayCharacter(char character) {
    byte errorToDisplay = B01111111;  //  On error display empty screen.
    byte characterToDisplay[] = {
        B00001000,  //  A
        B00000011,  //  B
        B01000110,  //  C
        B00100001,  //  D
        B00000110,  //  E
        B00001110,  //  F
        B01000010,  //  G
        B00001011,  //  H
        B01001111,  //  I
        B01100001,  //  J
        B00001010,  //  K
        B01000111,  //  L
        B01101010,  //  M
        B01001000,  //  N
        B01000000,  //  O
        B00001100,  //  P
        B00011000,  //  Q
        B01001100,  //  R
        B00010010,  //  S
        B00000111,  //  T
        B01000001,  //  U
        B01010001,  //  V
        B01010101,  //  W
        B00001001,  //  X
        B00010001,  //  Y
        B00110100,  //  Z
    };
    byte numberToDisplay[] = {
        B01000000,  //  0
        B01111001,  //  1
        B00100100,  //  2
        B00110000,  //  3
        B00011001,  //  4
        B00010010,  //  5
        B00000010,  //  6
        B01111000,  //  7
        B00000000,  //  8
        B00010000,  //  9
       
    };

    boolean bitToWrite;
    for (int segment = 0; segment < 7; segment++) {
        if (character >= '0' && character <= '9') {
            bitToWrite = bitRead(numberToDisplay[character - '0'], segment);
        }
        else if (character >= 'a' && character <= 'z') {
            bitToWrite = bitRead(characterToDisplay[character - 'a'], segment);
        }
        else if (character >= 'A' && character <= 'Z') {
            bitToWrite = bitRead(characterToDisplay[character - 'A'], segment);
        }
        else {
            bitToWrite = bitRead(errorToDisplay, segment);
        }
        if (anodeDisplay) {
            digitalWrite(pins[segment], bitToWrite);
        }
        else {
            digitalWrite(pins[segment], !bitToWrite);
        }
       
    }
}

void SevenSegmentDisplay::displayDecimalPoint(boolean on) {
    if (anodeDisplay) {
        digitalWrite(pins[7], !on);
    }
    else {
        digitalWrite(pins[7], on);
    }
}

void SevenSegmentDisplay::testDisplay() {
    for (int i = 0; i <= 9; i++) {
        displayCharacter( (char)('0' + i));
        delay(500);
    }
    for (int i = 0; i <= 25; i++) {
        displayCharacter((char)('A' + i));
        delay(500);
    }
}