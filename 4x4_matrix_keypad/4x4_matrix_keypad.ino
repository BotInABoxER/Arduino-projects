/* Based on CustomKeypad.pde by Alexander Brevig (alexanderbrevig@gmail.com)
   Uses 4x4 Matrix Keypad to play music on https://onlinesequencer.net/
   
   ---
   Requires: An Arduino Leonardo or compatible (https://bit.ly/2PiN6LN)
             A Computer with the Arduino IDE or Web Editor installed (https://www.arduino.cc/en/Main/Software)
             A Micro USB Cable 
             A 4x4 Matrix Keypad (https://bit.ly/2MYLtVV)
             8 Male-to-Female Dupont Jumper Wires (https://ebay.to/2NunbAh)
             Arduino Keyboard Library (https://github.com/arduino-libraries/Keyboard)
             Arduino Keypad Library (https://playground.arduino.cc/code/keypad#Download)
   
   ---
   Setup: Connect the pins on the keypad to Digital Pins 2-9 on the Arduino (Leonardo)
   using Male-to-Female Dupont Jumper Wires
   
   ---
   How to Play: Plug Arduino Leonardo into computer via USB port.
   Follow chart below for keymappings (make sure all the cables are connected properly)

          ----------------------
         | O     23456789     O |   
         |                      |
         |    G6  F6  E6  D6    |
         |                      |
         |    C6  B5  A5  G5    |   
         |                      |
         |    F5  E5  D5  C5    |
         |                      |
         |    B4  A4  G4  F4    |
         | O                  O |
          ----------------------
          
  ---        
  Troubleshooting: Make sure all the jumper cables are connected properly, then try rearranging the rowPins and colPins if necessary.
  
  ---
  Optional: The keypad looks nice with a 3D Printed enclosure like https://www.thingiverse.com/thing:2229746 (You may need to widdle it
  with an Xacto knife for a snug fit. If you don't have any screws for it, regular tape works just as well for attaching the two halves.)
  
  ---
  License: MIT License 
  Copyright (c) 2018 Bot-In-a-Box Educational Robotics

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
  
*/

#include <Keypad.h>
#include <Keyboard.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'O','P','[',']'},
  {'T', 'Y' ,'U','I'},
  {'Q','W','E','R'},
  {'F','G','H','J'}
};
byte rowPins[ROWS] = {6, 7, 8, 9}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  Keyboard.begin();
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    Serial.println(customKey);
    Keyboard.print(customKey);
  }
}
