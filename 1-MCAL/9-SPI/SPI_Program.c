/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 20/7/2024  ************************************/
/*************************** SWC : SPI         ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "SPI_Private.h"
#include "SPI_Configuration.h"
#include "SPI_Interface.h"

void SPI_voidInit(void)
{
    #if SPI_u8_MODE == MASTER
    /* choose data order */
    CLR_BIT(SPI_u8_SPCR_REGISTER, SPI_u8_SPCR_DORD_BIT);

    /* select master mode */
    SET_BIT(SPI_u8_SPCR_REGISTER, SPI_u8_SPCR_MSTR_BIT);

    /* choose clk */
    SET_BIT(SPI_u8_SPCR_REGISTER, SPI_u8_SPCR_SPR1_BIT);
    CLR_BIT(SPI_u8_SPCR_REGISTER, SPI_u8_SPCR_SPR0_BIT);

    
    /* choose CPOL */
    SET_BIT(SPI_u8_SPCR_REGISTER, SPI_u8_SPCR_CPOL_BIT);
    SET_BIT(SPI_u8_SPCR_REGISTER, SPI_u8_SPCR_CPHA_BIT);

    #elif SPI_u8_MODE == SLAVE
    /* choose data order */
    CLR_BIT(SPI_u8_SPCR_REGISTER, SPI_u8_SPCR_DORD_BIT);

    /* select master mode */
    CLR_BIT(SPI_u8_SPCR_REGISTER, SPI_u8_SPCR_MSTR_BIT);

    /* choose CPOL */
    SET_BIT(SPI_u8_SPCR_REGISTER, SPI_u8_SPCR_CPOL_BIT);
    SET_BIT(SPI_u8_SPCR_REGISTER, SPI_u8_SPCR_CPHA_BIT);

    #endif
    
    /* enable SPI */
    SET_BIT(SPI_u8_SPCR_REGISTER, SPI_u8_SPCR_SPE_BIT);
}

void SPI_voidSendDataSlave(u8 Copy_u8DataSent)
{
    //send data byte
    SPI_u8_SPDR_REGISTER = Copy_u8DataSent;

    //check if the transmission is completed
    //while((GET_BIT(SPI_u8_SPSR_REGISTER, SPI_u8_SPSR_SPIF_BIT)) == 0);
}

u8 SPI_u8RecieveData(u8 *Copy_pu8DataRecieved)
{
    u8 Local_u8ErrorState = STD_TYPE_OK;

    if (Copy_pu8DataRecieved != NULL)
    {
        //check if the transmission is completed
        while((GET_BIT(SPI_u8_SPSR_REGISTER, SPI_u8_SPSR_SPIF_BIT)) == 0);

        //read byte
        *Copy_pu8DataRecieved = SPI_u8_SPDR_REGISTER;
    }
    else
    {
        Local_u8ErrorState = STD_TYPE_NOK;
    }
    return Local_u8ErrorState
    
}

u8 SPI_u8SendRecieve(u8 Copy_u8DataSent, u8 *Copy_pu8DataRecieved)
{
    u8 Local_u8ErrorState = STD_TYPE_OK;

    if (Copy_pu8DataRecieved != NULL)
    {
        //send data byte
        SPI_u8_SPDR_REGISTER = Copy_u8DataSent;

        //check if the transmission is completed
        while((GET_BIT(SPI_u8_SPSR_REGISTER, SPI_u8_SPSR_SPIF_BIT)) == 0);

        //read byte
        *Copy_pu8DataRecieved = SPI_u8_SPDR_REGISTER;
    }
    else
    {
        Local_u8ErrorState = STD_TYPE_NOK;
    }
    return Local_u8ErrorState
    
    
}