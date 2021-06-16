EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr User 7000 7000
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text GLabel 900  1950 0    50   Input ~ 0
A0
Text GLabel 900  2100 0    50   Input ~ 0
A1
Text GLabel 900  2250 0    50   Input ~ 0
A2
Text GLabel 900  2400 0    50   Input ~ 0
A3
Text GLabel 900  2550 0    50   Input ~ 0
A4
Text GLabel 900  2700 0    50   Input ~ 0
A5
Text GLabel 4500 1500 2    50   Input ~ 0
13
Text GLabel 3000 2650 0    50   Input ~ 0
12
Text GLabel 3050 4000 2    50   Input ~ 0
11
Text GLabel 3050 4150 2    50   Input ~ 0
10
Text GLabel 3050 4300 2    50   Input ~ 0
9
Text GLabel 4550 1700 2    50   Input ~ 0
8
Text GLabel 4550 1850 2    50   Input ~ 0
7
Text GLabel 3100 2400 2    50   Input ~ 0
6
Text GLabel 4550 2150 2    50   Input ~ 0
5
Text GLabel 4550 2300 2    50   Input ~ 0
4
Text GLabel 4550 2450 2    50   Input ~ 0
3
Text GLabel 4550 2600 2    50   Input ~ 0
2
Text GLabel 3450 850  2    50   Input ~ 0
RX
Text GLabel 3450 1000 2    50   Input ~ 0
TX
Text GLabel 5800 900  2    50   Input ~ 0
SCK
Text GLabel 5800 750  2    50   Input ~ 0
SCL
Text GLabel 5800 1250 2    50   Input ~ 0
SCK0
Text GLabel 5800 1400 2    50   Input ~ 0
SCL0
$Comp
L power:+3V3 #PWR0101
U 1 1 6065C72D
P 750 900
F 0 "#PWR0101" H 750 750 50  0001 C CNN
F 1 "+3V3" V 765 1028 50  0000 L CNN
F 2 "" H 750 900 50  0001 C CNN
F 3 "" H 750 900 50  0001 C CNN
	1    750  900 
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR0102
U 1 1 6065CF80
P 750 1050
F 0 "#PWR0102" H 750 900 50  0001 C CNN
F 1 "+5V" V 765 1178 50  0000 L CNN
F 2 "" H 750 1050 50  0001 C CNN
F 3 "" H 750 1050 50  0001 C CNN
	1    750  1050
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 6065D427
P 750 1200
F 0 "#PWR0103" H 750 950 50  0001 C CNN
F 1 "GND" V 755 1072 50  0000 R CNN
F 2 "" H 750 1200 50  0001 C CNN
F 3 "" H 750 1200 50  0001 C CNN
	1    750  1200
	0    1    1    0   
$EndComp
$Comp
L Connector:Conn_01x12_Male J?
U 1 1 6065FA6A
P 2700 600
F 0 "J?" H 2672 482 50  0001 R CNN
F 1 "ExpandConnector" V 2672 573 50  0000 R CNN
F 2 "" H 2700 600 50  0001 C CNN
F 3 "~" H 2700 600 50  0001 C CNN
	1    2700 600 
	0    1    1    0   
$EndComp
$Comp
L Device:LED D?
U 1 1 606625E3
P 1100 4200
F 0 "D?" V 1047 4280 50  0001 L CNN
F 1 "LED_R" V 1200 4250 50  0000 L CNN
F 2 "" H 1100 4200 50  0001 C CNN
F 3 "~" H 1100 4200 50  0001 C CNN
	1    1100 4200
	0    1    1    0   
