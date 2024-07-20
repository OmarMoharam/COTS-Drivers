/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 20/7/2024  ************************************/
/*************************** SWC : SPI         ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void SPI_voidInit(void);
void SPI_voidSendDataSlave(u8 Copy_u8DataSent);
u8 SPI_u8SendRecieve(u8 Copy_u8DataSent, u8 *Copy_pu8DataRecieved);
u8 SPI_u8RecieveData(u8 *Copy_pu8DataRecieved);
#endif
