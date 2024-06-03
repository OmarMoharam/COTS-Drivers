/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 30/5/2024  ************************************/
/*************************** SWC : External Interrupt *****************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/******************* Define EXTI Registers ***********************/
#define EXTI_u8_MCUCR *((volatile u8 *)0x55) //for EXTI0 EXTI1
#define EXTI_u8_EXTI0_TRIGGER_ISC00 0
#define EXTI_u8_EXTI0_TRIGGER_ISC01 1

#define EXTI_u8_EXTI1_TRIGGER_ISC10 2
#define EXTI_u8_EXTI1_TRIGGER_ISC11 3

#define EXTI_u8_MCUCSR *((volatile u8 *)0x54) //for EXTI2
#define EXTI_u8_EXTI2_TRIGGER_ISC2 6

#define EXTI_u8_GICR *((volatile u8 *)0x5B) //PIE
#define EXTI_u8_GIFR *((volatile u8 *)0x5A) //PIF
#define EXTI_u8_EXTI0_BIT 6 //PD2
#define EXTI_u8_EXTI1_BIT 7 //PD3
#define EXTI_u8_EXTI2_BIT 5 //PB2


#endif