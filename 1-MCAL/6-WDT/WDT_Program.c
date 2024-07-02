/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 30/6/2024  ************************************/
/*************************** HWC : Servo Motor ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "WDT_Interface.h"

#define WDT_u8_WDTCR_REGISTER *((volatile u8*)0x41)
#define WDT_u8_WDTCR_WDTOE 4
#define WDT_u8_WDTCR_WDE 3
#define WDT_u8_WDTCR_WDP2 2
#define WDT_u8_WDTCR_WDP1 1
#define WDT_u8_WDTCR_WDP0 0


u8 WDT_u8Enable(u8 Copy_u8Prescaler)
{
    u8 Local_u8ErrorState = STD_TYPE_OK;
    switch (Copy_u8Prescaler)
    {
    case WDT_u8_PRESCALER_16:
        WDT_u8_WDTCR_REGISTER |= (0<<WDT_u8_WDTCR_WDP2) | (0<<WDT_u8_WDTCR_WDP1) | (0<<WDT_u8_WDTCR_WDP0);
        WDT_u8_WDTCR_REGISTER |= (1<<WDT_u8_WDTCR_WDE);
        break;
    case WDT_u8_PRESCALER_32:
        WDT_u8_WDTCR_REGISTER |= (0<<WDT_u8_WDTCR_WDP2) | (0<<WDT_u8_WDTCR_WDP1) | (1<<WDT_u8_WDTCR_WDP0);
        WDT_u8_WDTCR_REGISTER |= (1<<WDT_u8_WDTCR_WDE);
        break;
    case WDT_u8_PRESCALER_64:
        WDT_u8_WDTCR_REGISTER |= (0<<WDT_u8_WDTCR_WDP2) | (1<<WDT_u8_WDTCR_WDP1) | (0<<WDT_u8_WDTCR_WDP0);
        WDT_u8_WDTCR_REGISTER |= (1<<WDT_u8_WDTCR_WDE);
        break;
    case WDT_u8_PRESCALER_128:
        WDT_u8_WDTCR_REGISTER |= (0<<WDT_u8_WDTCR_WDP2) | (1<<WDT_u8_WDTCR_WDP1) | (1<<WDT_u8_WDTCR_WDP0);
        WDT_u8_WDTCR_REGISTER |= (1<<WDT_u8_WDTCR_WDE);
        break;
    case WDT_u8_PRESCALER_256:
        WDT_u8_WDTCR_REGISTER |= (1<<WDT_u8_WDTCR_WDP2) | (0<<WDT_u8_WDTCR_WDP1) | (0<<WDT_u8_WDTCR_WDP0);
        WDT_u8_WDTCR_REGISTER |= (1<<WDT_u8_WDTCR_WDE);
        break;
    case WDT_u8_PRESCALER_512:
        WDT_u8_WDTCR_REGISTER |= (1<<WDT_u8_WDTCR_WDP2) | (0<<WDT_u8_WDTCR_WDP1) | (1<<WDT_u8_WDTCR_WDP0);
        WDT_u8_WDTCR_REGISTER |= (1<<WDT_u8_WDTCR_WDE);
        break;
    case WDT_u8_PRESCALER_1024:
        WDT_u8_WDTCR_REGISTER |= (1<<WDT_u8_WDTCR_WDP2) | (1<<WDT_u8_WDTCR_WDP1) | (0<<WDT_u8_WDTCR_WDP0);
        WDT_u8_WDTCR_REGISTER |= (1<<WDT_u8_WDTCR_WDE);
        break;
    case WDT_u8_PRESCALER_2048:
        WDT_u8_WDTCR_REGISTER |= (1<<WDT_u8_WDTCR_WDP2) | (1<<WDT_u8_WDTCR_WDP1) | (1<<WDT_u8_WDTCR_WDP0);
        WDT_u8_WDTCR_REGISTER |= (1<<WDT_u8_WDTCR_WDE);
        break;
    
    default:
        Local_u8ErrorState = STD_TYPE_NOK;
        break;
    }
    return Local_u8ErrorState;
}

void WDT_voidDisable(void)
{
    WDT_u8_WDTCR_REGISTER |= (1<<WDT_u8_WDTCR_WDE) | (1<<WDT_u8_WDTCR_WDTOE);
    WDT_u8_WDTCR_REGISTER = 0x00;
}
