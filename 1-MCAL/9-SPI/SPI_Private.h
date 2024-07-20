/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 20/7/2024  ************************************/
/*************************** SWC : SPI         ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#define SPI_u8_SPCR_REGISTER *((volatile u8*)0x2D)
#define SPI_u8_SPSR_REGISTER *((volatile u8*)0x2E)
#define SPI_u8_SPDR_REGISTER *((volatile u8*)0x2F)

/* SPCR Bits */
#define SPI_u8_SPCR_SPIE_BIT 7
#define SPI_u8_SPCR_SPE_BIT 6
#define SPI_u8_SPCR_DORD_BIT 5
#define SPI_u8_SPCR_MSTR_BIT 4
#define SPI_u8_SPCR_CPOL_BIT 3
#define SPI_u8_SPCR_CPHA_BIT 2
#define SPI_u8_SPCR_SPR1_BIT 1
#define SPI_u8_SPCR_SPR0_BIT 0

/* SPSR Bits */
#define SPI_u8_SPSR_SPIF_BIT 7
#define SPI_u8_SPSR_WCOL_BIT 6
#define SPI_u8_SPSR_SPI2X_BIT 0


#define MASTER 1
#define SLAVE 2
 

#endif
