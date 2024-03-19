/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 17/3/2024  ************************************/
/*************************** SWC : DIO         ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/********************************************** The Main Functions used in DIO ***********************************************/
/*****************************************************************************************************************************/

/*init the DIO PINs*/
void DIO_voidInit(void);

/*Set the direction of the PIN by selecting port number, pin number and its direction and the return type u8 is indication
for the function is worked right or wrong*/
u8 DIO_u8SetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinDirection);

/*Set the value of the PIN after making it output and the return type u8 is indication
for the function is worked right or wrong*/
u8 DIO_u8SetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue);

/*Get the value of the PIN by pointer after making it input and the return type u8 is indication
for the function is worked right or wrong*/
u8 DIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 *Copy_pu8ReturnedPinValue);


/*Set the direction of the PORT by selecting port number and its direction and the return type u8 is indication
for the function is worked right or wrong*/
u8 DIO_u8SetPortDirection(u8 Copy_u8PortId, u8 Copy_u8PortDirection);

/*Set the value of the PORT after making it output and the return type u8 is indication
for the function is worked right or wrong*/
u8 DIO_u8SetPortValue(u8 Copy_u8PortId, u8 Copy_u8PortValue);

/*Get the value of the PORT by pointer after making it input and the return type u8 is indication
for the function is worked right or wrong*/
u8 DIO_u8GetPortValue(u8 Copy_u8PortId, u8 *Copy_pu8ReturnedPortValue);
/*****************************************************************************************************************************/

/**************************************************** Macros for PORTS *******************************************************/
#define DIO_u8_PORTA 0
#define DIO_u8_PORTB 1
#define DIO_u8_PORTC 2
#define DIO_u8_PORTD 3

/**************************************************** Macros for PINS *******************************************************/
#define DIO_u8_PIN0 0
#define DIO_u8_PIN1 1
#define DIO_u8_PIN2 2
#define DIO_u8_PIN3 3
#define DIO_u8_PIN4 4
#define DIO_u8_PIN5 5
#define DIO_u8_PIN6 6
#define DIO_u8_PIN7 7

/**************************************************** Macros for PIN Direction *******************************************************/
#define DIO_u8_OUTPUT 1
#define DIO_u8_INPUT 0

/**************************************************** Macros for PIN Value ******************************************************/
#define DIO_u8_HIGH 1
#define DIO_u8_LOW 0

#endif
