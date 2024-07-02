/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 30/6/2024  ************************************/
/*************************** HWC : Servo Motor ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
#ifndef WDT_INTERFACE_H
#define WDT_INTERFACE_H

u8 WDT_u8Enable(u8 Copy_u8Prescaler);
void WDT_voidDisable(void);

/* Prescaler */
/*
Prescaler           V = 3   V = 5
16K (16,384)        17.1ms  16.3ms
32K (32,768)        34.3ms  32.5ms
64K (65,536)        68.5ms  65ms
128K (131,072)      0.14s   0.13 s
256K (262,144)      0.27s   0.26s
512K (524,288)      0.55s   0.52s
1,024K (1,048,576)  1.1s    1.0s
2,048K (2,097,152)  2.2s    2.1s
*/
#define WDT_u8_PRESCALER_16 1
#define WDT_u8_PRESCALER_32 2
#define WDT_u8_PRESCALER_64 3
#define WDT_u8_PRESCALER_128 4
#define WDT_u8_PRESCALER_256 5
#define WDT_u8_PRESCALER_512 6
#define WDT_u8_PRESCALER_1024 7
#define WDT_u8_PRESCALER_2048 8

#endif