/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 12/7/2024  ************************************/
/*************************** SWC : TWI         ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "TWI_Private.h"
#include "TWI_Interface.h"
#include "TWI_Configuration.h"


void TWI_voidMasterInit(void)
{
    //set prescaler value
    CLR_BIT(TWI_u8_TWSR_REGISTER, TWI_u8_TWSR_TWPS1_BIT);
    CLR_BIT(TWI_u8_TWSR_REGISTER, TWI_u8_TWSR_TWPS0_BIT);
    
    //set TWBR with the value => 200KHZ
    TWI_u8_TWBR_REGISTER = 12;
    
    //Enable ACK
    SET_BIT(TWI_u8_TWCR_REGISTER, TWI_u8_TWCR_TWEA_BIT);
    
    //Enable I2C
    SET_BIT(TWI_u8_TWCR_REGISTER, TWI_u8_TWCR_TWEN_BIT);
}

TWI_ErrorState TWI_u8SlaveInit(u8 Copy_u8SlaveAddress)
{
    TWI_ErrorState Local_enuErrorState = TWI_OK;
    
    //set slave address TWAR ensure its within range and doesn't equal to a reserved address and slave address begin from bit 1
    if((Copy_u8SlaveAddress <= 127) && (Copy_u8SlaveAddress != 0) && (Copy_u8SlaveAddress <= 0xF0))
    {
        TWI_U8_TWAR_REGISTER = (Copy_u8SlaveAddress<<1);
        
        //Enable ACK
        SET_BIT(TWI_u8_TWCR_REGISTER, TWI_u8_TWCR_TWEA_BIT);
        
        //Enable I2C
        SET_BIT(TWI_u8_TWCR_REGISTER, TWI_u8_TWCR_TWEN_BIT);
    }
    
    else
    {
        Local_enuErrorState = TWI_SLA_Init_Error;
    }
    
    return Local_enuErrorState;
    
}

TWI_ErrorState TWI_u8SendStartCondition(void)
{
    TWI_ErrorState Local_enuErrorState = TWI_OK;
    
    //clear flag + start condition
    TWI_u8_TWCR_REGISTER = (1<<TWI_u8_TWCR_TWINT_BIT) | (1<<TWI_u8_TWCR_TWSTA_BIT) | (1 << TWI_u8_TWCR_TWEN_BIT);
    
    //check the flag while(!= 1) and should add
    while(!(GET_BIT(TWI_u8_TWCR_REGISTER, TWI_u8_TWCR_TWINT_BIT)));
    
    //check status code start condition ACK
    if (((TWI_u8_TWSR_REGISTER & 0xF8) != MASTER_START_CONDITION) )
    {
        Local_enuErrorState = TWI_SC_Error;
    }
    
    //clear start condition bit
    CLR_BIT(TWI_u8_TWCR_REGISTER, TWI_u8_TWCR_TWSTA_BIT);
    
    return Local_enuErrorState;
}

TWI_ErrorState TWI_u8SendRepeatedStartCondition(void)
{
    TWI_ErrorState Local_enuErrorState = TWI_OK;
    
    //clear flag + start condition
    TWI_u8_TWCR_REGISTER = (1<<TWI_u8_TWCR_TWINT_BIT) | (1<<TWI_u8_TWCR_TWSTA_BIT) | (1 << TWI_u8_TWCR_TWEN_BIT);
    
    //check the flag while(!= 1)
    while(!(GET_BIT(TWI_u8_TWCR_REGISTER, TWI_u8_TWCR_TWINT_BIT)));
    
    //check status code for repeated start condition ACK
    if (((TWI_u8_TWSR_REGISTER & 0xF8) != MASTER_REPEATED_START_CONDITION) )
    {
        Local_enuErrorState = TWI_RSC_Error;
    }
    
    //clear start condition bit
    CLR_BIT(TWI_u8_TWCR_REGISTER, TWI_u8_TWCR_TWSTA_BIT);
    return Local_enuErrorState;
}

TWI_ErrorState TWI_u8SendStopCondition(void)
{
    TWI_ErrorState Local_enuErrorState = TWI_OK;

    //clear flag + stop condition
    TWI_u8_TWCR_REGISTER = (1<<TWI_u8_TWCR_TWINT_BIT) | (1<<TWI_u8_TWCR_TWSTO_BIT) | (1 << TWI_u8_TWCR_TWEN_BIT);

    //check ACK
    if (((TWI_u8_TWSR_REGISTER & 0xF8) != SLAVE_STOP_OR_REPEATED) )
    {
        Local_enuErrorState = TWI_STC_Error;
    }

    return Local_enuErrorState;
    
}

TWI_ErrorState TWI_u8SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
    TWI_ErrorState Local_enuErrorState = TWI_OK;
    
    //write slave address + 0 in TWDR
    TWI_u8_TWDR_REGISTER = (Copy_u8SlaveAddress<<1) | (0<<TWI_U8_TWDR_RW_BIT);
    //clear flag
    TWI_u8_TWCR_REGISTER = (1<<TWI_u8_TWCR_TWINT_BIT) | (1 << TWI_u8_TWCR_TWEN_BIT);
    
    //check the flag while(!= 1)
    while(!(GET_BIT(TWI_u8_TWCR_REGISTER, TWI_u8_TWCR_TWINT_BIT)));

    //check status code slave address + Write ACK
    if (((TWI_u8_TWSR_REGISTER & 0xF8) != MASTER_SLA_W_ACK) )
    {
        Local_enuErrorState = TWI_SLA_W_Error;
    }

    return Local_enuErrorState;


}

TWI_ErrorState TWI_u8SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
    TWI_ErrorState Local_enuErrorState = TWI_OK;
    
    //write slave address + 0 in TWDR
    TWI_u8_TWDR_REGISTER = (Copy_u8SlaveAddress<<1) | (1<<TWI_U8_TWDR_RW_BIT);
    //clear flag
    TWI_u8_TWCR_REGISTER = (1<<TWI_u8_TWCR_TWINT_BIT) | (1 << TWI_u8_TWCR_TWEN_BIT);
    
    //check the flag while(!= 1)
    while(!(GET_BIT(TWI_u8_TWCR_REGISTER, TWI_u8_TWCR_TWINT_BIT)));

    //check status code slave address + read ACK
    if (((TWI_u8_TWSR_REGISTER & 0xF8) != MASTER_SLA_R_ACK) )
    {
        Local_enuErrorState = TWI_SLA_R_Error;
    }

    return Local_enuErrorState;

}

TWI_ErrorState TWI_u8SendDataByte(u8 Copy_u8DataByte)
{
    TWI_ErrorState Local_enuErrorState = TWI_OK;

    //write data in TWDR
    TWI_u8_TWDR_REGISTER = Copy_u8DataByte;

    //clear flag
    TWI_u8_TWCR_REGISTER = (1<<TWI_u8_TWCR_TWINT_BIT) | (1 << TWI_u8_TWCR_TWEN_BIT);
    
    //check the flag while(!= 1)
    while(!(GET_BIT(TWI_u8_TWCR_REGISTER, TWI_u8_TWCR_TWINT_BIT)));

    //check status code master send data ACK
    if (((TWI_u8_TWSR_REGISTER & 0xF8) != MASTER_DATA_TRANSMITTED_ACK) )
    {
        Local_enuErrorState = TWI_MT_DATA_Error;
    }

    return Local_enuErrorState;
}

TWI_ErrorState TWI_u8RecieveDataByte(u8 *Copy_pu8DataByte)
{
    TWI_ErrorState Local_enuErrorState = TWI_OK;

    //check pointer
    if (Copy_pu8DataByte != NULL)
    {
        //clear flag
        TWI_u8_TWCR_REGISTER = (1<<TWI_u8_TWCR_TWINT_BIT) | (1 << TWI_u8_TWCR_TWEN_BIT);

        //check the flag while(!= 1)
        while(!(GET_BIT(TWI_u8_TWCR_REGISTER, TWI_u8_TWCR_TWINT_BIT)));

        //check status code master read data ACK
        if (((TWI_u8_TWSR_REGISTER & 0xF8) != MASTER_DATA_RECEIVED_ACK) )
        {
        Local_enuErrorState = TWI_MR_DATA_Error;
        }
        else
        {
            //read data in TWDR
            *Copy_pu8DataByte = TWI_u8_TWDR_REGISTER;

        }
        
    }
    else
    {
        Local_enuErrorState = TWI_NULL_POINTER;
    }
    
    return Local_enuErrorState;

    
}