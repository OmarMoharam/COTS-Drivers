/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 30/5/2024  ************************************/
/*************************** SWC : External Interrupt *****************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
/* LIB */
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

/* MCAL */
#include "EXTI_Configuration.h"
#include "EXTI_Interface.h"
#include "EXTI_Private.h"

void EXTI_voiEXTI0Enable(void)
{
    /* 1- Select Edge Source --> Falling Edge */
    SET_BIT(EXTI_u8_MCUCR,1);
    CLR_BIT(EXTI_u8_MCUCR,0);

    /* 2- Enable EXTI0 --> PIE */
    SET_BIT(EXTI_u8_GICR,6);
}