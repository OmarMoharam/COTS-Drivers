/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 27/5/2024  ************************************/
/*************************** HWC : Keypad      ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
#ifndef KPD_CONFIGURATION_H
#define KPD_CONFIGURATION_H

/* Keypad Rows and Columns Ports */
#define KPD_u8_ROW_PORT DIO_u8_PORTA
#define KPD_u8_COLUMN_PORT DIO_u8_PORTA

/* Keypad Rows and Columns Pins */
#define KPD_u8_R1_PIN DIO_u8_PIN0
#define KPD_u8_R2_PIN DIO_u8_PIN1
#define KPD_u8_R3_PIN DIO_u8_PIN2
#define KPD_u8_R4_PIN DIO_u8_PIN3

#define KPD_u8_C1_PIN DIO_u8_PIN4
#define KPD_u8_C2_PIN DIO_u8_PIN5
#define KPD_u8_C3_PIN DIO_u8_PIN6
#define KPD_u8_C4_PIN DIO_u8_PIN7

/* Keypad keys */
#define KPD_KEYS {{'1' , '2' , '3' , '+'}, \
                  {'4' , '5' , '6' , '='}, \
                  {'7' , '8' , '9' , '-'}, \
                  {'/' , '0' , '%' , '*'}} 
#endif