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
#define DIO_u8_PORTA_REGISTER *((volatile *)0x3B)
#define DIO_u8_DDRA_REGISTER  *((volatile *)0x3A)
#define DIO_u8_PINA_REGISTER  *((volatile *)0x39)

#define DIO_u8_PORTB_REGISTER *((volatile *)0x38)
#define DIO_u8_DDRB_REGISTER  *((volatile *)0x37)
#define DIO_u8_PINB_REGISTER  *((volatile *)0x36)

#define DIO_u8_PORTC_REGISTER *((volatile *)0x35)
#define DIO_u8_DDRC_REGISTER  *((volatile *)0x34)
#define DIO_u8_PINC_REGISTER  *((volatile *)0x33)

#define DIO_u8_PORTD_REGISTER *((volatile *)0x32)
#define DIO_u8_DDRD_REGISTER  *((volatile *)0x31)
#define DIO_u8_PIND_REGISTER  *((volatile *)0x30)
/********************************************************************************************************************************/

#endif