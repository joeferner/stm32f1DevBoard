EESchema Schematic File Version 2  date Thu 17 Jan 2013 09:41:47 PM EST
LIBS:userFavorites
LIBS:power
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 4
Title ""
Date "18 jan 2013"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L SDCARD J3
U 1 1 50CE3303
P 6100 3700
F 0 "J3" H 5950 4300 60  0000 C CNN
F 1 "SDCARD" H 6100 3050 60  0000 C CNN
	1    6100 3700
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR58
U 1 1 50CE3309
P 5500 3150
F 0 "#PWR58" H 5500 3110 30  0001 C CNN
F 1 "+3.3V" H 5500 3260 30  0000 C CNN
	1    5500 3150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR59
U 1 1 50CE330F
P 5500 4300
F 0 "#PWR59" H 5500 4300 30  0001 C CNN
F 1 "GND" H 5500 4230 30  0001 C CNN
	1    5500 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 4100 5500 4100
Wire Wire Line
	5500 4100 5500 4300
Wire Wire Line
	5600 4200 5500 4200
Connection ~ 5500 4200
Wire Wire Line
	5600 3250 5500 3250
Wire Wire Line
	5500 3250 5500 3150
Wire Wire Line
	5600 3700 5100 3700
Wire Wire Line
	5600 3600 5100 3600
Wire Wire Line
	5600 3500 5100 3500
Wire Wire Line
	5600 3400 5100 3400
$Comp
L CPsmall C17
U 1 1 50CE3324
P 7750 4600
F 0 "C17" H 7775 4650 30  0000 L CNN
F 1 "0.1uF" H 7775 4550 30  0000 L CNN
	1    7750 4600
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR60
U 1 1 50CE332A
P 7750 4400
F 0 "#PWR60" H 7750 4360 30  0001 C CNN
F 1 "+3.3V" H 7750 4510 30  0000 C CNN
	1    7750 4400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR61
U 1 1 50CE3330
P 7750 4800
F 0 "#PWR61" H 7750 4800 30  0001 C CNN
F 1 "GND" H 7750 4730 30  0001 C CNN
	1    7750 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7750 4400 7750 4500
Wire Wire Line
	7750 4700 7750 4800
Text GLabel 5100 3400 0    50   Input ~ 0
SDCS
Text GLabel 5100 3500 0    50   Input ~ 0
MOSI
Text GLabel 5100 3600 0    50   Input ~ 0
MISO
Text GLabel 5100 3700 0    50   Input ~ 0
SCK
NoConn ~ 5600 3800
NoConn ~ 5600 3900
$Comp
L R R19
U 1 1 50F8B9A0
P 5250 3100
F 0 "R19" H 5260 3190 60  0000 C CNN
F 1 "10k" H 5260 3000 60  0000 C CNN
	1    5250 3100
	0    -1   -1   0   
$EndComp
$Comp
L +3.3V #PWR57
U 1 1 50F8B9B2
P 5250 2800
F 0 "#PWR57" H 5250 2760 30  0001 C CNN
F 1 "+3.3V" H 5250 2910 30  0000 C CNN
	1    5250 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 2800 5250 2900
Wire Wire Line
	5250 3250 5250 3400
Connection ~ 5250 3400
$EndSCHEMATC
