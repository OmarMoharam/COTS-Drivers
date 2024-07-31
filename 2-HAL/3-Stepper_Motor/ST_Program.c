/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 30/5/2024  ************************************/
/*************************** HWC : Stepper Motor **********************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/

#include<util/delay.h>
#define F_CPU 8000000UL

/*LIB*/
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

/* MCAL */
#include "DIO_Interface.h"

/* HAL */
#include "ST_Interface.h"
#include "ST_Configration.h"
#include "ST_Private.h"

u8 ST_u8MoveMotor(u8 Copy_u8Direction, u16 Copy_u16Degree)
{
    u8 Local_u8ErrorState = STD_TYPE_OK;
    while (Copy_u16Degree > 360) {Copy_u16Degree -= 360;}
    
    /* Number of steps */

    u16 Local_u16NumberOfSteps, Local_u16Iteration, Local_u16Counter;
    Local_u16NumberOfSteps = ( ( Copy_u16Degree * 2048UL ) / 360 );
    Local_u16Iteration = (Local_u16NumberOfSteps / 4);

    switch (Copy_u8Direction)
    {
    case ST_u8_CCW:
        for (Local_u16Counter = 0; Local_u16Counter <= Local_u16Iteration; Local_u16Counter++)
        {
            /********************* CCW *****************************/
            //step 1
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_BLUE_PIN, DIO_u8_LOW); //blue
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_PINK_PIN, DIO_u8_HIGH); //pink
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_YELLOW_PIN, DIO_u8_HIGH); //yellow
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_ORANGE_PIN, DIO_u8_HIGH); //orange
            _delay_ms(10); //for the step to complete
            //step 2
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_BLUE_PIN, DIO_u8_HIGH); //blue
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_PINK_PIN, DIO_u8_LOW); //pink
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_YELLOW_PIN, DIO_u8_HIGH); //yellow
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_ORANGE_PIN, DIO_u8_HIGH); //orange
            _delay_ms(10); //for the step to complete
            //step 3
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_BLUE_PIN, DIO_u8_HIGH); //blue
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_PINK_PIN, DIO_u8_HIGH); //pink
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_YELLOW_PIN, DIO_u8_LOW); //yellow
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_ORANGE_PIN, DIO_u8_HIGH); //orange
            _delay_ms(10); //for the step to complete
            //step 4
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_BLUE_PIN, DIO_u8_HIGH); //blue
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_PINK_PIN, DIO_u8_HIGH); //pink
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_YELLOW_PIN, DIO_u8_HIGH); //yellow
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_ORANGE_PIN, DIO_u8_LOW); //orange
            _delay_ms(10); //for the step to complete
        }
        break;
        
    case ST_u8_CW:
        for (Local_u16Counter = 0; Local_u16Counter <= Local_u16Iteration; Local_u16Counter++)
        {
            /********************* CW *****************************/
            //step 1
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_BLUE_PIN, DIO_u8_HIGH); //blue
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_PINK_PIN, DIO_u8_HIGH); //pink
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_YELLOW_PIN, DIO_u8_HIGH); //yellow
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_ORANGE_PIN, DIO_u8_LOW); //orange
            _delay_ms(10); //for the step to complete
            //step 2
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_BLUE_PIN, DIO_u8_HIGH); //blue
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_PINK_PIN, DIO_u8_HIGH); //pink
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_YELLOW_PIN, DIO_u8_LOW); //yellow
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_ORANGE_PIN, DIO_u8_HIGH); //orange
            _delay_ms(10); //for the step to complete
            //step 3
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_BLUE_PIN, DIO_u8_HIGH); //blue
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_PINK_PIN, DIO_u8_LOW); //pink
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_YELLOW_PIN, DIO_u8_HIGH); //yellow
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_ORANGE_PIN, DIO_u8_HIGH); //orange
            _delay_ms(10); //for the step to complete
            //step 4
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_BLUE_PIN, DIO_u8_LOW); //blue
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_PINK_PIN, DIO_u8_HIGH); //pink
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_YELLOW_PIN, DIO_u8_HIGH); //yellow
            DIO_u8SetPinValue(ST_u8_PORT, ST_u8_ORANGE_PIN, DIO_u8_HIGH); //orange
            _delay_ms(10); //for the step to complete
        }
        break;
        
    default:
        Local_u8ErrorState = STD_TYPE_NOK;
        break;
    }
    
    return Local_u8ErrorState;
    
}
