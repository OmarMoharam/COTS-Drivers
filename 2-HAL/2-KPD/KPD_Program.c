/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 27/5/2024  ************************************/
/*************************** HWC : Keypad      ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
/********************************************************************/
/************************ Author: Omar Tarek ************************/
/************************ Date : 2/8/2024    ************************/
/************************ SWC : KPD          ************************/
/************************ Government : ITI   ************************/
/************************ Diploma : One Month  **********************/
/********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#define F_CPU 8000000UL
#include <util/delay.h>

/* MCAL */
#include "DIO_Interface.h"

/* HAL */
#include "KPD_Interface.h"
#include "KPD_Configuration.h"
#include "KPD_Private.h"

const u8 KPD_Au8Keys[4][4] = KPD_KEYS;

const u8 KPD_Au8RowsPins[4] = {KPD_u8_R1_PIN, KPD_u8_R2_PIN, KPD_u8_R3_PIN, KPD_u8_R4_PIN};
const u8 KPD_Au8ColumnsPins[4] = {KPD_u8_C1_PIN, KPD_u8_C2_PIN, KPD_u8_C3_PIN, KPD_u8_C4_PIN};

u8 KPD_u8GetKeyState(u8 *Copy_Pu8ReturnedKey)
{
    u8 Local_u8ErrorState = STD_TYPE_OK;

    u8 Local_u8RowsCounter, Local_u8ColumnsCounter, Local_u8PinValue, Local_u8Flag = 0;

    /* this condition should be exist at any pointer */
    if (Copy_Pu8ReturnedKey != NULL)
    {
    	/* This value returned if there is no key pressed */
    	 *Copy_Pu8ReturnedKey = KPD_u8_KEY_NOT_PRESSED;

        /* Activate each row */
        for (Local_u8RowsCounter = 0; Local_u8RowsCounter <= 3; Local_u8RowsCounter++)
        {
            DIO_u8SetPinValue(KPD_u8_ROW_PORT, KPD_Au8RowsPins[Local_u8RowsCounter], DIO_u8_LOW);

            /* scan every column to see if there is a pressed button = 0 */
            for (Local_u8ColumnsCounter = 0; Local_u8ColumnsCounter <= 3; Local_u8ColumnsCounter++)
            {
                DIO_u8GetPinValue(KPD_u8_COLUMN_PORT, KPD_Au8ColumnsPins[Local_u8ColumnsCounter], &Local_u8PinValue);
                 /* if any button pressed return its value 'ASCII' from the above array */
                if (Local_u8PinValue == DIO_u8_LOW)
                {
                    /* Debouncing */
                    _delay_ms(20);
                    DIO_u8GetPinValue(KPD_u8_COLUMN_PORT, KPD_Au8ColumnsPins[Local_u8ColumnsCounter], &Local_u8PinValue);

                    /* check if the pin is still low */
                    while (Local_u8PinValue == DIO_u8_LOW)
                    {
                        DIO_u8GetPinValue(KPD_u8_COLUMN_PORT, KPD_Au8ColumnsPins[Local_u8ColumnsCounter], &Local_u8PinValue);
                    }
        
                    *Copy_Pu8ReturnedKey = KPD_Au8Keys[Local_u8RowsCounter][Local_u8ColumnsCounter];
                    Local_u8Flag = 1;
                    break;
                }
                
            }
            DIO_u8SetPinValue(KPD_u8_ROW_PORT, KPD_Au8RowsPins[Local_u8RowsCounter], DIO_u8_HIGH);
            if (Local_u8Flag == 1)
            {
                break;
            }
            
        }
        
    }
    else
    {
        Local_u8ErrorState = STD_TYPE_NOK;
    }
    return Local_u8ErrorState;
}
