/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 6/7/2024   ************************************/
/*************************** SWC : UART        ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

void UART_voidInit(u16 Copy_u16BaudRate);
void UART_voidSendByte(u8 Copy_u8SendData);
u8 UART_u8RecieveByte(u8 * Copy_pu8RecieveDate);

#endif