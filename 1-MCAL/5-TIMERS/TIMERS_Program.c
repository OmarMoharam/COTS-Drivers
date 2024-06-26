/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 22/6/2024  ************************************/
/*************************** SWC : TIMERS      ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "TIMERS_Configuration.h"
#include "TIMERS_Interface.h"
#include "TIMERS_Private.h"

/* Set Call function for Timer 0 */
static void(*Timer_pfTimer0[2])(void) = {NULL, NULL};


void Timer_voidInit(void)
{
    /*  1- Choose Timer Mode
        2- Set Timer PIE
        3- Set preload value or Set OCR value in CTC Mode
        4- Choose CLK */

    CLR_BIT(TIMER_u8_TCCR0_REGISTER, TIMER_TCCR0_WGM00_BIT); // Normal Mode
    CLR_BIT(TIMER_u8_TCCR0_REGISTER, TIMER_TCCR0_WGM01_BIT);

    SET_BIT(TIMER_u8_TIMSK_REGISTER, TIMER_TIMSK_TOIE0_BIT);

    TIMER_u8_TCNT0_REGISTER = 192;
    //TIMER_u8_OCR0_REGISTER = 99; //this is mean the flag will be = 1 when counter = 100;

    CLR_BIT(TIMER_u8_TCCR0_REGISTER, TIMER_TCCR0_CS02_BIT);
    SET_BIT(TIMER_u8_TCCR0_REGISTER, TIMER_TCCR0_CS01_BIT);
    CLR_BIT(TIMER_u8_TCCR0_REGISTER, TIMER_TCCR0_CS00_BIT);
}

u8 Timer_u8Timer0SetCallBackOVF(void(*Copy_pvoidApplication)(void))
{
    u8 Local_u8ErrorState = STD_TYPE_OK;
    if (Copy_pvoidApplication != NULL)
    {
        Timer_pfTimer0[0] = Copy_pvoidApplication;
    }
    else
    {
        Local_u8ErrorState = STD_TYPE_NOK;
    }
    return Local_u8ErrorState;
    

}

u8 Timer_u8Timer0SetCallBackCTC(void(*Copy_pvoidApplication)(void))
{
    u8 Local_u8ErrorState = STD_TYPE_OK;
    if (Copy_pvoidApplication != NULL)
    {
        Timer_pfTimer0[1] = Copy_pvoidApplication;
    }
    else
    {
        Local_u8ErrorState = STD_TYPE_NOK;
    }
    return Local_u8ErrorState;
    
}

/* Prototype for ISR of Timer Normal Mode */
void __vector_11(void)   __attribute__((signal));
void __vector_11(void)
{
    static u16 Local_u16CounterOVF = 0;
    Local_u16CounterOVF++;
    if (Local_u16CounterOVF == 3907)
    {
        /* Update preload value */
        TIMER_u8_TCNT0_REGISTER = 192;
        /* Clear the OVF Counter */
        Local_u16CounterOVF = 0;
        /* Callback function from application */
        if (Timer_pfTimer0[0] != NULL)
        {
            Timer_pfTimer0[0];
        }
        
    }
    
}

/* Prototype for ISR of Timer CTC Mode */
void __vector_10(void)   __attribute__((signal));
void __vector_10(void)
{
    static u16 Local_u16CounterCTC = 0;
    Local_u16CounterCTC++;
    if (Local_u16CounterCTC == 10000)
    {
        /* Clear the CTC Counter */
        Local_u16CounterCTC = 0;
        /* Callback function from application */
        if (Timer_pfTimer0[1] != NULL)
        {
            Timer_pfTimer0[1];
        }
        
    }
    
}