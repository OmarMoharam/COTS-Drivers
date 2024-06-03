/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 30/5/2024  ************************************/
/*************************** SWC : External Interrupt *****************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

u8 EXTI_u8Enable(u8 Copy_u8EXTIPin, u8 Copy_u8EdgeSource);
u8 EXTI_u8Disable(u8 Copy_u8EXTIPin);

/* External Interrupt Pins */
#define EXTI_u8_INT0 0
#define EXTI_u8_INT1 1
#define EXTI_u8_INT2 2

/* Edge Trigger */
#define EXTI_u8_FALLING_EDGE 1
#define EXTI_u8_LOW_STATE 2
#define EXTI_u8_RISING_EDGE 3
#define EXTI_u8_ANY_LOGICAL_STATE 4

/* ISR */
u8 EXTI_u8EXTISetCallBack(u8 Copy_u8EXTIIndex, void(*Copy_pvoidFunction)(void));
#endif