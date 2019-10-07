EESchema Schematic File Version 4
LIBS:HHV_2019_SC-cache
EELAYER 29 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 1 1
Title "Hardware Hacking Village 2019 Soldering Challenge"
Date "2019-09-09"
Rev ""
Comp "Design by @alt_bier (a.k.a. Richard Gowen)"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L alt_bier-sch:Conn_01x02 J1
U 1 1 5D76574B
P 7350 2550
F 0 "J1" H 7430 2542 50  0000 L CNN
F 1 "Battery_Connector" H 7430 2451 50  0000 L CNN
F 2 "alt_bier-fp:Pin_Header_Straight_1x02_Pitch2.54mm" H 7500 2250 50  0001 C CNN
F 3 "~" H 7350 2550 50  0001 C CNN
	1    7350 2550
	1    0    0    -1  
$EndComp
$Comp
L alt_bier-sch:R_THT R1
U 1 1 5D765BCE
P 6000 2550
F 0 "R1" V 6207 2550 50  0000 C CNN
F 1 "R_THT" V 6116 2550 50  0000 C CNN
F 2 "alt_bier-fp:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6130 2500 50  0001 C CNN
F 3 "~" H 5950 2550 50  0001 C CNN
	1    6000 2550
	0    1    1    0   
$EndComp
$Comp
L alt_bier-sch:LED_5mm D1
U 1 1 5D76608A
P 5450 2550
F 0 "D1" H 5443 2766 50  0000 C CNN
F 1 "LED_5mm" H 5443 2675 50  0000 C CNN
F 2 "alt_bier-fp:LED_D5.0mm" H 5450 2300 50  0001 C CNN
F 3 "~" H 5450 2550 50  0001 C CNN
	1    5450 2550
	1    0    0    -1  
$EndComp
$Comp
L alt_bier-sch:R_THT R2
U 1 1 5D767AA8
P 6000 2950
F 0 "R2" V 6207 2950 50  0000 C CNN
F 1 "R_THT" V 6116 2950 50  0000 C CNN
F 2 "alt_bier-fp:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6130 2900 50  0001 C CNN
F 3 "~" H 5950 2950 50  0001 C CNN
	1    6000 2950
	0    1    1    0   
$EndComp
$Comp
L alt_bier-sch:LED_3mm D2
U 1 1 5D7682FC
P 5450 2950
F 0 "D2" H 5443 3166 50  0000 C CNN
F 1 "LED_3mm" H 5443 3075 50  0000 C CNN
F 2 "alt_bier-fp:LED_D3.0mm" H 5450 2700 50  0001 C CNN
F 3 "~" H 5450 2950 50  0001 C CNN
	1    5450 2950
	1    0    0    -1  
$EndComp
$Comp
L alt_bier-sch:LED_RCBG_THT_5mm D5
U 1 1 5D9A84AB
P 2050 3250
F 0 "D5" H 2050 3747 50  0000 C CNN
F 1 "LED_RCBG_THT_5mm" H 2050 3656 50  0000 C CNN
F 2 "alt_bier-fp:LED_D5.0mm-4_RGB" H 2100 2800 50  0001 C CNN
F 3 "~" H 2050 3200 50  0001 C CNN
	1    2050 3250
	1    0    0    -1  
$EndComp
$Comp
L alt_bier-sch:R_THT R5
U 1 1 5D9AA85E
P 3700 2650
F 0 "R5" V 3907 2650 50  0000 C CNN
F 1 "R_THT" V 3816 2650 50  0000 C CNN
F 2 "alt_bier-fp:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 3830 2600 50  0001 C CNN
F 3 "~" H 3650 2650 50  0001 C CNN
	1    3700 2650
	0    1    1    0   
$EndComp
$Comp
L alt_bier-sch:R_1206 R3
U 1 1 5D9AAE40
P 6000 3450
F 0 "R3" V 6200 3400 50  0000 L CNN
F 1 "R_1206" V 6100 3300 50  0000 L CNN
F 2 "alt_bier-fp:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 6130 3400 50  0001 C CNN
F 3 "~" H 5950 3450 50  0001 C CNN
	1    6000 3450
	0    1    1    0   
