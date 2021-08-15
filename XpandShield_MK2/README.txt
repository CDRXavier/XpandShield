XpandShield MK2

Expansion shield with multiple I/O. Features multiple analog (and digital) inputs.

With 6 analog input via two joysticks and two linear actuator, the potential is almost endless. Plus a on-board high speed display and quite a few extra buttons, this will be all you need to make advanced projects requiring analog inputs. USB gamepad/mouse/keyboard/controller? You bet. Programmable robot control? Sounds very decent. Or just another fancy Arduboy? Well, that works too, if you want.

______
To Do

Make everything
Write up everything

Features:
Two analog stick (with center push)
DPad (currently using 4 independent pushbuttons)
6-buttons (abcxyz) + 4 shoulder
1.3 inch (or 0.96 inch) SSD1306 OLED
two Linear potentialmeters
menu, start, select button
stick-type switch


"Upcoming" features

Analog shoulder triggers? I'll try to source parts, but I don't think there are much options. I don't make entire devices ... yet.

RGBLED output?

Proto area (for your wireless modules)?

Battery circuit & connector(?)

Vibrating motor (?)
______


Utilizing three 74HC165D parallel-load shift registers connected to SPI bus in daisy chain along with a tri-state buffer allow for ultra-fast read of the button state (SPI bus operate at 8MHz).