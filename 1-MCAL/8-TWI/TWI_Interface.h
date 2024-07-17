/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 12/7/2024  ************************************/
/*************************** SWC : TWI         ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
#ifndef TWI_INTERFACE_H
#define TWI_INTERFACE_H

void TWI_voidMasterInit(void);
u8 TWI_u8SlaveInit(u8 Copy_u8SlaveAddress);
u8 TWI_u8SendStartCondition(void);
u8 TWI_u8SendRepeatedStartCondition(void);
u8 TWI_u8SendStopCondition(void);
u8 TWI_u8SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);
u8 TWI_u8SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);
u8 TWI_u8SendDataByte(u8 Copy_u8DataByte);
u8 TWI_u8RecieveDataByte(u8 *Copy_pu8DataByte);


#endif