$EndComp
$Comp
L Device:LED D?
U 1 1 6066383B
P 1450 4200
F 0 "D?" V 1397 4280 50  0001 L CNN
F 1 "LED_G" V 1550 4250 50  0000 L CNN
F 2 "" H 1450 4200 50  0001 C CNN
F 3 "~" H 1450 4200 50  0001 C CNN
	1    1450 4200
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 6066404A
P 1600 1950
F 0 "SW?" H 1600 2250 50  0001 C CNN
F 1 "SW_UP" H 1600 2144 50  0000 C CNN
F 2 "" H 1600 2150 50  0001 C CNN
F 3 "~" H 1600 2150 50  0001 C CNN
	1    1600 1950
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 60665A44
P 1300 2250
F 0 "SW?" H 1300 2065 50  0001 C CNN
F 1 "SW_LEFT" V 1300 2050 50  0000 C CNN
F 2 "" H 1300 2450 50  0001 C CNN
F 3 "~" H 1300 2450 50  0001 C CNN
	1    1300 2250
	0    -1   -1   0   
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 606660C5
P 1900 2250
F 0 "SW?" V 1854 2398 50  0001 L CNN
F 1 "SW_RIGHT" V 1900 2398 50  0000 L CNN
F 2 "" H 1900 2450 50  0001 C CNN
F 3 "~" H 1900 2450 50  0001 C CNN
	1    1900 2250
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 606665A9
P 1600 2550
F 0 "SW?" H 1600 2365 50  0001 C CNN
F 1 "SW_DOWN" H 1600 2457 50  0000 C CNN
F 2 "" H 1600 2750 50  0001 C CNN
F 3 "~" H 1600 2750 50  0001 C CNN
	1    1600 2550
	-1   0    0    1   
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 6066694C
P 3550 1950
F 0 "SW?" H 3550 2235 50  0001 C CNN
F 1 "SW_B" H 3550 2143 50  0000 C CNN
F 2 "" H 3550 2150 50  0001 C CNN
F 3 "~" H 3550 2150 50  0001 C CNN
	1    3550 1950
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 60666F32
P 3550 2300
F 0 "SW?" H 3550 2585 50  0001 C CNN
F 1 "SW_A" H 3550 2493 50  0000 C CNN
F 2 "" H 3550 2500 50  0001 C CNN
F 3 "~" H 3550 2500 50  0001 C CNN
	1    3550 2300
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT_US RV?
U 1 1 606682D3
P 2550 4050
F 0 "RV?" H 2483 4096 50  0001 R CNN
F 1 "R_POT_US" V 2437 4050 50  0000 C CNN
F 2 "" H 2550 4050 50  0001 C CNN
F 3 "~" H 2550 4050 50  0001 C CNN
	1    2550 4050
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_POT_US RV?
U 1 1 606693D8
P 2550 4750
F 0 "RV?" V 2437 4750 50  0001 C CNN
F 1 "R_POT_US" V 2437 4750 50  0000 C CNN
F 2 "" H 2550 4750 50  0001 C CNN
F 3 "~" H 2550 4750 50  0001 C CNN
	1    2550 4750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3800 2300 3750 2300
$Comp
L Connector:Conn_01x07_Male J?
U 1 1 60683FEC
P 3300 3250
F 0 "J?" V 3227 3228 50  0001 C CNN
F 1 "Display" V 3227 3228 50  0000 C CNN
F 2 "" H 3300 3250 50  0001 C CNN
F 3 "~" H 3300 3250 50  0001 C CNN
	1    3300 3250
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_POT_US RV?
U 1 1 60668A05
P 2550 4400
F 0 "RV?" V 2437 4400 50  0001 C CNN
F 1 "R_POT_US" V 2437 4400 50  0000 C CNN
F 2 "" H 2550 4400 50  0001 C CNN
F 3 "~" H 2550 4400 50  0001 C CNN
	1    2550 4400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	900  1950 1400 1950
Wire Wire Line
	900  2100 1750 2100
Wire Wire Line
	1750 2100 1750 2050
Wire Wire Line
	1750 2050 1900 2050
Wire Wire Line
	900  2400 1100 2400
Wire Wire Line
	1100 2400 1100 2550
Wire Wire Line
	1100 2550 1400 2550
Wire Wire Line
	900  2250 1100 2250
Wire Wire Line
	1100 2250 1100 2050
Wire Wire Line
	1100 2050 1300 2050
Wire Wire Line
	1300 2450 1800 2450
Wire Wire Line
	1800 2450 1800 1950
Wire Wire Line
	1900 2450 1800 2450
Connection ~ 1800 2450
Wire Wire Line
	1800 2550 1800 2450
$Comp
L power:+3V3 #PWR0104
U 1 1 606A8EB2
P 1050 4550
F 0 "#PWR0104" H 1050 4400 50  0001 C CNN
F 1 "+3V3" V 1065 4678 50  0000 L CNN
F 2 "" H 1050 4550 50  0001 C CNN
F 3 "" H 1050 4550 50  0001 C CNN
	1    1050 4550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1050 4550 1100 4550
Wire Wire Line
	1450 4550 1450 4350
Wire Wire Line
	1100 4550 1100 4350
Connection ~ 1100 4550
Wire Wire Line
	1100 4550 1450 4550
Wire Wire Line
	1450 4550 1800 4550
Wire Wire Line
	1800 4550 1800 4350
Connection ~ 1450 4550
Wire Wire Line
	3750 1700 3750 1950
Connection ~ 3350 1950
Wire Wire Line
	2100 800  2100 900 
