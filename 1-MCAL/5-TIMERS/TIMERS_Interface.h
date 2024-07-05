/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 22/6/2024  ************************************/
/*************************** SWC : TIMERS      ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H

/********************************************* Timer 1 *********************************************/
void Timer_voidInitTimer0(void);
u8 Timer_u8Timer0SetCallBackOVF(void(*Copy_pvoidApplication)(void));
u8 Timer_u8Timer0SetCallBackCTC(void(*Copy_pvoidApplication)(void));
void Timer_voidTimer0SetCompareMatchValue(u8 Copy_u8OCR0Value);

/***************************************************************************************************/
/********************************************* Timer 1 *********************************************/
void Timer_voidInitTimer1(void);
void Timer_voidTimer1SetValue(u16 Copy_u16Value);
u16 Timer_u16Timer1ReadValue(void);

/***************************************************************************************************/
/******************************************** Timer 1 Servo ****************************************/
void Timer_voidTimer1SetCompareMatchValue(u16 Copy_u16OCRValue);

/***************************************************************************************************/
/******************************************** Timer 1 ICU ****************************************/
#define Timer_u8_ICU_RISING_EDGE 1
#define Timer_u8_ICU_FALLING_EDGE 0

void ICU_voidInit(void);
u8 ICU_u8SetTriggerEdge(u8 Copy_u8Edge);
void ICU_voidEnableInterrupt(void);
void ICU_voidDisableInterrupt(void);
u16 ICU_u16ReadValue(void);
u8 ICU_u8SetCallBack(void(*Copy_pvoidApplication)(void));

#endif