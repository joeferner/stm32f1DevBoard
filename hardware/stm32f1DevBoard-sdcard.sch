EESchema Schematic File Version 2  date Sun 16 Dec 2012 03:06:52 PM EST
LIBS:stm32f1DevBoard
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:stm32f1DevBoard-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 4
Title ""
Date "16 dec 2012"
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
L +3.3V #PWR055
U 1 1 50CE3309
P 5500 3150
F 0 "#PWR055" H 5500 3110 30  0001 C CNN
F 1 "+3.3V" H 5500 3260 30  0000 C CNN
	1    5500 3150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR056
U 1 1 50CE330F
P 5500 4300
F 0 "#PWR056" H 5500 4300 30  0001 C CNN
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
L CSMALL C17
U 1 1 50CE3324
P 7750 4600
F 0 "C17" H 7775 4650 30  0000 L CNN
F 1 "0.1uF" H 7775 4550 30  0000 L CNN
	1    7750 4600
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR057
U 1 1 50CE332A
P 7750 4400
F 0 "#PWR057" H 7750 4360 30  0001 C CNN
F 1 "+3.3V" H 7750 4510 30  0000 C CNN
	1    7750 4400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR058
U 1 1 50CE3330
P 7750 4800
F 0 "#PWR058" H 7750 4800 30  0001 C CNN
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
$EndSCHEMATC
