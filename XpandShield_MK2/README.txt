XpandShield MK2

Expansion shield with multiple I/O. Features multiple analog (and digital) inputs.

With 6 analog input via two joysticks and two linear actuator, the potential is almost endless. Plus a on-board high speed display and quite a few extra buttons, this will be all you need to make advanced projects requiring analog inputs. USB gamepad/mouse/keyboard/controller? You bet. Programmable robot control? Sounds very decent. Or just another fancy Arduboy? Well, that works too, if you want.

______
To Do

Make everything
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

There is a library for XpandShield MK2. To use it, download the MK2_Lib folder and put it into the Arduino's library folder.

There are example sketches. They are under the Sketches folder.
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
