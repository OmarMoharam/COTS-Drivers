#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "DIO_Interface.h"
#include "TIMERS_Interface.h"
#include "GI_Interface.h"

void toggle_led(void);
int main(void)
{
    DIO_voidInit();
    GI_voidEnable();

    /* SET CALL Back "Should be implemented before enable timer"*/
    Timer_u8Timer0SetCallBackOVF(&toggle_led);

    Timer_voidInit;

    while (1);
    return 0;
}

void toggle_led(void)
{
    static u8 flag = 0;
    if (flag == 0)
    {
        DIO_u8SetPinValue(DIO_u8_PORTA, DIO_u8_PIN0, DIO_u8_HIGH);
        flag = 1;
    }
    else
    {
        DIO_u8SetPinValue(DIO_u8_PORTA, DIO_u8_PIN0, DIO_u8_LOW);
        flag = 0;
    }
    
}