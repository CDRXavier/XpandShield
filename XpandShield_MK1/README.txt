XpandShield
Expansion Shield with multiple I/O for Arduino boards. Arduboy-compatiable pins.

MK1_0 is retired and is kept for archival reasons. It's the green shield.

MK1_1 is a "small" sized shield with no expansion area or battery connector.

MK1_1_2 is a "large" shield with no battery circuit and a large expansion area.

MK1_2 is the blue shield shown in the pictures (on Hackster and elsewhere). It have the size of a "large" Arduino, have 6 buttons, a display, a expansion header, a beeper, a RGB LED, a charging circuit mount, and a small expansion area (roughly 1/3 of a small proto shield). This is also retired.

MK1_3 replaces MK1_2, with the charging module replaced with a MAX1811 (instead of a breakout), along with a few other components like charging LED and resistors.
______
To Do

IDK
______
Components

Note: Some components used in the shield is subjected to change as parts availability might render some components scarce.

Two rows of male, 2.54mm (or 0.1 inch) standard pins/header go to the left and right edges of the board. A additional row of male pins go to the center "expansion port", which is optional.
For regular Arduino boards, you need 35 pins, a additional 7 for display, and a additional 11/12 for the expansion connector.
For big Arduino boards, you need 51 pins, a additional 7 for the display, a additional 11/12 for the expansion connector, and a additional 36 pin for the Digital connector.
You need a 2x3 female pin/headers for the ICSP. We will be using those connections on all boards.

Six two-lead buttons are required. The exact type of buttons used are up to you. You can get the cheap square ones and cut off two legs, or step up and go with the tactile buttons for a USB mice. Or anything in betweeen.
Four multi-turn adjustable resistors are recommded. You can use fixed-valued resistors instead, connecting the middle (or the rightmost) pad and the leftmost pad.
A fixed-value resistor is required. One is for the indicator LED, and is (to personal discretion) between 3K and 20K ohms.

Depend on the Arduino board used, the current limited by the onboard USB port fuse is 500mA or 900mA (even if the USB port is able to supply more). Drawing more current will cause the voltage to drop rather quickly (before the fuse trips). Don't feed power to hungry component (e.g. large servos/motors/heater/amplifier)

Always pick the current that is equal (or less) than the capacity of the battery you are using. For example, if we are using a 400mAh battery, then we can charge it with no more than 400 mA. If you are using low quality or cheap batteries, I recommend 75% of the value derived from the rated capacity.

For MAX1811, pull the current select high for 500mA and low for 100mA.
For LTC4056, "in constant current mode the typical charge current is 915 times the current through this resistor. Current is limited to approximately 1.4mA (charge current of approimately 1.4A)"

Pick any beeper that fit. The openings for the leads fit 5.08mm (2 * 2.54mm) ones or 7.62mm (3 * 2.54mm) ones. Remember that the beeper must NOT be "continuous" or "with source" (i.e. beeps when fed power) but are instead "not sourced" (i.e. click once when fed power). A dumb piezo buzzer.
You CAN use a speaker, but the resistance must be at least 500 ohms. You can wire resistors in series to increase the value.

Now, the display.
Long story short, pick any display you can find that says BOTH "SSD1306" AND "SPI" in the description. It MUST be SSD1306 and it MUST be SPI. On some breakout you have a option to choose between the SPI interface and the I2C interface. Make sure they are on the SPI mode.
A good display of this type should have SEVEN pins. They are, with the display facing you, from left to right, GND (ground), VCC(5V), CLK(clock), MOSI(master out serial in) or COPI (controller out peripheral in), RES(reset), DC, and CS(chip select). Sometimes the pins are labaled D0 and D1 and they probably indicate CLK and MOSI. Just align the leftmost pin and it will work. Some boards do not have the CS pin and its okay, but if you want to use the shield with the feeArducart, or any other SPI devices, there will be issues because the display will be always selected.

You might run out of patience and grab whichever 0.96 inch one (of perhaps the worst color you can imagine), or you can spent a lot of time and eventually come around some nice 1.3 inch white ones with 7 pins like I did. Shenzhen is a wonderful place, in this regard.

Now, the power switch.
The switch is of DPDT (double pole double throw) type. Whether it is a sliding switch or a push-button switch, it's your preference. The pins are a 3*2@2.54mm grid.
...
Okay. I just spent about 15 minutes looking for a place for the "DPDT sideways locking pushbutton" I got. And I couldn't find it.
It's by Toneluck. And the reason I chose it is because ... well, let me tell you a story.
Quite a few years ago I made my first toy that I am very happy about. It was a toy three-wheeler with a powered omnidirectional wheel and two trailing wheels. I looked at the pile of (unorganized) electronic parts and I found one of these. And I used it on the motor. The LED headlight received a cheap small sliding switch. Despite the (significantly) smaller load, the small sliding switch had wore out (despite seeing few uses), while the pushbutton still works perfectly.
So, this time, I go out and tried to look for that same switch I used on this three-wheeler. The one on my three-wheeler had no markings, but it look practically identical to this Toneluck one I found.
(still looking for DPDT switches)
Well, I do not want to use those square ones with the button sticking out from the top. Those ... I didn't have a good memory working with those. (a.k.a. the quality is usually horrible).
You had a few (DPDT 2.54mm pitch) switches. I saw a few from C&K. NKK too. A few from TE Connectivity. Also a few Alps.