Wire Wire Line
	2100 900  750  900 
Wire Wire Line
	750  1050 2200 1050
Wire Wire Line
	2200 1050 2200 800 
Wire Wire Line
	2300 1200 2300 800 
Wire Wire Line
	2300 1200 2300 1600
Connection ~ 2300 1200
Wire Wire Line
	750  1200 2300 1200
Wire Wire Line
	2300 1600 1800 1600
Wire Wire Line
	1800 1600 1800 1950
Connection ~ 2300 1600
Connection ~ 1800 1950
Text GLabel 2150 3300 0    50   Input ~ 0
MISO
Text GLabel 2150 3450 0    50   Input ~ 0
MOSI
Text GLabel 2150 3600 0    50   Input ~ 0
SCK
Wire Wire Line
	2150 3300 2700 3300
Wire Wire Line
	2700 3300 2700 2800
Wire Wire Line
	2600 800  2600 2850
Wire Wire Line
	2600 3450 2150 3450
Wire Wire Line
	2150 3600 2500 3600
Wire Wire Line
	2500 3600 2500 800 
$Comp
L power:+5V #PWR0105
U 1 1 606B8352
P 3600 2850
F 0 "#PWR0105" H 3600 2700 50  0001 C CNN
F 1 "+5V" H 3615 3023 50  0000 C CNN
F 2 "" H 3600 2850 50  0001 C CNN
F 3 "" H 3600 2850 50  0001 C CNN
	1    3600 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 2850 3600 3050
Wire Wire Line
	3400 3050 3400 2800
Wire Wire Line
	3400 2800 2700 2800
Connection ~ 2700 2800
Wire Wire Line
	2700 2800 2700 800 
Wire Wire Line
	2600 2850 3300 2850
Wire Wire Line
	3300 2850 3300 3050
Connection ~ 2600 2850
Wire Wire Line
	2600 2850 2600 3450
Wire Wire Line
	3000 2650 3000 3050
Wire Wire Line
	3100 2400 3100 3050
Wire Wire Line
	3100 2400 2400 2400
Wire Wire Line
	2400 2400 2400 800 
Wire Wire Line
	4550 2300 4100 2300
Wire Wire Line
	4100 2300 4100 2550
Wire Wire Line
	4100 2550 3200 2550
Wire Wire Line
	3200 2550 3200 3050
Wire Wire Line
	2550 3900 2700 3900
Wire Wire Line
	3050 3900 3050 4000
Wire Wire Line
	3050 4150 2850 4150
Wire Wire Line
	2850 4150 2850 4250
Wire Wire Line
	2850 4250 2700 4250
Wire Wire Line
	3050 4300 2950 4300
Wire Wire Line
	2950 4300 2950 4600
Wire Wire Line
	2950 4600 2700 4600
Wire Wire Line
	1100 4050 1100 3900
Wire Wire Line
	1450 4050 1450 3850
Wire Wire Line
	1450 3850 2400 3850
Wire Wire Line
	2400 3850 2400 4050
$Comp
L Device:LED D?
U 1 1 6066330A
P 1800 4200
F 0 "D?" H 1793 4417 50  0001 C CNN
F 1 "LED_B" V 1900 4350 50  0000 C CNN
F 2 "" H 1800 4200 50  0001 C CNN
F 3 "~" H 1800 4200 50  0001 C CNN
	1    1800 4200
	0    1    1    0   
$EndComp
Wire Wire Line
	2400 4400 2300 4400
Wire Wire Line
	2300 4400 2300 3900
Wire Wire Line
	2300 3900 1100 3900
Wire Wire Line
	1800 4050 2200 4050
Wire Wire Line
	2200 4050 2200 4750
Wire Wire Line
	2200 4750 2400 4750
Wire Wire Line
	3350 1950 3350 2300
Wire Wire Line
	4550 1700 3750 1700
Wire Wire Line
	4550 1850 3800 1850
Wire Wire Line
	3800 1850 3800 2300
Wire Wire Line
	3500 3050 3500 2450
Wire Wire Line
	3500 2450 3350 2450
Wire Wire Line
	3350 2450 3350 2300
Connection ~ 3350 2300
Wire Wire Line
	4450 2150 4550 2150
$Comp
L Device:R_POT_US RV?
U 1 1 606EC31B
P 4100 1500
F 0 "RV?" V 3895 1500 50  0001 C CNN
F 1 "R_POT_US" V 3987 1500 50  0000 C CNN
F 2 "" H 4100 1500 50  0001 C CNN
F 3 "~" H 4100 1500 50  0001 C CNN
	1    4100 1500
	0    1    1    0   
