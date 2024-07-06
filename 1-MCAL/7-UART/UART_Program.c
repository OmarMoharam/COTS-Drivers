/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 6/7/2024   ************************************/
/*************************** SWC : UART        ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "UART_Private.h"
#include "UART_Configuration.h"
#include "UART_Interface.h"


void UART_voidInit(u16 Copy_u16BaudRate)
{
    u16 Local_u8UBRRValue;
    u8 Local_u8UCSRCValue = 0b10000000;

    /******************** Write the baud rate ********************/
    #if (U2X_MODE == DISABLE) && (USART_MODE == ASYNCHRONOUS)
    Local_u8UBRRValue = (CPU_FREQUENCY / (Copy_u16BaudRate * 16UL)) - 1;
    UART_u8_UBRRL_REGISTER = (u8)(Local_u8UBRRValue);
    UART_u8_UBRRH_REGISTER = (u8)(Local_u8UBRRValue>>8);

    #elif (U2X_MODE == ENABLE) && (USART_MODE == ASYNCHRONOUS)
    Local_u8UBRRValue = (CPU_FREQUENCY / (Copy_u16BaudRate * 8UL)) - 1;
    UART_u8_UBRRL_REGISTER = (u8)(Local_u8UBRRValue);
    UART_u8_UBRRH_REGISTER = (u8)(Local_u8UBRRValue>>8);

    #elif (USART_MODE == SYNCHRONOUS)
    Local_u8UBRRValue = (CPU_FREQUENCY / (Copy_u16BaudRate * 2UL)) - 1;
    UART_u8_UBRRL_REGISTER = (u8)(Local_u8UBRRValue);
    UART_u8_UBRRH_REGISTER = (u8)(Local_u8UBRRValue>>8);
    #endif

    /******************* Select Mode Asynchronous, Synchronous *******************/
    #if USART_MODE == ASYNCHRONOUS

    CLR_BIT(Local_u8UCSRCValue, UART_u8_UCSRC_UMSEL_BIT);
    
    /* Disable MPCM */
    CLR_BIT(UART_u8_UCSRA_REGISTER, UART_u8_UCSRA_MPCM_BIT);

        #if U2X_MODE == ENABLE
        SET_BIT(UART_u8_UCSRA_REGISTER, UART_u8_UCSRA_U2X_BIT);
        #elif U2X_MODE == DISABLE
        CLR_BIT(UART_u8_UCSRA_REGISTER, UART_u8_UCSRA_U2X_BIT);
        #endif
    
    #elif USART_MODE == SYNCHRONOUS
    
    SET_BIT(Local_u8UCSRCValue, UART_u8_UCSRC_UMSEL_BIT);

    /* Disable U2X */
    CLR_BIT(UART_u8_UCSRA_REGISTER, UART_u8_UCSRA_U2X_BIT);

        #if MPCM_MODE == ENABLE
        SET_BIT(UART_u8_UCSRA_REGISTER, UART_u8_UCSRA_MPCM_BIT);
        #elif MPCM_MODE == DISABLE
        CLR_BIT(UART_u8_UCSRA_REGISTER, UART_u8_UCSRA_MPCM_BIT);
        #endif
    #endif

    /******************* Enable Rx and Tx *******************/
    SET_BIT(UART_u8_UCSRB_REGISTER, UART_u8_UCSRB_TXEN_BIT);
    SET_BIT(UART_u8_UCSRB_REGISTER, UART_u8_UCSRB_RXEN_BIT);
    
    /******************* Choose Character Size *******************/
    #if CHARCTER_SIZE == FIVE_BITS
    CLR_BIT(UART_u8_UCSRB_REGISTER, UART_u8_UCSRB_UCSZ2_BIT);
    CLR_BIT(Local_u8UCSRCValue, UART_u8_UCSRC_UCSZ1_BIT);
    CLR_BIT(Local_u8UCSRCValue, UART_u8_UCSRC_UCSZ0_BIT);
   
    #elif CHARCTER_SIZE == SIX_BITS
    CLR_BIT(UART_u8_UCSRB_REGISTER, UART_u8_UCSRB_UCSZ2_BIT);
    CLR_BIT(Local_u8UCSRCValue, UART_u8_UCSRC_UCSZ1_BIT);
    SET_BIT(Local_u8UCSRCValue, UART_u8_UCSRC_UCSZ0_BIT);
   
    #elif CHARCTER_SIZE == SEVEN_BITS
    CLR_BIT(UART_u8_UCSRB_REGISTER, UART_u8_UCSRB_UCSZ2_BIT);
    SET_BIT(Local_u8UCSRCValue, UART_u8_UCSRC_UCSZ1_BIT);
    CLR_BIT(Local_u8UCSRCValue, UART_u8_UCSRC_UCSZ0_BIT);

    #elif CHARCTER_SIZE == EIGHT_BITS
    CLR_BIT(UART_u8_UCSRB_REGISTER, UART_u8_UCSRB_UCSZ2_BIT);
    SET_BIT(Local_u8UCSRCValue, UART_u8_UCSRC_UCSZ1_BIT);
    SET_BIT(Local_u8UCSRCValue, UART_u8_UCSRC_UCSZ0_BIT);
    
    #elif CHARCTER_SIZE == NINE_BITS
    SET_BIT(UART_u8_UCSRB_REGISTER, UART_u8_UCSRB_UCSZ2_BIT);
    SET_BIT(Local_u8UCSRCValue, UART_u8_UCSRC_UCSZ1_BIT);
    SET_BIT(Local_u8UCSRCValue, UART_u8_UCSRC_UCSZ0_BIT);
    #endif

    /******************* Choose Parity bit *******************/
    #if PARITY_BIT == ENABLE_EVEN
    SET_BIT(Local_u8UCSRCValue, UART_u8_UCSRC_UPM1_BIT);
    CLR_BIT(Local_u8UCSRCValue, UART_u8_UCSRC_UPM0_BIT);

    #elif PARITY_BIT == ENABLE_ODD
    SET_BIT(Local_u8UCSRCValue, UART_u8_UCSRC_UPM1_BIT);
    SET_BIT(Local_u8UCSRCValue, UART_u8_UCSRC_UPM0_BIT);

    #elif PARITY_BIT == DISABLE
    CLR_BIT(Local_u8UCSRCValue, UART_u8_UCSRC_UPM1_BIT);
    CLR_BIT(Local_u8UCSRCValue, UART_u8_UCSRC_UPM0_BIT);
    #endif
    

    /******************* Choose Stop Bit *******************/
    #if STOP_BIT == ONE_BIT
    CLR_BIT(Local_u8UCSRCValue, UART_u8_UCSRC_USBS_BIT);

    #elif STOP_BIT == TWO_BITS
    SET_BIT(Local_u8UCSRCValue, UART_u8_UCSRC_USBS_BIT);
    #endif

    UART_u8_UCSRC_REGISTER = Local_u8UCSRCValue;
}

void UART_voidSendByte(u8 Copy_u8SendData)
{
    /* Check Data register is empty */
    while((GET_BIT(UART_u8_UCSRA_REGISTER, UART_u8_UCSRA_UDRE_BIT)) == 0);

    /* Check Transmit Complete */
    while((GET_BIT(UART_u8_UCSRA_REGISTER, UART_u8_UCSRA_TXC_BIT)) == 0);

    /* Send Data */
    UART_u8_UDR_REGISTER = Copy_u8SendData;
}

u8 UART_u8RecieveByte(u8 * Copy_pu8RecieveDate)
{
    u8 Local_u8ErrorState = STD_TYPE_OK;
    if (Copy_pu8RecieveDate != NULL)
    {
         /* Check Reciever Complete */
        while((GET_BIT(UART_u8_UCSRA_REGISTER, UART_u8_UCSRA_RXC_BIT)) == 0);

        /* Recieve Data */
        * Copy_pu8RecieveDate = UART_u8_UDR_REGISTER;
    }
    else
    {
        Local_u8ErrorState = STD_TYPE_NOK;
    }
   
    return Local_u8ErrorState;
}
