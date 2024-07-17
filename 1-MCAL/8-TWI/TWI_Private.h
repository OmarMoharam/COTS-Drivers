/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 12/7/2024  ************************************/
/*************************** SWC : TWI         ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
#ifndef TWI_PRIVATE_H
#define TWI_PRIVATE_H

/* TWI Registers */
#define TWI_u8_TWDR_REGISTER *((volatile u8*)0x23)
#define TWI_U8_TWAR_REGISTER *((volatile u8*)0x22)
#define TWI_u8_TWSR_REGISTER *((volatile u8*)0x21)
#define TWI_u8_TWBR_REGISTER *((volatile u8*)0x20)
#define TWI_u8_TWCR_REGISTER *((volatile u8*)0x56)

/* TWDR Bit */
#define TWI_U8_TWDR_RW_BIT 0

/* TWCR Bits */
#define TWI_u8_TWCR_TWINT_BIT 7
#define TWI_u8_TWCR_TWEA_BIT 6
#define TWI_u8_TWCR_TWSTA_BIT 5
#define TWI_u8_TWCR_TWSTO_BIT 4
#define TWI_u8_TWCR_TWWC_BIT 3
#define TWI_u8_TWCR_TWEN_BIT 2
#define TWI_u8_TWCR_TWIE_BIT 0

/* TWSR Bits */
#define TWI_u8_TWSR_TWPS1_BIT 1
#define TWI_u8_TWSR_TWPS0_BIT 0

/* TWAR Bits */
#define TWI_u8_TWAR_TWGCE_BIT 0

/* ACK for master transmitter mode */
#define MASTER_START_CONDITION 0X08
#define MASTER_REPEATED_START_CONDITION 0X10
#define MASTER_SLA_W_ACK 0x18
#define MASTER_SLA_W_NOT_ACK 0x20
#define MASTER_DATA_TRANSMITTED_ACK 0x28
#define MASTER_DATA_TRANSMITTED_NOT_ACK 0x30

/* ACK for master receiver mode */
#define MASTER_SLA_R_ACK 0x40
#define MASTER_SLA_R_NOT_ACK 0x48
#define MASTER_DATA_RECEIVED_ACK 0x50
#define MASTER_DATA_RECEIVED_NOT_ACK 0x58

/* ACK for slave transmitter mode */
#define SLAVE_SLA_R_ACK 0xA8
#define SLAVE_DATA_TRANSMITTED_ACK 0xB8
#define SLAVE_DATA_TRANSMITTED_NOT_ACK 0xC0

/* ACK for slave receiver mode */
#define SLAVE_SLA_W_ACK 0x60
#define SLAVE_DATA_RECEIVED_ACK 0x80
#define SLAVE_DATA_RECEIVED_NOT_ACK 0x88
#define SLAVE_STOP_OR_REPEATED 0XA0


#endif