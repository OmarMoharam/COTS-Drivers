/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 17/3/2024  ************************************/
/*************************** SWC : DIO         ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/

/*1st LIB Layer*/
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

/*2nd MCAL form down to up*/
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "DIO_Configuration.h"

void DIO_voidInit(void)
{
    DIO_u8_DDRA_REGISTER = DIO_INIT(DIO_u8_PA7_INIT_DIRECTION,DIO_u8_PA6_INIT_DIRECTION,DIO_u8_PA5_INIT_DIRECTION,DIO_u8_PA4_INIT_DIRECTION,
						   DIO_u8_PA3_INIT_DIRECTION,DIO_u8_PA2_INIT_DIRECTION,DIO_u8_PA1_INIT_DIRECTION,DIO_u8_PA0_INIT_DIRECTION);
    
    DIO_u8_DDRB_REGISTER = DIO_INIT(DIO_u8_PB7_INIT_DIRECTION,DIO_u8_PB6_INIT_DIRECTION,DIO_u8_PB5_INIT_DIRECTION,DIO_u8_PB4_INIT_DIRECTION,
						   DIO_u8_PB3_INIT_DIRECTION,DIO_u8_PB2_INIT_DIRECTION,DIO_u8_PB1_INIT_DIRECTION,DIO_u8_PB0_INIT_DIRECTION);
    
    DIO_u8_DDRC_REGISTER = DIO_INIT(DIO_u8_PC7_INIT_DIRECTION,DIO_u8_PC6_INIT_DIRECTION,DIO_u8_PC5_INIT_DIRECTION,DIO_u8_PC4_INIT_DIRECTION,
						   DIO_u8_PC3_INIT_DIRECTION,DIO_u8_PC2_INIT_DIRECTION,DIO_u8_PC1_INIT_DIRECTION,DIO_u8_PC0_INIT_DIRECTION);
    
    DIO_u8_DDRD_REGISTER = DIO_INIT(DIO_u8_PD7_INIT_DIRECTION,DIO_u8_PD6_INIT_DIRECTION,DIO_u8_PD5_INIT_DIRECTION,DIO_u8_PD4_INIT_DIRECTION,
						   DIO_u8_PD3_INIT_DIRECTION,DIO_u8_PD2_INIT_DIRECTION,DIO_u8_PD1_INIT_DIRECTION,DIO_u8_PD0_INIT_DIRECTION);

    DIO_u8_PORTA_REGISTER = DIO_INIT(DIO_u8_PA7_INIT_VALUE,DIO_u8_PA6_INIT_VALUE,DIO_u8_PA5_INIT_VALUE,DIO_u8_PA4_INIT_VALUE,
						   DIO_u8_PA3_INIT_VALUE,DIO_u8_PA2_INIT_VALUE,DIO_u8_PA1_INIT_VALUE,DIO_u8_PA0_INIT_VALUE);
											                    
	DIO_u8_PORTB_REGISTER = DIO_INIT(DIO_u8_PB7_INIT_VALUE,DIO_u8_PB6_INIT_VALUE,DIO_u8_PB5_INIT_VALUE,DIO_u8_PB4_INIT_VALUE,
						   DIO_u8_PB3_INIT_VALUE,DIO_u8_PB2_INIT_VALUE,DIO_u8_PB1_INIT_VALUE,DIO_u8_PB0_INIT_VALUE);
											 
	DIO_u8_PORTC_REGISTER = DIO_INIT(DIO_u8_PC7_INIT_VALUE,DIO_u8_PC6_INIT_VALUE,DIO_u8_PC5_INIT_VALUE,DIO_u8_PC4_INIT_VALUE,
						   DIO_u8_PC3_INIT_VALUE,DIO_u8_PC2_INIT_VALUE,DIO_u8_PC1_INIT_VALUE,DIO_u8_PC0_INIT_VALUE);
											 
	DIO_u8_PORTD_REGISTER = DIO_INIT(DIO_u8_PD7_INIT_VALUE,DIO_u8_PD6_INIT_VALUE,DIO_u8_PD5_INIT_VALUE,DIO_u8_PD4_INIT_VALUE,
						   DIO_u8_PD3_INIT_VALUE,DIO_u8_PD2_INIT_VALUE,DIO_u8_PD1_INIT_VALUE,DIO_u8_PD0_INIT_VALUE);

}


