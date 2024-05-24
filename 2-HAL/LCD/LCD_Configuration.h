/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 24/5/2024  ************************************/
/*************************** HWC : LCD         ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
#ifndef LCD_CONFIGURATION_H
#define LCD_CONFIGURATION_H

/* This for ports used in functions */
/*Options : 1- DIO_u8_PORTA 
            2- DIO_u8_PORTB 
            3- DIO_u8_PORTC
            4- DIO_u8_PORTD */
#define LCD_u8_CONTROL_PORT DIO_u8_PORTA
#define LCD_u8_DATA_PORT DIO_u8_PORTB


/* This for pins used in functions */
/*Options : 1- DIO_u8_PIN0 
            2- DIO_u8_PIN1 
            3- DIO_u8_PIN2
            4- DIO_u8_PIN3
            4- DIO_u8_PIN4
            4- DIO_u8_PIN5
            4- DIO_u8_PIN6
            4- DIO_u8_PIN7 */
#define LCD_u8_RS_PIN DIO_u8_PIN0
#define LCD_u8_RW_PIN DIO_u8_PIN1
#define LCD_u8_E_PIN DIO_u8_PIN2

#endif