$EndComp
Wire Wire Line
	4250 1500 4500 1500
Wire Wire Line
	4100 1650 4100 1800
Wire Wire Line
	4100 1800 3950 1800
Wire Wire Line
	3950 1800 3950 2150
Wire Wire Line
	3450 850  3200 850 
Wire Wire Line
	3200 850  3200 800 
Wire Wire Line
	3450 1000 2900 1000
Wire Wire Line
	2900 1000 2900 800 
Wire Wire Line
	900  2550 1000 2550
Wire Wire Line
	1000 2550 1000 1450
Wire Wire Line
	1000 1450 2800 1450
Wire Wire Line
	2800 1450 2800 800 
$Comp
L Device:Jumper_NC_Dual JP?
U 1 1 60700F43
P 4850 800
F 0 "JP?" V 4804 902 50  0001 L CNN
F 1 "Jpr_SCK" V 5000 850 50  0000 L CNN
F 2 "" H 4850 800 50  0001 C CNN
F 3 "~" H 4850 800 50  0001 C CNN
	1    4850 800 
	0    1    1    0   
$EndComp
$Comp
L Device:Jumper_NC_Dual JP?
U 1 1 607028A7
P 5100 1350
F 0 "JP?" H 5100 1497 50  0001 C CNN
F 1 "Jpr_SCL" V 5250 1400 50  0000 L CNN
F 2 "" H 5100 1350 50  0001 C CNN
F 3 "~" H 5100 1350 50  0001 C CNN
	1    5100 1350
	0    1    1    0   
$EndComp
Wire Wire Line
	3350 1950 2300 1950
Wire Wire Line
	2300 1950 2300 1600
Wire Wire Line
	3000 800  3000 1250
Wire Wire Line
	3000 1250 4900 1250
Wire Wire Line
	3100 800  3100 1150
Wire Wire Line
	3100 1150 4650 1150
Wire Wire Line
	4650 1150 4650 800 
Wire Wire Line
	4650 800  4750 800 
Wire Wire Line
	4900 1250 4900 1350
Wire Wire Line
	4900 1350 5000 1350
Wire Wire Line
	4850 550  5400 550 
Wire Wire Line
	5400 550  5400 900 
Wire Wire Line
	5400 900  5800 900 
Wire Wire Line
	4850 1050 5400 1050
Wire Wire Line
	5400 1050 5400 1250
Wire Wire Line
	5400 1250 5800 1250
Wire Wire Line
	5100 1100 5500 1100
Wire Wire Line
	5500 1100 5500 750 
Wire Wire Line
	5500 750  5800 750 
Wire Wire Line
	5100 1600 5500 1600
Wire Wire Line
	5500 1600 5500 1400
Wire Wire Line
	5500 1400 5800 1400
NoConn ~ 4400 2450
NoConn ~ 4400 2600
Wire Wire Line
	4400 2450 4550 2450
Wire Wire Line
	4400 2600 4550 2600
NoConn ~ 1050 2700
Wire Wire Line
	1050 2700 900  2700
$Comp
L pspice:R R?
U 1 1 606DBFC0
P 4200 2150
F 0 "R?" V 4405 2150 50  0001 C CNN
F 1 "R" V 4313 2150 50  0000 C CNN
F 2 "" H 4200 2150 50  0001 C CNN
F 3 "~" H 4200 2150 50  0001 C CNN
	1    4200 2150
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60C8E320
P 5800 4900
F 0 "#PWR?" H 5800 4650 50  0001 C CNN
F 1 "GND" H 5805 4727 50  0000 C CNN
F 2 "" H 5800 4900 50  0001 C CNN
F 3 "" H 5800 4900 50  0001 C CNN
	1    5800 4900
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push_DPDT SW0
U 1 1 60C90C83
P 4600 3700
F 0 "SW0" H 4600 4185 50  0001 C CNN
F 1 "SW_DPDT" H 4600 4094 50  0000 C CNN
F 2 "" H 4600 3900 50  0001 C CNN
F 3 "~" H 4600 3900 50  0001 C CNN
	1    4600 3700
	1    0    0    -1  
$EndComp
$Comp
L pspice:DIODE D0
U 1 1 60CCAC6F
P 5400 3100
F 0 "D0" H 5400 3365 50  0001 C CNN
F 1 "SR240" H 5400 3273 50  0000 C CNN
F 2 "" H 5400 3100 50  0001 C CNN
F 3 "~" H 5400 3100 50  0001 C CNN
	1    5400 3100
	1    0    0    -1  
