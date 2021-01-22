# Letters and Numbers Seven Segment Display Library
[![Video showing the demo for the library usage](https://github.com/alikabeel/Letters-and-Numbers-Seven-Segment-Display-Library/blob/main/Extras/Video%20Demo.PNG)](http://www.youtube.com/watch?v=6GbRylG605I)

 This is an Arduino library for displaying letters and numbers on a 7-segment display (single digit 7-segment display). The library supports both anode and cathode displays and using the library you can display letters (A-Z) & numbers (0-9). The library makes displaying letters & numbers as easy as passing the number/letter as an argument to a function. The library also offers the ability to control the decimal point of the 7-segment using a function call. This makes the whole usage of the 7-segment very seamless and abstracts the whole usage of the device.
 
 ## Download
 To download the library you can download it directly by downloading this repo as ZIP and later import it into your Arduino IDE. Alternatively, you can download the library directly from the library manager in Arduino IDE. Both ways are covered in details [here](https://www.arduino.cc/en/guide/libraries).
 ## Usage
#### To import the library into your sketch you can either include it via the Arduino IDE [here](https://www.arduino.cc/en/guide/libraries). Alternatively, You can use the following line to import the library into your sketch:
```
#include <SevenSegmentDisplay.h>
```
#### To instantiate a seven segment display object to use it to control the seven segment display you can use the following line:
```
 SevenSegmentDisplay screenName(A_pin, B_pin, C_pin, D_pin, E_pin, F_pin, G_pin, DP_pin, isAnodeDisplay);
```
As shown above the constructor of the SevenSegmentDisplay object takes as arguments the pins to which the 7 segment display are connected to in addition to a boolean flag which indicates whether the display is anode indicated by setting the flag to (true) or cathode which is indicated by setting the flag to (false). The following diagram show the position of each pin in the 7-segment display:
[![Image showing the position of the 7 segment display pins](https://github.com/alikabeel/Letters-and-Numbers-Seven-Segment-Display-Library/blob/main/Extras/pin%20diagram.png)](https://github.com/alikabeel/Letters-and-Numbers-Seven-Segment-Display-Library/blob/main/Extras/pin%20diagram.png).

As an example of instantiating the object:
```
 SevenSegmentDisplay screenName(2, 3, 4, 5, 6, 7, 8, 9, true);
```
This creates a new anode SevenSegmentDisplay object with pins connected to pins (2-9) in the Arduino board.

#### Currently the library offers the following functions:

<b> 1. displayCharacter(char c):</b>
This function allows the user to draw any letter/number onto the display by just invoking the function on the SevenSegmentDisplay object and passing the desired character (case insensitive) to the function. For example:
```
screenName.displayCharacter('A');
```
In case of passing an unsupported character all the LEDs of the 7-segment will turn off indicating the occurance of an error.

<b> 2. displayDecimalPoint(boolean isTurnedOn):</b>
This function allows turning on and off the deciaml point of the 7-segment display by passing a boolean flag indicating whether the decimal point should be on or off. For example:
```
screenName.displayDecimalPoint(false);
```
<b> 3. testDisplay():</b>
By calling this function, the 7-segment will show all the numbers (0-9) followed by all letters(A-Z) in order to test that the 7-segment is fully functional and can display all the supported letters and numbers. For example:
```
screenName.testDisplay();
```

## Letters & Numbers Map
The following figure shows the mapping of the supported characters on the 7-segment display:

[![Image showing the mapping of numbers on the 7 segment display](https://github.com/alikabeel/Letters-and-Numbers-Seven-Segment-Display-Library/blob/main/Extras/NumbersMap.PNG)](https://github.com/alikabeel/Letters-and-Numbers-Seven-Segment-Display-Library/blob/main/Extras/NumbersMap.PNG).
[![Image showing mapping of letters on the 7 segment display](https://github.com/alikabeel/Letters-and-Numbers-Seven-Segment-Display-Library/blob/main/Extras/Letters1Map.PNG)](https://github.com/alikabeel/Letters-and-Numbers-Seven-Segment-Display-Library/blob/main/Extras/Letters1Map.PNG).
[![Image showing mapping of letters on the 7 segment display](https://github.com/alikabeel/Letters-and-Numbers-Seven-Segment-Display-Library/blob/main/Extras/Letters2Map.PNG)](https://github.com/alikabeel/Letters-and-Numbers-Seven-Segment-Display-Library/blob/main/Extras/Letters2Map.PNG).


## Connecting 7-Segment Display Diagram

#### Connecting Anode 7-Segment Display

[![Image showing connecting anode 7 segment display](https://github.com/alikabeel/Letters-and-Numbers-Seven-Segment-Display-Library/blob/main/Extras/Connecting%20Anode%207-segment%20Display.png)](https://github.com/alikabeel/Letters-and-Numbers-Seven-Segment-Display-Library/blob/main/Extras/Connecting%20Anode%207-segment%20Display.png).


#### Connecting Cathode 7-Segment Display
[![Image showing connecting cathode 7 segment display](https://github.com/alikabeel/Letters-and-Numbers-Seven-Segment-Display-Library/blob/main/Extras/Connecting%20Cathode%207-segment%20Display.png)](https://github.com/alikabeel/Letters-and-Numbers-Seven-Segment-Display-Library/blob/main/Extras/Connecting%20Cathode%207-segment%20Display.png).

<b> Note: </b> Some 7-segment displays require the addition of resistor to prevent burning the screen. Always refer to the specific datasheet of your display before connecting it. The diagram is for general guidance only.
## Contribute
All contributions are very much welcomed. You can contribute by opening an issue and suggesting an addition to the library or by issuing a pull request and adding whichever feature you deem useful.

## License
This library is offered under the MIT license. Please check [this](LICENSE) for more info.