u8 DIO_u8SetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinDirection)
{
    u8 Local_u8ErrorState = STD_TYPE_OK;
    if ((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId <= DIO_u8_PIN7) && ((Copy_u8PinDirection == DIO_u8_OUTPUT) || (Copy_u8PinDirection == DIO_u8_INPUT)))
    {
        switch (Copy_u8PortId)
        {
        case DIO_u8_PORTA:
            switch (Copy_u8PinDirection)
            {
            case DIO_u8_OUTPUT:SET_BIT(DIO_u8_DDRA_REGISTER,Copy_u8PinId);break;
            case DIO_u8_INPUT:CLR_BIT(DIO_u8_DDRA_REGISTER,Copy_u8PinId);break;
            }
            break;
        
        case DIO_u8_PORTB:
            switch (Copy_u8PinDirection)
            {
            case DIO_u8_OUTPUT:SET_BIT(DIO_u8_DDRB_REGISTER,Copy_u8PinId);break;
            case DIO_u8_INPUT:CLR_BIT(DIO_u8_DDRB_REGISTER,Copy_u8PinId);break;
            }
            break;

        case DIO_u8_PORTC:
            switch (Copy_u8PinDirection)
            {
            case DIO_u8_OUTPUT:SET_BIT(DIO_u8_DDRC_REGISTER,Copy_u8PinId);break;
            case DIO_u8_INPUT:CLR_BIT(DIO_u8_DDRC_REGISTER,Copy_u8PinId);break;
            }
            break;

        case DIO_u8_PORTD:
            switch (Copy_u8PinDirection)
            {
            case DIO_u8_OUTPUT:SET_BIT(DIO_u8_DDRD_REGISTER,Copy_u8PinId);break;
            case DIO_u8_INPUT:CLR_BIT(DIO_u8_DDRD_REGISTER,Copy_u8PinId);break;
            }
            break;
        default:Local_u8ErrorState = STD_TYPE_NOK;
            break;
        }
    }
    else
    {
        Local_u8ErrorState = STD_TYPE_NOK;
    }
    return Local_u8ErrorState;
}
/**********************************************************************************************************************************/

u8 DIO_u8SetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue)
{
    u8 Local_u8ErrorState = STD_TYPE_OK;

    if (Copy_u8PinId <= DIO_u8_PIN7)
    {
        switch (Copy_u8PortId)
        {
        case DIO_u8_PORTA:
            switch (Copy_u8PinValue)
            {
            case DIO_u8_HIGH:SET_BIT(DIO_u8_PORTA_REGISTER,Copy_u8PinId);break;
            case DIO_u8_LOW:CLR_BIT(DIO_u8_PORTA_REGISTER,Copy_u8PinId);break;
            default:Local_u8ErrorState = STD_TYPE_NOK;
                break;
            }
            break;
        
        case DIO_u8_PORTB:
            switch (Copy_u8PinValue)
            {
            case DIO_u8_HIGH:SET_BIT(DIO_u8_PORTB_REGISTER,Copy_u8PinId);break;
            case DIO_u8_LOW:CLR_BIT(DIO_u8_PORTB_REGISTER,Copy_u8PinId);break;
            default:Local_u8ErrorState = STD_TYPE_NOK;
                break;
            }
            break;

        case DIO_u8_PORTC:
            switch (Copy_u8PinValue)
            {
            case DIO_u8_HIGH:SET_BIT(DIO_u8_PORTC_REGISTER,Copy_u8PinId);break;
            case DIO_u8_LOW:CLR_BIT(DIO_u8_PORTC_REGISTER,Copy_u8PinId);break;
            default:Local_u8ErrorState = STD_TYPE_NOK;
                break;
            }
            break;
            
        case DIO_u8_PORTD:
            switch (Copy_u8PinValue)
            {
            case DIO_u8_HIGH:SET_BIT(DIO_u8_PORTD_REGISTER,Copy_u8PinId);break;
            case DIO_u8_LOW:CLR_BIT(DIO_u8_PORTD_REGISTER,Copy_u8PinId);break;
            default:Local_u8ErrorState = STD_TYPE_NOK;
                break;
            }
            break;

        default:Local_u8ErrorState = STD_TYPE_NOK;
            break;
        }
    }
    else
    {
        Local_u8ErrorState = STD_TYPE_NOK;
    }
    
    return Local_u8ErrorState;
}
/**********************************************************************************************************************************/