$EndComp
$Comp
L Battery_Management:MAX1811 U?
U 1 1 60CF9EBD
P 5250 4400
F 0 "U?" H 5300 4867 50  0000 C CNN
F 1 "MAX1811" H 5300 4776 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 5500 4050 50  0001 L CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/MAX1811.pdf" H 5250 3700 50  0001 C CNN
	1    5250 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 4200 4750 4200
Wire Wire Line
	4750 4200 4750 4300
Wire Wire Line
	4750 4300 4850 4300
Wire Wire Line
	4850 4500 4750 4500
Wire Wire Line
	4750 4500 4750 4300
Connection ~ 4750 4300
Wire Wire Line
	5750 4200 5750 3600
Wire Wire Line
	5250 4800 5250 4900
Wire Wire Line
	5250 4900 5350 4900
Wire Wire Line
	5350 4900 5350 4800
Wire Wire Line
	5350 4900 5800 4900
Connection ~ 5350 4900
Wire Wire Line
	5750 3600 4800 3600
Text GLabel 4150 3500 0    50   Input ~ 0
B+
Text GLabel 4150 3900 0    50   Input ~ 0
B-
Wire Wire Line
	4400 3500 4150 3500
Wire Wire Line
	4150 3900 4150 4900
Wire Wire Line
	4150 4900 5250 4900
Connection ~ 5250 4900
Wire Wire Line
	4300 3900 4400 3900
Wire Wire Line
	4800 3800 4800 3700
Wire Wire Line
	4800 3700 4300 3700
Wire Wire Line
	4300 3700 4300 3900
Wire Wire Line
	4800 4000 4800 4100
Wire Wire Line
	4800 4100 4750 4100
Wire Wire Line
	4750 4100 4750 4200
Connection ~ 4750 4200
Wire Wire Line
	2700 4050 2700 3900
Connection ~ 2700 3900
Wire Wire Line
	2700 3900 3050 3900
Wire Wire Line
	2700 4400 2700 4250
Connection ~ 2700 4250
Wire Wire Line
	2700 4250 2550 4250
Wire Wire Line
	2700 4600 2700 4750
Connection ~ 2700 4600
Wire Wire Line
	2700 4600 2550 4600
Wire Wire Line
	4850 4600 4750 4600
Wire Wire Line
	4750 4600 4750 4500
Connection ~ 4750 4500
$Comp
L Device:LED D?
U 1 1 60D83B92
P 6000 4400
F 0 "D?" H 5993 4617 50  0000 C CNN
F 1 "LED" H 5993 4526 50  0000 C CNN
F 2 "" H 6000 4400 50  0001 C CNN
F 3 "~" H 6000 4400 50  0001 C CNN
	1    6000 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 4400 5750 4400
$Comp
L Device:Polyfuse F?
U 1 1 60D9BBFD
P 4950 3250
F 0 "F?" H 5038 3296 50  0000 L CNN
F 1 "Polyfuse" H 5038 3205 50  0000 L CNN
F 2 "" H 5000 3050 50  0001 L CNN
F 3 "~" H 4950 3250 50  0001 C CNN
	1    4950 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 3350 6150 3450
Wire Wire Line
	5800 3100 5800 3450
$Comp
L Device:R_US R?
U 1 1 60DCF024
P 6150 3850
F 0 "R?" H 6218 3896 50  0000 L CNN
F 1 "R_US" H 6218 3805 50  0000 L CNN
F 2 "" V 6190 3840 50  0001 C CNN
F 3 "~" H 6150 3850 50  0001 C CNN
	1    6150 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 4400 6150 4000
Wire Wire Line
	6150 3700 6150 3450
Connection ~ 6150 3450
Wire Wire Line
	5800 3450 6150 3450
$Comp
L power:+5V #PWR?
U 1 1 60C8D9B7
P 6150 3350
F 0 "#PWR?" H 6150 3200 50  0001 C CNN
F 1 "+5V" H 6165 3523 50  0000 C CNN
F 2 "" H 6150 3350 50  0001 C CNN
F 3 "" H 6150 3350 50  0001 C CNN
	1    6150 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 3450 5150 3450
Wire Wire Line
	5150 3450 5150 3700
Wire Wire Line
	5150 3700 4800 3700
Connection ~ 5800 3450
Connection ~ 4800 3700
Wire Wire Line
	5800 3100 5600 3100
Wire Wire Line
	5200 3100 4950 3100
Wire Wire Line
	4950 3400 4800 3400
$EndSCHEMATC
