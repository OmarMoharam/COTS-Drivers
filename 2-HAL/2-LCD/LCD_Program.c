/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 24/5/2024  ************************************/
/*************************** HWC : LCD         ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
/* LIB */
#include"STD_TYPES.h"
#include"BIT_MATHS.h"
#define F_CPU 8000000UL
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
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
    _delay_us(1);
    /* E = 0 */
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
    _delay_us(1);
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
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
    _delay_us(1);
    /* E = 0 */
    DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
    _delay_us(1);
}


void LCD_voidSendString(u8 *Copy_Pu8String)
{
    /* we send the string character by character and when he reaches the \0 it terminates */
    while (*Copy_Pu8String != '\0')
    {
        LCD_voidSendChar(*Copy_Pu8String);
        Copy_Pu8String++;
    }

}

void  LCD_voidSendNumber(u32 Copy_u32Number)
{
    u8 Local_u8NumberOfCharacter = 0;
    u8 Local_u8ReverseCounter;
    u8 Local_u8Temp;
    u8 Local_u8ConvertedNumber[LCD_u8_Numbers];

    if (Copy_u32Number == 0)
    {
        Local_u8ConvertedNumber[Local_u8NumberOfCharacter++] = 0;
        Local_u8ConvertedNumber[Local_u8NumberOfCharacter] = '\0';
        LCD_voidSendString(Local_u8ConvertedNumber);
        return;
    }

    /* loop to convert each number to a string but reversed */
    while (Copy_u32Number != 0)
    {
        Local_u8ConvertedNumber[Local_u8NumberOfCharacter++] = (Copy_u32Number % 10) + '0';
        Copy_u32Number /= 10;
    }
    Local_u8ConvertedNumber[Local_u8NumberOfCharacter] = '\0';

    /* loop to reverse the number to its original arrangement */
    for (Local_u8ReverseCounter = 0; Local_u8ReverseCounter < Local_u8NumberOfCharacter / 2; Local_u8ReverseCounter++)
    {
        Local_u8Temp = Local_u8ConvertedNumber[Local_u8ReverseCounter];
        Local_u8ConvertedNumber[Local_u8ReverseCounter] = Local_u8ConvertedNumber[Local_u8NumberOfCharacter - Local_u8ReverseCounter - 1];
        Local_u8ConvertedNumber[Local_u8NumberOfCharacter - Local_u8ReverseCounter - 1] = Local_u8Temp;
    }

    LCD_voidSendString(Local_u8ConvertedNumber);

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

void LCD_voidClear(void)
{
    LCD_voidSendCommand(0x01);
    _delay_us(2);
}

void LCD_voidSendSpecialCharacter(u8 Copy_u8CharLocation, u8 *Copy_Pu8SpecialChar, u8 Copy_u8LineNumber, u8 Copy_u8Location)
{
    switch (Copy_u8CharLocation)
    {
    case LCD_u8_CHAR_0: LCD_voidSendCommand(LCD_u8_CHAR_0_ADDRESS); break;
    case LCD_u8_CHAR_1: LCD_voidSendCommand(LCD_u8_CHAR_1_ADDRESS); break;
    case LCD_u8_CHAR_2: LCD_voidSendCommand(LCD_u8_CHAR_2_ADDRESS); break;
    case LCD_u8_CHAR_3: LCD_voidSendCommand(LCD_u8_CHAR_3_ADDRESS); break;
    case LCD_u8_CHAR_4: LCD_voidSendCommand(LCD_u8_CHAR_4_ADDRESS); break;
    case LCD_u8_CHAR_5: LCD_voidSendCommand(LCD_u8_CHAR_5_ADDRESS); break;
    case LCD_u8_CHAR_6: LCD_voidSendCommand(LCD_u8_CHAR_6_ADDRESS); break;
    case LCD_u8_CHAR_7: LCD_voidSendCommand(LCD_u8_CHAR_7_ADDRESS); break;

    default: return; break;
    }

    LCD_voidSendCommand(Copy_u8CharLocation);

    for (u8 Local_u8Counter = 0; Local_u8Counter < 8; Local_u8Counter++)
    {
        LCD_voidSendChar(*(Copy_Pu8SpecialChar++));
    }

    LCD_voidGoToXY(Copy_u8LineNumber, Copy_u8Location);
    LCD_voidSendChar(Copy_u8CharLocation);

}

void LCD_voidShiftDisplay(u8 Copy_u8ShiftDirection, u32 Copy_u8DelayBtwSteps, u32 Copy_u8Duration)
{
    u8 Local_u8StartTime = 0;
    u8 Local_u8CurrentTime = 0;

    while (Local_u8CurrentTime - Local_u8StartTime < Copy_u8Duration)
    {
        if (Copy_u8ShiftDirection == 0)
        {
            LCD_voidSendCommand(0x18);
        }
        else
        {
            LCD_voidSendCommand(0x1C);
        }
        
        _delay_ms(Copy_u8DelayBtwSteps);

        Local_u8CurrentTime += Copy_u8DelayBtwSteps; 
    }
    

}