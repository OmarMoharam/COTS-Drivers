/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 17/3/2024  ************************************/
/*************************** SWC : DIO         ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H
/*********************************************** Registers for DDR, PORT and PIN ************************************************/
/********************************************************************************************************************************/
#define DIO_u8_PORTA_REGISTER *((volatile u8 *)0x3B)
#define DIO_u8_DDRA_REGISTER  *((volatile u8 *)0x3A)
#define DIO_u8_PINA_REGISTER  *((volatile u8 *)0x39)

#define DIO_u8_PORTB_REGISTER *((volatile u8 *)0x38)
#define DIO_u8_DDRB_REGISTER  *((volatile u8 *)0x37)
#define DIO_u8_PINB_REGISTER  *((volatile u8 *)0x36)

#define DIO_u8_PORTC_REGISTER *((volatile u8 *)0x35)
#define DIO_u8_DDRC_REGISTER  *((volatile u8 *)0x34)
#define DIO_u8_PINC_REGISTER  *((volatile u8 *)0x33)

#define DIO_u8_PORTD_REGISTER *((volatile u8 *)0x32)
#define DIO_u8_DDRD_REGISTER  *((volatile u8 *)0x31)
#define DIO_u8_PIND_REGISTER  *((volatile u8 *)0x30)
/********************************************************************************************************************************/
/*************************************************** Macros for PINs DIRECTION ***************************************************/
#define DIO_u8_INIT_OUTPUT 1
#define DIO_u8_INIT_INPUT 0
/********************************************************************************************************************************/
/*************************************************** Macros for PINs VALUES ***************************************************/
#define DIO_u8_OUTPUT_LOW 0
#define DIO_u8_OUTPUT_HIGH 1
#define DIO_u8_INPUT_FLOATING 0
#define DIO_u8_INPUT_PULLUP 1

/* function to init PINs */
#define DIO_INIT(P7,P6,P5,P4,P3,P2,P1,P0)       DIO_INIT_HELP(P7,P6,P5,P4,P3,P2,P1,P0)
#define DIO_INIT_HELP(P7,P6,P5,P4,P3,P2,P1,P0)  0b##P7##P6##P5##P4##P3##P2##P1##P0

#endif