$EndComp
$Comp
L alt_bier-sch:LED_1206 D3
U 1 1 5D9AB199
P 5450 3450
F 0 "D3" H 5443 3666 50  0000 C CNN
F 1 "LED_1206" H 5443 3575 50  0000 C CNN
F 2 "alt_bier-fp:LED_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 5450 3200 50  0001 C CNN
F 3 "~" H 5450 3450 50  0001 C CNN
	1    5450 3450
	1    0    0    -1  
$EndComp
Text GLabel 7000 2650 0    50   Input ~ 0
POS
Text GLabel 7000 2550 0    50   Input ~ 0
GND
Wire Wire Line
	7000 2650 7150 2650
Wire Wire Line
	7000 2550 7150 2550
Text GLabel 6350 2550 2    50   Input ~ 0
POS
Text GLabel 6350 2950 2    50   Input ~ 0
POS
Text GLabel 4050 2650 2    50   Input ~ 0
POS
Wire Wire Line
	6350 2550 6150 2550
Wire Wire Line
	6350 2950 6150 2950
Wire Wire Line
	4050 2650 3850 2650
Wire Wire Line
	5850 2550 5600 2550
Wire Wire Line
	5850 2950 5600 2950
$Comp
L alt_bier-sch:R_THT R7
U 1 1 5D9AAC96
P 3700 3250
F 0 "R7" V 3907 3250 50  0000 C CNN
F 1 "R_THT" V 3816 3250 50  0000 C CNN
F 2 "alt_bier-fp:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 3830 3200 50  0001 C CNN
F 3 "~" H 3650 3250 50  0001 C CNN
	1    3700 3250
	0    1    1    0   
$EndComp
Wire Wire Line
	3550 3250 3450 3250
$Comp
L alt_bier-sch:R_THT R6
U 1 1 5D9BA72A
P 3700 3900
F 0 "R6" V 3907 3900 50  0000 C CNN
F 1 "R_THT" V 3816 3900 50  0000 C CNN
F 2 "alt_bier-fp:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 3830 3850 50  0001 C CNN
F 3 "~" H 3650 3900 50  0001 C CNN
	1    3700 3900
	0    1    1    0   
$EndComp
Wire Wire Line
	3550 3900 3450 3900
Text GLabel 4050 3250 2    50   Input ~ 0
POS
Wire Wire Line
	4050 3250 3850 3250
Text GLabel 4050 3900 2    50   Input ~ 0
POS
Wire Wire Line
	4050 3900 3850 3900
Wire Wire Line
	2250 3050 2400 3050
Wire Wire Line
	2400 3050 2400 2650
Wire Wire Line
	2250 3250 2750 3250
Wire Wire Line
	2250 3450 2400 3450
Wire Wire Line
	2400 3450 2400 3900
Wire Wire Line
	2400 3900 2750 3900
Text GLabel 5150 2550 0    50   Input ~ 0
GND
Wire Wire Line
	5150 2550 5300 2550
Text GLabel 5150 2950 0    50   Input ~ 0
GND
Wire Wire Line
	5150 2950 5300 2950
Text GLabel 1700 3250 0    50   Input ~ 0
GND
Wire Wire Line
	1700 3250 1850 3250
Text GLabel 6350 3450 2    50   Input ~ 0
POS
Wire Wire Line
	6350 3450 6150 3450
Wire Wire Line
	5850 3450 5600 3450
Text GLabel 5150 3450 0    50   Input ~ 0
GND
Wire Wire Line
	5150 3450 5300 3450
Wire Wire Line
	3550 2650 3450 2650
Wire Wire Line
	2900 2650 2750 2650
