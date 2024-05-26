/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 24/5/2024  ************************************/
/*************************** HWC : LCD         ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

/* Line Locations in DDRAM */
#define LCD_u8_LINE1 1
#define LCD_u8_LINE2 2

/* CGRAM Special Characters */
#define LCD_u8_CHAR_0 0
#define LCD_u8_CHAR_1 1
#define LCD_u8_CHAR_2 2
#define LCD_u8_CHAR_3 3
#define LCD_u8_CHAR_4 4
#define LCD_u8_CHAR_5 5
#define LCD_u8_CHAR_6 6
#define LCD_u8_CHAR_7 7

/* Direction of shifting for display */
#define LCD_u8_SHIFT_LEFT 0
#define LCD_u8_SHIFT_RIGHT 1

/* function to init lcd as said in the datasheet*/
void LCD_voidInit(void);

/* there are to many commands for initiation and the only thing changed is the command
    so we use this function to reuse the same code*/
void LCD_voidSendCommand(u8 Copy_u8Command);

/*to send the characters one by one and is the same body as send command function */
void LCD_voidSendChar(u8 Copy_u8Char);

/*to send the string one by one and is the same body as send command function
    the input shall be arr[] = {"Omar"} OR arr[] = {'O' , 'm' , 'a', 'r' , '\0'}*/
void LCD_voidSendString(u8 *Copy_Pu8String);

/*to send the number one by one and is the same body as send command function */
void LCD_voidSendNumber(u32 Copy_u32Number);

/* to go to a certain location in the LCD */
u8 LCD_voidGoToXY(u8 Copy_u8LineNumber, u8 Copy_u8Location);

/* to clear the screen */
void LCD_voidClear(void);

/* To send a special character */
void LCD_voidSendSpecialCharacter(u8 Copy_u8CharLocation, u8 *Copy_Pu8SpecialChar, u8 Copy_u8LineNumber, u8 Copy_u8Location);

/* shifting the display */
void LCD_voidShiftDisplay(u8 Copy_u8ShiftDirection, u32 Copy_u8DelayBtwSteps, u32 Copy_u8Duration);
#endif
