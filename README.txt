XpandShield
Expansion Shield with multiple I/O. Compatible with Arduboy.
______
To Do
Experiment with some 6V (widely unavailable) 12V(rarely available) and 16V(plentiul supply) PPTC and evaluate if they are adequate (e.g. their resistance might be too high/low)

Update the board with more comments.

My own library for the Arduino Due (that aim to semi-support Arduboy sketches) is in the workings (and will be uploaded here). However, note that the Arduino Due do not have EEPROM.



______
Components
Two rows of male, 2.54mm (or 0.1 inch) standard pins go to the left and right edges of the board. A additional row of male pins go to the center "expansion port".
Six two-lead buttons are required. The exact type of buttons used are up to you. You can get the cheap square ones and cut off two legs, or step up and go with the tactile buttons for a USB mice. Or anything in betweeen.
Four multi-turn adjustable resistors are recommded. You can use fixed-valued resistors instead, connecting the middle (or the rightmost) pad and the leftmost pad.
Two fixed-value resistors are required. One is for the two indicator LEDs (because they only light up one at a time), and is (to personal discretion) between 3K and 10K ohms. The other one is the current-limiting resistor, whose relationship is shown below:

Resistance | Current
  (kΩ)     |  (mA)
   10      |   130
   5       |   250
   4       |   300
   3       |   400
   2       |   580
   1.66    |   690
   1.5     |   780
   1.33    |   900
   1.2     |   1000

I recommend one between 3K and 2K. Depend on the Arduino board used, the current limited by the onboard USB port fuse is 500mA (even if the USB port is able to supply more). Drawing more current will cause the voltage to drop rather quickly (before the fuse trips).

Always pick the current that is equal (or less) than the capacity of the battery you are using. For example, if we are using a 400mAh battery, then we can charge it with no more than 400 mA (which, if it is rated correctly, full-charge it in exactly an hour). If you are using low quality or cheap batteries, I recommend 75% of the rated capacity.

Pick any beeper that fit. The openings for the leads fit 5.08mm (2 * 2.54mm) ones or 7.62mm (3 * 2.54mm) ones. Remember that the beeper must NOT be "continuous" or "with source" (i.e. beeps when fed power) but are instead "not sourced" (i.e. click once when fed power, click once when disconnected from power).

Now, the display.
Long story short, pick any display you can find that says BOTH "SSD1306" AND "SPI" in the product title. Some of the boards give you a option to choose between the SPI interface and the I2C (or IIC/TWI) interface. Make sure they are on the SPI mode.
A good display of this type should have SEVEN pins. They are, from left to right, GND (ground), VCC(5V), CLK(clock), MOSI(master out slave in), RES(reset), DC, and CS(chip select). Some boards do not have the CS pin and its okay, but if you want to use the shield with the Arducart, or any other SPI devices, there will be issues because the display will be always selected.

You might run out of patience and grab whichever 0.96 inch one (of perhaps the worst color you can imagine), or you can spent a lot of time and eventually come around some nice 1.3 inch white ones with 7 pins like I did.

Now, the switch.
The switch is of DPDT (double pole double throw) type. Whether it is a sliding switch or a push-button switch, it's your preference. The pins are a 3*2 2.54mm grid.
...
Okay. I just spent about 15 minutes looking for a place for the "DPDT sideways locking pushbutton" I got. And I couldn't find it.
It's by Toneluck. And the reason I chose it is because ... well, let me tell you a story.
Quite a few years ago I made my first toy that I am very happy about. It was a toy three-wheeler with a omnidirectional wheel and two trailing wheels. I looked at the pile of (unorganized) electronic parts (back at that time) and I found one of these. And I used it on the motor. The LED headlight received a cheap small switch. Despite the larger load, the small sliding switch had wore out (despite seeing few uses), while the pushbutton still works perfectly.
So, this time, I go out and tried to look for that same switch I used on this three-wheeler. The one on my three-wheeler had no markings, but it look practically identical to this Toneluck one I found.
(still looking for DPDT switches)
Well, I do not want to use those square ones with the button sticking out from the top. Those ... I didn't have a good memory working with those.
You had a few (DPDT 2.54mm pitch) switches. I saw a few from C&K. NKK too. A few from TE Connectivity. Also a few Alps.

Don't ask me about the LEDs. They are 3mm thru-hole. They are available literally everywhere. You need at least one of each of red, green, blue.

The diode is a SR-240. A SR-220 should also work (but is not guaranteed since I didn't test it). They are also available at most places.
______
Fabricating the board
To make changes to the board (to accomondate different part availability), you must have the KiCad software.
Then you can either change the PCB to fit your liking (since everything is licenced under GPL v2.0 or later), or you can just fabricate it "as is", if you manage to get everything.
To prepare files for fabrication, you need to select "Export" or "Fabrication Outputs" under "Files". Then choose the appropriate file format the company asks for.

Note: When fabricating, it is up to you if you want to print the (white) "comment" markings onto the board or not. They serve as a guidance during assembly, but you can always refer to the PCB or the photos.
______
Assembly
It is recommended that you solder the TP-4056 (if available) first, then the central "expansion connector", followed by the ICSP header, followed by buttons / resistors / LED / screenPins / beeper / switch / batteryConnector in any order. The outside pins go after you clipped away the extra leads of all of the other components because they "gets in the way".
______
______
All of the shield's information is contained above. For others, read below.
______
______
Compatiable Boards

Currently, The v2_X version (3v3 wired LED and IIC "version select") of the shield works 100% with Arduino Leonardo and Arduino Due.
To use with Leonardo (or use Due's Wire1, together with pull-up resistors), short the two upper "version select" holes. To use Due's Wire0 (the default one with pull-up resistors), short the lower two. Do NOT connect the upper one with the lower one. It causes undefined behavior.

The v1_X version (5V wired LED) work 100% with Arduino Leonardo.

"Partial compatiable" boards
With Arduino UNO, you cannot use the display, the RGB LED and the beeper correctly (without modifications) because pin 13,12,11 are duplicates of the MOSI, MISO, and SCK found at the ICSP header. Furthermore, A0 and A1 is SCL and SDA, so function for up and down buttons are not guaranteed -- and is unuseable if you plan on using hardware IIC.

Arduino Mega do not display any of the "incompatiable-ness" of the Arduino UNO, despite using similar MCUs. However it had not been tested with.
To use IIC with Arduino Mega, short the upper two of the "version select" pads.

Arduino Zero also do not display any of the "imcompatiable-ness" of the Arduino UNO, however it had not been tested with.
To use IIC with Arduino Zero, short the upper two of the "version select" pads.

You can use v1_X (5V LED) boards on any 3v3 Arduino (Due, Zero, etc.), provided that you do not solder the LEDs.
______
Code/sketch/program

Arduino Leonardo support unmodified Arduboy sketch binary (without bootloader), as well as full support of Arduboy, Arduboy2, and Arduboy Homemade libraries. All of the code posted in relative projects works as well -- provided that the parts adhere to the requirements.

Currently, Arduboy code will compile for Arduino Mega. However, compatiability had not been tested.

Arduino Due and Arduino Zero lie at the place where they would have partial support (because they lack EEPROM), but the library is not there yet.

The code will neither compile for Arduino Uno nor does it physically support the connectivity Arduboy requires. Cutting corners may be possible, but there will be no information on that. Proceed on your own.
