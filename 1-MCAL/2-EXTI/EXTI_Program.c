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

/* Global pointer to  a function */
static void (*EXTI_ApfEXTI[3])(void) = {NULL, NULL, NULL}; // to solve wild pointers

u8 EXTI_u8Enable(u8 Copy_u8EXTIPin, u8 Copy_u8EdgeSource)
{
    u8 Local_u8ErrorState = STD_TYPE_OK;
    

    /* Enable External Interrupt (PIE) and Select Edge Source */  
    switch (Copy_u8EXTIPin)
    {
    case EXTI_u8_INT0:
        switch (Copy_u8EdgeSource)
        {
        case EXTI_u8_FALLING_EDGE:
            SET_BIT(EXTI_u8_MCUCR,EXTI_u8_EXTI0_TRIGGER_ISC01);
            CLR_BIT(EXTI_u8_MCUCR,EXTI_u8_EXTI0_TRIGGER_ISC00);
            break;
        case EXTI_u8_LOW_STATE:
            CLR_BIT(EXTI_u8_MCUCR,EXTI_u8_EXTI0_TRIGGER_ISC01);
            CLR_BIT(EXTI_u8_MCUCR,EXTI_u8_EXTI0_TRIGGER_ISC00);
            break;
        case EXTI_u8_RISING_EDGE:
            SET_BIT(EXTI_u8_MCUCR,EXTI_u8_EXTI0_TRIGGER_ISC01);
            SET_BIT(EXTI_u8_MCUCR,EXTI_u8_EXTI0_TRIGGER_ISC00);
            break;
        case EXTI_u8_ANY_LOGICAL_STATE:
            CLR_BIT(EXTI_u8_MCUCR,EXTI_u8_EXTI0_TRIGGER_ISC01);
            SET_BIT(EXTI_u8_MCUCR,EXTI_u8_EXTI0_TRIGGER_ISC00);
            break;
    
        default:
            Local_u8ErrorState = STD_TYPE_NOK;
            break;
        }
        if (Local_u8ErrorState == STD_TYPE_OK)
           SET_BIT(EXTI_u8_GICR, EXTI_u8_EXTI0_BIT);
        break;
    
    case EXTI_u8_INT1:
        switch (Copy_u8EdgeSource)
        {
        case EXTI_u8_FALLING_EDGE:
            SET_BIT(EXTI_u8_MCUCR,EXTI_u8_EXTI1_TRIGGER_ISC11);
            CLR_BIT(EXTI_u8_MCUCR,EXTI_u8_EXTI1_TRIGGER_ISC10);
            break;
        case EXTI_u8_LOW_STATE:
            CLR_BIT(EXTI_u8_MCUCR,EXTI_u8_EXTI1_TRIGGER_ISC11);
            CLR_BIT(EXTI_u8_MCUCR,EXTI_u8_EXTI1_TRIGGER_ISC10);
            break;
        case EXTI_u8_RISING_EDGE:
            SET_BIT(EXTI_u8_MCUCR,EXTI_u8_EXTI1_TRIGGER_ISC11);
            SET_BIT(EXTI_u8_MCUCR,EXTI_u8_EXTI1_TRIGGER_ISC10);
            break;
        case EXTI_u8_ANY_LOGICAL_STATE:
            CLR_BIT(EXTI_u8_MCUCR,EXTI_u8_EXTI1_TRIGGER_ISC11);
            SET_BIT(EXTI_u8_MCUCR,EXTI_u8_EXTI1_TRIGGER_ISC10);
            break;
    
        default:
            Local_u8ErrorState = STD_TYPE_NOK;
            break;
        }
        if (Local_u8ErrorState == STD_TYPE_OK)
            SET_BIT(EXTI_u8_GICR, EXTI_u8_EXTI1_BIT);
        break;
    
    case EXTI_u8_INT2:
        switch (Copy_u8EdgeSource)
        {
        case EXTI_u8_FALLING_EDGE:
            CLR_BIT(EXTI_u8_MCUCSR,EXTI_u8_EXTI2_TRIGGER_ISC2);
            break;
        case EXTI_u8_RISING_EDGE:
            SET_BIT(EXTI_u8_MCUCSR,EXTI_u8_EXTI2_TRIGGER_ISC2);
            break;
    
        default:
            Local_u8ErrorState = STD_TYPE_NOK;
            break;
        }
        if (Local_u8ErrorState == STD_TYPE_OK)
            SET_BIT(EXTI_u8_GICR, EXTI_u8_EXTI2_BIT);
        break;
    
    default:
        Local_u8ErrorState = STD_TYPE_NOK;
        break;
    }
    
    return Local_u8ErrorState;
}

u8 EXTI_u8Disable(u8 Copy_u8EXTIPin)
{
    u8 Local_u8ErrorState = STD_TYPE_OK;
    
    switch (Copy_u8EXTIPin)
    {
    case EXTI_u8_INT0:
        CLR_BIT(EXTI_u8_GICR,EXTI_u8_EXTI0_BIT);
        break;
    case EXTI_u8_INT1:
        CLR_BIT(EXTI_u8_GICR,EXTI_u8_EXTI1_BIT);
        break;
    case EXTI_u8_INT2:
        CLR_BIT(EXTI_u8_GICR,EXTI_u8_EXTI2_BIT);
        break;
    
    default:
        Local_u8ErrorState = STD_TYPE_NOK;
        break;
    }
    return Local_u8ErrorState;
}

/* Set Call Function */
u8 EXTI_u8EXTISetCallBack(u8 Copy_u8EXTIIndex, void(*Copy_pvoidFunction)(void))
{
    u8 Local_u8ErrorState = STD_TYPE_OK;
    if ((Copy_u8EXTIIndex <= EXTI_u8_INT2) && (Copy_pvoidFunction != NULL))
    {
        EXTI_ApfEXTI[Copy_u8EXTIIndex] = Copy_pvoidFunction;
    }
    else
    {
        Local_u8ErrorState = STD_TYPE_NOK;
    }
    
    
    return Local_u8ErrorState;
}

/* Prototype for ISR of EXTI 0*/
void __vector_1(void)     __attribute__((signal));
void __vector_1(void)
{
    if (EXTI_ApfEXTI[EXTI_u8_INT0] != NULL)
    {
        EXTI_ApfEXTI[EXTI_u8_INT0]();
    }
    
}

/* Prototype for ISR of EXTI 1*/
void __vector_2(void)     __attribute__((signal));
void __vector_2(void)
{
    if (EXTI_ApfEXTI[EXTI_u8_INT1] != NULL)
    {
        EXTI_ApfEXTI[EXTI_u8_INT1]();
    }
}

/* Prototype for ISR of EXTI 2*/
void __vector_3(void)     __attribute__((signal));
void __vector_3(void)
{
    if (EXTI_ApfEXTI[EXTI_u8_INT2] != NULL)
    {
        EXTI_ApfEXTI[EXTI_u8_INT2]();
    }
}

