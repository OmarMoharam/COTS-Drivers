/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 30/6/2024  ************************************/
/*************************** HWC : Servo Motor ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "TIMERS_Configuration.h"
#include "TIMERS_Interface.h"
#include "TIMERS_Private.h"

#include "SERVO_Inteface.h"
#include "SERVO_Configuration.h"
#include "SERVO_Private.h"

void SERVO_voidInit(void)
{
    Timer_voidInitTimer1();
}

u8 SERVO_u8SetAngle(u8 Copy_u8Angle)
{
    u8 Local_u8ErrorState = STD_TYPE_OK;
    u16 Local_u16OCRValue;
    if (Copy_u8Angle >= SERVO_u8_MIN_ANGLE && Copy_u8Angle <= SERVO_u8_MAX_ANGLE)
    {
        Local_u16OCRValue =( (Copy_u8Angle - SERVO_u8_MIN_ANGLE) * ((SERVO_u8_MAX_OCR - SERVO_u8_MIN_OCR) / (SERVO_u8_MAX_ANGLE - SERVO_u8_MIN_ANGLE)) )+ SERVO_u8_MIN_OCR;
        Timer_voidTimer1SetCompareMatchValue(Local_u16OCRValue);
    }
    else
    {
        Local_u8ErrorState = STD_TYPE_NOK;
    }
    
    return Local_u8ErrorState;
}