u8 DIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 *Copy_pu8ReturnedPinValue)
{
    u8 Local_u8ErrorState = STD_TYPE_OK;
    u8 Local_u8PinValue;

    if ((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId <= DIO_u8_PIN7) && (Copy_pu8ReturnedPinValue != NULL))
    {
        switch (Copy_u8PortId)
        {
        case DIO_u8_PORTA:Local_u8PinValue = GET_BIT(DIO_u8_PINA_REGISTER,Copy_u8PinId);
            if (Local_u8PinValue == 0)
            {
                *Copy_pu8ReturnedPinValue = DIO_u8_LOW;
            }
            else
            {
                *Copy_pu8ReturnedPinValue = DIO_u8_HIGH;
            }
            break;
        
        case DIO_u8_PORTB:Local_u8PinValue = GET_BIT(DIO_u8_PINB_REGISTER,Copy_u8PinId);
            if (Local_u8PinValue == 0)
            {
                *Copy_pu8ReturnedPinValue = DIO_u8_LOW;
            }
            else
            {
                *Copy_pu8ReturnedPinValue = DIO_u8_HIGH;
            }
            break;

        case DIO_u8_PORTC:Local_u8PinValue = GET_BIT(DIO_u8_PINC_REGISTER,Copy_u8PinId);
            if (Local_u8PinValue == 0)
            {
                *Copy_pu8ReturnedPinValue = DIO_u8_LOW;
            }
            else
            {
                *Copy_pu8ReturnedPinValue = DIO_u8_HIGH;
            }
            break;

        case DIO_u8_PORTD:Local_u8PinValue = GET_BIT(DIO_u8_PIND_REGISTER,Copy_u8PinId);
            if (Local_u8PinValue == 0)
            {
                *Copy_pu8ReturnedPinValue = DIO_u8_LOW;
            }
            else
            {
                *Copy_pu8ReturnedPinValue = DIO_u8_HIGH;
            }
            break;

        default:
            break;
        }
    }
    else
    {
        Local_u8ErrorState = STD_TYPE_NOK;
    }
    
    return Local_u8ErrorState;
}
/**********************************************************************************************************************************/

u8 DIO_u8SetPortDirection(u8 Copy_u8PortId, u8 Copy_u8PortDirection)
{
    u8 Local_u8ErrorState = STD_TYPE_OK;

    if (Copy_u8PortDirection == DIO_u8_OUTPUT || Copy_u8PortDirection == DIO_u8_INPUT)
    {
        switch (Copy_u8PortId)
        {
        case DIO_u8_PORTA:
            switch (Copy_u8PortDirection)
            {
            case DIO_u8_OUTPUT : DIO_u8_DDRA_REGISTER = 0xff;break;
            case DIO_u8_INPUT : DIO_u8_DDRA_REGISTER = 0x00;break;
            }
            break;
        
        case DIO_u8_PORTB:
            switch (Copy_u8PortDirection)
            {
            case DIO_u8_OUTPUT : DIO_u8_DDRB_REGISTER = 0xff;break;
            case DIO_u8_INPUT : DIO_u8_DDRB_REGISTER = 0x00;break;
            }
            break;

        case DIO_u8_PORTC:
            switch (Copy_u8PortDirection)
            {
            case DIO_u8_OUTPUT : DIO_u8_DDRC_REGISTER = 0xff;break;
            case DIO_u8_INPUT : DIO_u8_DDRC_REGISTER = 0x00;break;
            }
            break;

        case DIO_u8_PORTD:
            switch (Copy_u8PortDirection)
            {
            case DIO_u8_OUTPUT : DIO_u8_DDRD_REGISTER = 0xff;break;
            case DIO_u8_INPUT : DIO_u8_DDRD_REGISTER = 0x00;break;
            }
            break;        

        default: Local_u8ErrorState = STD_TYPE_NOK;
            break;
        }
    }
    else
    {
        Local_u8ErrorState = STD_TYPE_NOK;
    }
    
    return Local_u8ErrorState;
}
/**********************************************************************************************************************************/

u8  DIO_u8SetPortValue    (u8 Copy_u8PortId, u8 Copy_u8PortValue)
{
	u8 Local_u8ErrorState = STD_TYPE_OK;
	switch (Copy_u8PortId)
	{
		case DIO_u8_PORTA:DIO_u8_PORTA_REGISTER = Copy_u8PortValue;break;
		case DIO_u8_PORTB:DIO_u8_PORTB_REGISTER = Copy_u8PortValue;break;
		case DIO_u8_PORTC:DIO_u8_PORTC_REGISTER = Copy_u8PortValue;break;
		case DIO_u8_PORTD:DIO_u8_PORTD_REGISTER = Copy_u8PortValue;break;
		default : Local_u8ErrorState = STD_TYPE_NOK;
	}
	return Local_u8ErrorState;
}
/**********************************************************************************************************************************/

u8 DIO_u8GetPortValue(u8 Copy_u8PortId, u8 *Copy_pu8ReturnedPortValue)
{
    u8 Local_u8ErrorState = STD_TYPE_OK;

    if (Copy_pu8ReturnedPortValue != NULL)
    {
        switch (Copy_u8PortId)
        {
        case DIO_u8_PORTA: *Copy_pu8ReturnedPortValue = DIO_u8_PINA_REGISTER;break;
        case DIO_u8_PORTB: *Copy_pu8ReturnedPortValue = DIO_u8_PINB_REGISTER;break;
        case DIO_u8_PORTC: *Copy_pu8ReturnedPortValue = DIO_u8_PINC_REGISTER;break;
        case DIO_u8_PORTD: *Copy_pu8ReturnedPortValue = DIO_u8_PIND_REGISTER;break;

        default: Local_u8ErrorState = STD_TYPE_NOK;
            break;
        }
    }
    else
    {
        Local_u8ErrorState = STD_TYPE_NOK;
    }
    
    return Local_u8ErrorState;
}
