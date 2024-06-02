/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 30/5/2024  ************************************/
/*************************** SWC : External Interrupt *****************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/* Define EXTI Registers */
#define EXTI_u8_MCUCR *((volatile u8 *)0x55)
#define EXTI_u8_MCUCSR *((volatile u8 *)0x54)
#define EXTI_u8_GICR *((volatile u8 *)0x5B)
#define EXTI_u8_GIFR *((volatile u8 *)0x5A)
#define EXTI_u8_SREG *((volatile u8 *)0x5F)

#endif