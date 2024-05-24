/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 24/5/2024  ************************************/
/*************************** HWC : LCD         ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

/* function to init lcd as said in the datasheet*/
void LCD_voidInit(void);

/* there are to many commands for initiation and the only thing changed is the command
    so we use this function to reuse the same code*/
void LCD_voidSendCommand(u8 Copy_u8Command);

/*to send the characters one by one and is the same body as send command function */
void LCD_voidSendChar(u8 Copy_u8Char);

#endif