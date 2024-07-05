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
static void(*Timer_pfTimer0[3])(void) = {NULL, NULL};


void Timer_voidInitTimer0(void)
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


void Timer_voidInitTimer1(void)
{
    /*  1- Choose Timer Mode
        2- Select HW Action on OC
        3- Set Top Value for ICR
        4- Set Angle of Servo Motor
        5- Choose CLK */

    SET_BIT(TIMER_u8_TCCR1A_REGISTER, TIMER_TCCR1A_WGM11_BIT);
    CLR_BIT(TIMER_u8_TCCR1A_REGISTER, TIMER_TCCR1A_WGM10_BIT);
    SET_BIT(TIMER_u8_TCCR1B_REGISTER, TIMER_TCCR1B_WGM13_BIT);
    SET_BIT(TIMER_u8_TCCR1B_REGISTER, TIMER_TCCR1B_WGM12_BIT);

    SET_BIT(TIMER_u8_TCCR1A_REGISTER, TIMER_TCCR1A_COM1A1_BIT);
    CLR_BIT(TIMER_u8_TCCR1A_REGISTER, TIMER_TCCR1A_COM1A0_BIT);

    TIMER_u16_ICR1_REGISTER = 19999;

    TIMER_u16_OCR1A_REGISTER = 1499; // angle = 90 default

    CLR_BIT(TIMER_u8_TCCR1B_REGISTER, TIMER_TCCR1B_CS12_BIT);
    SET_BIT(TIMER_u8_TCCR1B_REGISTER, TIMER_TCCR1B_CS11_BIT);
    CLR_BIT(TIMER_u8_TCCR1B_REGISTER, TIMER_TCCR1B_CS10_BIT);
}

void Timer_voidTimer1SetValue(u16 Copy_u16Value)
{
	TIMER_u16_TCNT1_REGISTER = Copy_u16Value;
}

u16 Timer_u16Timer1ReadValue(void)
{
	return TIMER_u16_TCNT1_REGISTER;
}


void Timer_voidTimer1SetCompareMatchValue(u16 Copy_u16OCRValue)
{
    TIMER_u16_OCR1A_REGISTER = Copy_u16OCRValue;
}


void Timer_voidTimer0SetCompareMatchValue(u8 Copy_u8OCR0Value)
{
    TIMER_u8_OCR0_REGISTER = Copy_u8OCR0Value;
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

void ICU_voidInit(void)
{
    /* Set it as Rising Edge */
    SET_BIT(TIMER_u8_TCCR1B_REGISTER, TIMER_TCCR1B_ICES1_BIT);

    /* Enable Interrupt */
    SET_BIT(TIMER_u8_TIMSK_REGISTER, TIMER_TIMSK_TICIE1_BIT);
}

u8 ICU_u8SetTriggerEdge(u8 Copy_u8Edge)
{
    u8 Local_u8ErrorState = STD_TYPE_OK;
    switch (Copy_u8Edge)
    {
    case Timer_u8_ICU_RISING_EDGE:
        SET_BIT(TIMER_u8_TCCR1B_REGISTER, TIMER_TCCR1B_ICES1_BIT);
        break;
    
    case Timer_u8_ICU_FALLING_EDGE:
        CLR_BIT(TIMER_u8_TCCR1B_REGISTER, TIMER_TCCR1B_ICES1_BIT);
        break;
    
    default:
        Local_u8ErrorState = STD_TYPE_NOK;
        break;
    }
    return Local_u8ErrorState;
}

void ICU_voidEnableInterrupt(void)
{
    SET_BIT(TIMER_u8_TIMSK_REGISTER, TIMER_TIMSK_TICIE1_BIT);
}

void ICU_voidDisableInterrupt(void)
{
    CLR_BIT(TIMER_u8_TIMSK_REGISTER, TIMER_TIMSK_TICIE1_BIT);
}

u16 ICU_u16ReadValue(void)
{
    return TIMER_u16_ICR1_REGISTER;
}

u8 ICU_u8SetCallBack(void(*Copy_pvoidApplication)(void))
{
    u8 Local_u8ErrorState = STD_TYPE_OK;
    if (Copy_pvoidApplication != NULL)
    {
        Timer_pfTimer0[2] = Copy_pvoidApplication;
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
            Timer_pfTimer0[0]();
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
            Timer_pfTimer0[1]();
        }
        
    }
    
}

/* Prototype for ISR of ICU */
void __vector_6(void)   __attribute__((signal));
void __vector_6(void)
{
        if (Timer_pfTimer0[2] != NULL)
        {
            Timer_pfTimer0[2]();
        }
    
}