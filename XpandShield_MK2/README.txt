XpandShield MK2

Expansion shield featuring multiple high-speed analog (and digital) inputs and a OLED for output.

With 6 analog input via two joysticks and two linear actuator, the potential is almost endless. Plus a on-board high speed display and quite a few extra buttons, this will be all you need to make advanced projects requiring analog inputs. USB gamepad/mouse/keyboard/controller? You bet. Programmable robot control? Sounds very decent. Or just another fancy Arduboy? Well, that works too, if you want.

______
To Do

Write up everything

Features:
Two ThumbPointer™ (with center push)
DPad (currently using 4 independent pushbuttons)
6-buttons (abcxyz) + 4 shoulder (L1R1L2R2)
1.3 inch (or 0.96 inch) SSD1306 OLED
two linear potentialmeters
menu, start, select button
stick-type switch (8 direction + center push)

Utilizing three 74HC165D parallel-load shift registers connected to SPI bus in daisy chain along with a tri-state buffer allow for fast reads of the button state, while the six analog channels provide 10 bit analog read for the six sticks.
______
Components

The board is designed so it is not required to wire every single button to operate it. You can fit up to 13 two-lead tactile switch, four sideways push button, two Thumbpointer RKJXV series (with or without center push or return), a RKJXM stick-type switch (cost quite a pretty penny), and two RS**1 SuperSlide (with 30mm of travel), with or without the metal mounting leads.
And a SSD1306 128*64 SPI display.

You will then need a arduino micro. yes. micro. not pro micro, not pro mini, Arduino Micro. I support official Arduino product.

After that, you will need the pull down resistor arrays.
For every four button (the stick-type switch count as 5 for the matter, and each push button from a thumbpointer count as one), you will need one of these "Resistor Networks & Arrays 20K 5% CONVEX SQUARE 4X0603".

I believe the concave ones also work -- they will do the job of 4x resistors just fine, the problem is whether they will fit on the board. Some will, some won't. Some is a complete pain in the arse to solder. Some is a complete blast.

The pins for the resistor (at minimum, the non-common pins going to different register pins) MUST BE SEPARATED. The side that are joined together (to GND) may be connected but it's best to separate them.

You then need 3 (or two, or one. depend on which buttons you want). 74HC165 SOP16 parallel to serial shift registers. Mine come from NXP. It doesn't mean the one from Ti doesn't work -- they will work. Just make sure they are 74HC165.

Then you need a tri state buffer from Ti. The mythical SN74AUP1G125.
Make sure it's the 125 and not the SN74AUP1G126, as the 125 have the inverted "output enable" while the 126 have a non-inverted signal.

If you do NOT want to solder such a component, you can connect the middle pin to the lower pin (the "A" to the "Y"). But this is not recommended because when the mcu is not polling the buttons, the line will be kept low/high (depend on the first bit of the first register) because the SN74HC165 does not have a tri state output. And this will interfere with anything else connected on the MISO line. Right now it will work because we don't have another device that uses MISO.

There is a place to put a ceramic capacitor in between two buttons(signaled by the thru hole pads). Put a 1uF-10uF ceramic capacitor there.

______
Assembly
Surface mounted modules first. Specifically the 0306 resistors because they are so small, you can easily break the board by heating for too long. Then the buttons, joystick, and the other stuff.

______
Compatiability

The board only supports Micro. However, because the pins for the display is wired up, a arduboy sketch will have no trouble driving the display. Even the direction buttons are somewhat solved as the analog sticks are able to provide the necessary voltage levels for the system to register a logic low. However all the buttons are wired to the shift registers and special code is needed to pull them out from those.
______
Library
There is a library for XpandShield MK2. To use it, "download the MK2_Lib folder and put it into the Arduino's library folder.

There are example sketches. And there will be more example sketches. They are under the Sketches folder.
___
"Upcoming" features

Analog shoulder triggers? I'll try to source parts, but I don't think there are much options. I don't make entire devices ... yet.
RGBLED output?
Proto area (for your wireless modules)?
Battery circuit & connector(?)
Vibrating motor (?)

Note:
MK2_0 and MK2_-1 are preserved for historical reasons.
Inside the RN-42 folder are firmwares for the RN-42 module, supposedly needed to be flashed onto HC-05 or other compatiable Bluetooth boards with the BC352 processor.
