/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 6/6/2024   ************************************/
/*************************** SWC : ADC         ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "ADC_Configuration.h"
#include "ADC_Interface.h"
#include "ADC_Private.h"

static void(*ADC_pfNotification)(u16) = NULL;

/* ADC busy flag */
static u8 ADC_u8BusyFlag = 0;

void ADC_voidInit(void)
{
    /* 1- Select VREF = AVCC
       2- Right Adjust
       3- Disable Auto Trigger
       4- Select CLK "Prescaler = 64"
       5- Enable ADC */

    CLR_BIT(ADC_u8_ADMUX_REGISTER, ADC_u8_ADMUX_REFS1);
    SET_BIT(ADC_u8_ADMUX_REGISTER, ADC_u8_ADMUX_REFS0);

    CLR_BIT(ADC_u8_ADMUX_REGISTER, ADC_u8_ADMUX_ADLAR);

    CLR_BIT(ADC_u8_ADCSRA_REGISTER, ADC_u8_ADCSRA_ADATE);

    SET_BIT(ADC_u8_ADCSRA_REGISTER, ADC_u8_ADCSRA_ADPS2);
    SET_BIT(ADC_u8_ADCSRA_REGISTER, ADC_u8_ADCSRA_ADPS1);
    CLR_BIT(ADC_u8_ADCSRA_REGISTER, ADC_u8_ADCSRA_ADPS0);

    SET_BIT(ADC_u8_ADCSRA_REGISTER, ADC_u8_ADCSRA_ADEN);
}

u8 ADC_u8GetDigitalValueSynchNonBlocking(u8 Copy_u8Channel, u16 *Copy_Pu16DigitalValue)
{
    u8 Local_u8ErrorState = STD_TYPE_OK;
    u32 Local_u32TimeOutCounter = 0;

    if ((Copy_u8Channel < 32) && (Copy_Pu16DigitalValue != NULL) && (ADC_u8BusyFlag == 0))
    {
        /* Make the ADC busy */
        ADC_u8BusyFlag = 1;

        /* 1- Select the channel */
        ADC_u8_ADMUX_REGISTER &= 0b11100000; //to clear the first 5 bit and keep the Most 3 bits
        ADC_u8_ADMUX_REGISTER |= Copy_u8Channel;

        /* 2- Start Conversion */
        SET_BIT(ADC_u8_ADCSRA_REGISTER, ADC_u8_ADCSRA_ADSC);

        /* 3- Wait till flag = 1 "Mean that the ADC is finished" */
        while ((!GET_BIT(ADC_u8_ADCSRA_REGISTER, ADC_u8_ADCSRA_ADIF)) && (Local_u32TimeOutCounter < ADC_u32_MAX_TIME_OUT))
        {
            Local_u32TimeOutCounter++;
        }

        if ((GET_BIT(ADC_u8_ADCSRA_REGISTER, ADC_u8_ADCSRA_ADIF)) != 0)
        {
            /* 4- Clear the flag */
            SET_BIT(ADC_u8_ADCSRA_REGISTER, ADC_u8_ADCSRA_ADIF);

            /* 5- Read the Digital Value */
            *Copy_Pu16DigitalValue = ADC_u16_ADC_REGISTER;
        }
        else
        {
            Local_u8ErrorState = STD_TYPE_NOK;
        }
        
    }
    else
    {
        Local_u8ErrorState = STD_TYPE_NOK;
    }

    /* Make the ADC unbusy */
    ADC_u8BusyFlag = 0;
    
    return Local_u8ErrorState;
}

u8 ADC_u8Asynchronous(u8 Copy_u8Channel, void(*Copy_pfNotification)(u16))
{
    u8 Local_u8ErrorState = STD_TYPE_OK;
    if ((Copy_u8Channel < 32) && (Copy_pfNotification != NULL) && (ADC_u8BusyFlag == 0))
    {
        /* Set flag to make ADC busy till it done from the current conversion */
        ADC_u8BusyFlag = 1;
        /* update global pointer to a function */
        ADC_pfNotification = Copy_pfNotification;

        /* Enable ADC Interrupt */
        SET_BIT(ADC_u8_ADCSRA_REGISTER, ADC_u8_ADCSRA_ADIE);

        /* 1- Select the channel */
        ADC_u8_ADMUX_REGISTER &= 0b11100000; //to clear the first 5 bit and keep the Most 3 bits
        ADC_u8_ADMUX_REGISTER |= Copy_u8Channel;

        /* 2- Start Conversion */
        SET_BIT(ADC_u8_ADCSRA_REGISTER, ADC_u8_ADCSRA_ADSC);
    }
    else
    {
        Local_u8ErrorState = STD_TYPE_NOK;
    }
    return Local_u8ErrorState;
}

u8 ADC_u8GetDigitalValueAsyn(u16 *Copy_u16pu16DigitalValue)
{
    u8 Local_u8ErrorState = STD_TYPE_OK;
    if (Copy_u16pu16DigitalValue != NULL)
    {
        *Copy_u16pu16DigitalValue = ADC_u16_ADC_REGISTER;
    }
    else
    {
        Local_u8ErrorState = STD_TYPE_NOK;
    }

    return Local_u8ErrorState;
}

/* Prototype for ADC ISR */
void __vector_16(void)  __attribute__((signal));
void __vector_16(void)
{
    if (ADC_pfNotification != NULL)
    {
        /* Clear the flag */
        ADC_u8BusyFlag = 0;
        /* Clear PIE of ADC */
        SET_BIT(ADC_u8_ADCSRA_REGISTER, ADC_u8_ADCSRA_ADIF);
        /* Calling Notification function */
        ADC_pfNotification(ADC_u16_ADC_REGISTER);
    }
    
}