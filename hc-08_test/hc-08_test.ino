/* Uses a HC-08 Bluetooth Low Energy (BLE) Module to blink an LED on an Arduino Nano using an iOS device with the ArduinoBlue app.
   This program is for testing out your HC-08, and can be used as a template for further prototyping. 
   
   ---
   Requires: An Arduino Nano or compatible (https://bit.ly/nano-botinabox)
             A Computer with the Arduino IDE or Web Editor installed (https://www.arduino.cc/en/Main/Software)
             A Micro USB Cable (https://bit.ly/microusb-cable-botinabox)
             Four Female-to-Female Dupont Jumper Wires (https://bit.ly/dupont-ftf-botinabox)
             A HC-08 BLE Breakout Board (https://bit.ly/hc08-botinabox)
             (Optional) An Arduino Nano Sensor Shield (https://bit.ly/nano-senshield-botinabox)
             The SoftwareSerial Library for Arduino (https://www.arduino.cc/en/Reference/SoftwareSerial) - should be included with the Arduino IDE
             An iPad/iPhone with the ArduinoBlue app installed (https://itunes.apple.com/us/app/arduinoblue/id1340487989?mt=8)

   ---
   Setup: Connect the RX pin to the TX pin on your Arduino.
          Connect the TX pin to the RX pin on your Arduino
          Connect the GND pin to the GND pin on your Arduino.
          Connect the VCC pin to the VCC or 5V pin on your Arduino.
          (When uploading code to your Arduino Nano, keep the module disconnected.)

          Upload this code to your Arduino (make sure ATMega328P (Old Bootloader) is selected in the Tools/Processor: menu after selecting Arduino Nano from the Tools/Board: menu)
          For some reason, Windows doesn't seem to want to upload code to any Arduino Nanos connected via USB 3. Find a 2.0 port if you're experiencing issues with connection.
          
          Make sure Bluetooth is enabled on your iOS device, then open the ArduinoBlue app and Find and Connect to the device in the app - not the device's Bluetooth settings (it should show up as HC-08 or something like that).

          Go to the Command Tab at the bottom of the screen and send the character a. The status LED on the Arduino Nano should blink.

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

#include <SoftwareSerial.h>
SoftwareSerial mySerial(0, 1); // RX, TX
#define PIN 13

void setup() {
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0) { 
    char data;
    data = Serial.read();
    Serial.write(Serial.read());
      switch (data)
      {
        case 'A': 
          digitalWrite(13, HIGH);
          delay(3000);
           break;
           
        default:
        digitalWrite(13,LOW);
      }
    
  }
    
}

