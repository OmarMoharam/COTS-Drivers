/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 22/6/2024  ************************************/
/*************************** SWC : TIMERS      ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H

void Timer_voidInit(void);
u8 Timer_u8Timer0SetCallBackOVF(void(*Copy_pvoidApplication)(void));
u8 Timer_u8Timer0SetCallBackCTC(void(*Copy_pvoidApplication)(void));



#endif