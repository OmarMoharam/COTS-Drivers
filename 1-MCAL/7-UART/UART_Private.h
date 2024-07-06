/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 6/7/2024   ************************************/
/*************************** SWC : UART        ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#define UART_u8_UDR_REGISTER    *((volatile u8*)0x2C) //read = RX, write = TX
#define UART_u8_UCSRA_REGISTER  *((volatile u8*)0x2B)
#define UART_u8_UCSRB_REGISTER  *((volatile u8*)0x2A)
#define UART_u8_UCSRC_REGISTER  *((volatile u8*)0x40)
#define UART_u8_UBRRH_REGISTER  *((volatile u8*)0x40)
#define UART_u8_UBRRL_REGISTER  *((volatile u8*)0x29)

#define UART_u16_UBRR_REGISTER  *((volatile u16*)0x29) // we can't do this because the Low and High UBRR is not in sequence with each other


/* UCSRA Bits */
#define UART_u8_UCSRA_RXC_BIT 7
#define UART_u8_UCSRA_TXC_BIT 6
#define UART_u8_UCSRA_UDRE_BIT 5
#define UART_u8_UCSRA_FE_BIT 4
#define UART_u8_UCSRA_DOR_BIT 3
#define UART_u8_UCSRA_PE_BIT 2
#define UART_u8_UCSRA_U2X_BIT 1
#define UART_u8_UCSRA_MPCM_BIT 0

/* UCSRB Bits */
#define UART_u8_UCSRB_RXCIE_BIT 7
#define UART_u8_UCSRB_TXCIE_BIT 6
#define UART_u8_UCSRB_UDRIE_BIT 5
#define UART_u8_UCSRB_RXEN_BIT 4
#define UART_u8_UCSRB_TXEN_BIT 3
#define UART_u8_UCSRB_UCSZ2_BIT 2
#define UART_u8_UCSRB_RXB8_BIT 1
#define UART_u8_UCSRB_TXB8_BIT 0

/* UCSRC Bits */
#define UART_u8_UCSRC_URSEL_BIT 7
#define UART_u8_UCSRC_UMSEL_BIT 6
#define UART_u8_UCSRC_UPM1_BIT 5
#define UART_u8_UCSRC_UPM0_BIT 4
#define UART_u8_UCSRC_USBS_BIT 3
#define UART_u8_UCSRC_UCSZ1_BIT 2
#define UART_u8_UCSRC_UCSZ0_BIT 1
#define UART_u8_UCSRC_UCPOL_BIT 0

/********************* Macros for configurations *********************/
#define ASYNCHRONOUS 0
#define SYNCHRONOUS  1

#define DISABLE 0
#define ENABLE 1

#define FIVE_BITS 5
#define SIX_BITS 6
#define SEVEN_BITS 7
#define EIGHT_BITS 8
#define NINE_BITS 9

#define ENABLE_EVEN 1
#define ENABLE_ODD 2

#define ONE_BIT 1
#define TWO_BITS 2


#endif