$Comp
L alt_bier-sch:R_1206 R4
U 1 1 5D9B86B5
P 6000 3950
F 0 "R4" V 6200 3900 50  0000 L CNN
F 1 "R_0805" V 6100 3800 50  0000 L CNN
F 2 "alt_bier-fp:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 6130 3900 50  0001 C CNN
F 3 "~" H 5950 3950 50  0001 C CNN
	1    6000 3950
	0    1    1    0   
$EndComp
$Comp
L alt_bier-sch:LED_1206 D4
U 1 1 5D9B86BB
P 5450 3950
F 0 "D4" H 5443 4166 50  0000 C CNN
F 1 "LED_0805" H 5443 4075 50  0000 C CNN
F 2 "alt_bier-fp:LED_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5450 3700 50  0001 C CNN
F 3 "~" H 5450 3950 50  0001 C CNN
	1    5450 3950
	1    0    0    -1  
$EndComp
Text GLabel 6350 3950 2    50   Input ~ 0
POS
Wire Wire Line
	6350 3950 6150 3950
Wire Wire Line
	5850 3950 5600 3950
Text GLabel 5150 3950 0    50   Input ~ 0
GND
Wire Wire Line
	5150 3950 5300 3950
$Comp
L alt_bier-sch:SW_Push_Dual_THT_6mm SW1
U 1 1 5D9BF14A
P 3100 2650
F 0 "SW1" H 3100 2935 50  0000 C CNN
F 1 "SW_Push_Dual_THT_6mm" H 3100 2844 50  0000 C CNN
F 2 "alt_bier-fp:SW_PUSH_6mm" H 3100 2850 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1905211531_SHOU-HAN-TS665CJ_C393938.pdf" H 3100 2850 50  0001 C CNN
	1    3100 2650
	1    0    0    -1  
$EndComp
$Comp
L alt_bier-sch:SW_Push_Dual_THT_6mm SW3
U 1 1 5D9C0415
P 3100 3250
F 0 "SW3" H 3100 3535 50  0000 C CNN
F 1 "SW_Push_Dual_THT_6mm" H 3100 3444 50  0000 C CNN
F 2 "alt_bier-fp:SW_PUSH_6mm" H 3100 3450 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1905211531_SHOU-HAN-TS665CJ_C393938.pdf" H 3100 3450 50  0001 C CNN
	1    3100 3250
	1    0    0    -1  
$EndComp
$Comp
L alt_bier-sch:SW_Push_Dual_THT_6mm SW2
U 1 1 5D9C0D08
P 3100 3900
F 0 "SW2" H 3100 4185 50  0000 C CNN
F 1 "SW_Push_Dual_THT_6mm" H 3100 4094 50  0000 C CNN
F 2 "alt_bier-fp:SW_PUSH_6mm" H 3100 4100 50  0001 C CNN
F 3 "https://datasheet.lcsc.com/szlcsc/1905211531_SHOU-HAN-TS665CJ_C393938.pdf" H 3100 4100 50  0001 C CNN
	1    3100 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 2850 2750 2850
Wire Wire Line
	2750 2850 2750 2650
Connection ~ 2750 2650
Wire Wire Line
	2750 2650 2400 2650
Wire Wire Line
	3300 2850 3450 2850
Wire Wire Line
	3450 2850 3450 2650
Connection ~ 3450 2650
Wire Wire Line
	3450 2650 3300 2650
Wire Wire Line
	2900 3450 2750 3450
Wire Wire Line
	2750 3450 2750 3250
Connection ~ 2750 3250
Wire Wire Line
	2750 3250 2900 3250
Wire Wire Line
	3300 3450 3450 3450
Wire Wire Line
	3450 3450 3450 3250
Connection ~ 3450 3250
Wire Wire Line
	3450 3250 3300 3250
Wire Wire Line
	3300 4100 3450 4100
Wire Wire Line
	3450 4100 3450 3900
Connection ~ 3450 3900
Wire Wire Line
	3450 3900 3300 3900
Wire Wire Line
	2900 4100 2750 4100
Wire Wire Line
	2750 4100 2750 3900
Connection ~ 2750 3900
Wire Wire Line
	2750 3900 2900 3900
$EndSCHEMATC
