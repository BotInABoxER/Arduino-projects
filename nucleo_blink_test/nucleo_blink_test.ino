/* Based on https://www.instructables.com/id/Quick-Start-to-STM-Nucleo-on-Arduino-IDE/ by User sriksh9 (https://www.instructables.com/member/sriksh9/)

   Blinks the Onboard LED of an STM32 Nucleo Board
   
   ---
   Requires: An STM Nucleo Board (https://bit.ly/f446re-botinabox)
             A Computer with the Arduino IDE installed (https://www.arduino.cc/en/Main/Software)
             A Mini USB Cable (https://bit.ly/miniusb-botinabox)
             The ST Micro USB Driver (https://bit.ly/2MCx4zl)
             

   ---
   Setup: Open the Arduino IDE, go to the File tab, and click on Preferences.
          Enter https://raw.githubusercontent.com/stm32duino/BoardManagerFiles/master/STM32/package_stm_index.json into the "Additional Boards Manager URLs" box.
          Click on OK to close the Preferences window.
          
          Click on the Tools tab, then click on Board.
          From the dropdown, click on Boards Manager.
          
          Scroll down the list and select STM32 Core package, then click on the Install button.
          Download sriksh9's Nucleo Header Remap library from https://github.com/sriksh9/Nucleo-PinMapping-for-Arduino as a ZIP file.
          
          Extract the ZIP file, and copy the Nucleo_map folder inside to the Arduino/libraries folder in your Documents folder.
          Click on the Tools tab back in the Arduino IDE.
          Click on Board, scroll down to Nucleo-64 and click on it.
          Click the Tools tab again, and select the Board part number menu.
          Click on the part number of your board (found on the back - if you bought the one from Ebay it's Nucleo F446RE).

          Connect the USB cable to your board and computer.
          Click on the Tools tab again, then click on Port, and select the Port to which your board is connected.

          (Alternatively, try saving the Arduino sketch and moving it to the Nucleo board, as it should show up as a USB Drive.)

          Refer to https://bit.ly/2MC8zCq for help with the Pin Headers Remap.

          For other help, create an issue on the Botinaboxer/arduino-projects repo.

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
#include <f401reMap.h>

int a = pinMap(12); //pinMap(Mapped Pin)
int b = pinMap(1);
void setup()
{
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
}

void loop()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  delay(500);
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  delay(500); 
}
