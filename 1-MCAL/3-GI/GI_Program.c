/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 30/5/2024  ************************************/
/*************************** SWC : External Interrupt *****************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "GI_Interface.h"

#define EXTI_u8_SREG *((volatile u8 *)0x5F) //Enable Interrupt Registers
#define EXTI_u8_SREG_BIT 7

void GI_voidEnable(void)
{
    /* Enable SREG (GIE) */
    SET_BIT(EXTI_u8_SREG, EXTI_u8_SREG_BIT);
}

void GI_voidDisable(void)
{
    /* Disable SREG (GIE) */
    CLR_BIT(EXTI_u8_SREG, EXTI_u8_SREG_BIT);
}