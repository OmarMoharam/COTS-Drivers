/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 24/5/2024  ************************************/
/*************************** HWC : LCD         ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
/* LIB */
#include"STD_TYPES.h"
#include"BIT_MATHS.h"
#define F_CFU 8000000
#include<util/delay.h>

/* MCAL */
#include"DIO_Interface.h"

/* HAL */
#include"LCD_Interface.h"
#include"LCD_Private.h"
#include"LCD_Configuration.h"

void LCD_voidInit(void)
{
    /* Function Set */
    _delay_us(35);
    LCD_voidSendCommand(0b00111000);
    /* Display ON/OFF Control */
    _delay_us(40);
    LCD_voidSendCommand(0b00001111);
    /* Display Clear */
    _delay_us(40);
    LCD_voidSendCommand(0b00000001);
    /* Entry Mode Set */
    _delay_us(2);
    LCD_voidSendCommand(0b00000110);
}

void LCD_voidSendCommand(u8 Copy_u8Command)
{
    /* RS = 0 */
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_LOW);
    /* R/W = 0 */
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
    /* Write the command */
    DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Command);
    /* E = 1 and we should make a delay presented in the datasheet */
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
    _delay_us(1);
    /* E = 0 */
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
}

void LCD_voidSendChar(u8 Copy_u8Char)
{
     /* RS = 1 */
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_HIGH);
    /* R/W = 0 */
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
    /* Write the character */
    DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Char);
    /* E = 1 and we should make a delay presented in the datasheet */
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
    _delay_us(1);
    /* E = 0 */
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
}

void LCD_voidSendString(u8 *Copy_Pu8String)
{
    while (*Copy_Pu8String != '\0')
    {
        LCD_voidSendChar(*Copy_Pu8String);
        Copy_Pu8String++;
    }
    
}

u8 LCD_voidGoToXY(u8 Copy_u8LineNumber, u8 Copy_u8Location)
{
    u8 Local_u8ErrorState = STD_TYPE_OK;
    if (Copy_u8Location <= 39)
    {
        switch (Copy_u8LineNumber)
        {
        case LCD_u8_LINE1:LCD_voidSendCommand(0x80+Copy_u8Location); break;
        case LCD_u8_LINE2:LCD_voidSendCommand(0xC0+Copy_u8Location); break;
        default: Local_u8ErrorState = STD_TYPE_NOK; break;
        }
    }
    else
    {
        Local_u8ErrorState = STD_TYPE_NOK;
    }
    return Local_u8ErrorState;
}