Don't ask me about the LEDs. They are 3mm thru-hole. They are available literally everywhere. You need at least one of each of red, green, blue. But if you are lazy you can just grab whichever color you came across.

The diode is a SR-240. A SR-220 should also work. They are also available at most places.

Experiment with (both 6V and 16V) PPTC rated at 0.75A do not see tripping at current rated at 1A. The resistance is quite low, however. But still.
I did NOT include battery protection ICs because the only ones I find are TSSOPs, which are impossible to solder by hand. Use batteries with protection ICs.

There will be a place for a filter cap. Pick the ceramic capacitor with the largest capacitance you can find.
______
The Board Files

This folder houses the XpandShield (main) project, including the schemantics. Download this folder, then open this project file.
In the project navigator, you can select the two sub-projects (that actually contain the board and the layers and stuff).
You can also skip ahead and open the sub-projects directly.

To make changes to the board (to accomondate different parts availability), you must have the KiCad software.
Then you can either change the PCB to fit your liking, or you can just fabricate it "as is".
To prepare files for fabrication, you need to open up the pcb file (kicad.pcb).
Select "Export" or "Fabrication Outputs" under "Files". Then choose the appropriate file format the company asks for. Drill files are also required (mostly the pth and npth format)

Note: When fabricating, it is up to you if you want to print the (white) "comment" markings (the "cmts_user" layer) onto the board or not. They serve as a guidance during assembly, but might interfere with solder pads and might cost extra. You can always refer to the PCB or the photos.
______
Assembly
For unknown reasons, the signal pins on the charging IC is disconnected from the rest of the circuit -- instead of a piece of copper trace you have two jumper pins. Connect those together with jumpers. Or a small value resistor. I'm not sure why I decided to do that. Maybe as a mean to protect the signal pins on the IC from overcurrent.
And, because having that choice is better than not having one, I guess I will leave it there. Although I still don't understand why will I put it there in the first place.

It is recommended that you solder the MAX1811 first (the "dot" or the ridge facing AWAY from the proto area), then the central "expansion connector", followed by the ICSP header, followed by others. The outside pins go last, after you clipped away the extra leads of all of the other components because they "gets in the way". The screen goes after the outside connectors.
______
______
All of the information about the shield itself is contained above. For others, read below.
______
______
Compatiable Boards

Currently, all shields works 100% with Arduino Leonardo and Arduino Due.
To use with Leonardo (or use Due's Wire1, together with external pull-up resistors), short the two upper "version select" holes. (they are thru-hole vias, so it doesn't matter if they are connected on both sides or just one). To use Due's Wire0 (the default one with pull-up resistors), short the lower two. Do NOT connect the upper one with the lower one as it causes undefined behavior (unless on Leonardo, where the lower pins are unavailable).

If using "MK1_1" with Due, external pull-up resistors is required on Wire1 pins.

"Partial compatiable" boards
Arduino Mega -- it had not been tested with.
To use IIC with Arduino Mega, short the upper two of the "version select" pads.

Arduino Zero -- it had not been tested with.
To use IIC with Arduino Zero, short the upper two of the "version select" pads.

Uncompatiable Boards

Arduino UNO
You cannot use the display, the RGB LED and the beeper correctly (without modifications) because pin 13,12,11 are duplicates of the MOSI, MISO, and SCK found at the ICSP header. Furthermore, A0 and A1 is SCL and SDA, so function for up and down buttons are not guaranteed -- and is unuseable if you plan on using hardware I2C.
______
Code/sketch/program

The library for the XpandShield is here! To use the library, you need to move the XpandShield_Lib folder into the "libraries" folder in your personal Arduino folder.
The library should also be added to the Arduino library manager (as soon as the process is complete).

Example sketches are in the "Sketches" folder. The "_OLD" version is preserved for historical reasons.

With Arduino Leonardo, it support unmodified Arduboy binary, as well as full support of Arduboy, Arduboy2, and Arduboy Homemade libraries. All of the code posted in relative projects works as well -- provided that all the parts adhere to the requirements.

Currently, Arduboy code will compile for Arduino Mega. However, compatiability had not been tested.

Arduino Due and Arduino Zero lie at the place where they would have partial support (because they lack EEPROM), but otherwise have more than the hardware capabilities of the Leonardo.

The code will neither compile for Arduino Uno nor does it physically support the connectivity Arduboy requires. Cutting corners may be possible, but there will be no support on that.
