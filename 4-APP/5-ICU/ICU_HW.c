#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "TIMERS_Interface.h"
#include "GI_Interface.h"
#include "LCD_Interface.h"

static u16 periodTime = 0;
static u16 onTime = 0;

void ICU_HW(void);

int main(void)
{
    DIO_voidInit();
    LCD_voidInit();

    ICU_u8SetCallBack(&ICU_HW);
    ICU_voidInit();

    Timer_voidInitTimer0();
    Timer_voidInitTimer1();


    GI_voidEnable();



    while(1)
    {
        while((periodTime == 0) && (onTime == 0));
        LCD_voidGoToXY(LCD_u8_LINE1, 0);
        LCD_voidSendString("Period Time: ");
        LCD_voidSendNumber(periodTime);
        LCD_voidGoToXY(LCD_u8_LINE2, 0);
        LCD_voidSendString("ON Time: ");
        LCD_voidSendNumber(onTime);
    }

    return 0;
}

void ICU_HW(void)
{
    static u8 counter = 0;
    static u16 reading1 = 0, reading2 = 0, reading3 = 0;
    counter++;
    if(counter == 1)
    {
       reading1 = ICU_u16ReadValue(); // Start the timer
    }
    else if(counter == 2)
    {
    	reading2 = ICU_u16ReadValue();
        periodTime = reading2 - reading1; // Capture the period time
        ICU_u8SetTriggerEdge(Timer_u8_ICU_FALLING_EDGE); // Switch to falling edge
    }
    else if(counter == 3)
    {
    	reading3 = ICU_u16ReadValue();
        onTime = reading3 - reading2;
        ICU_voidDisableInterrupt(); // Disable interrupt
        counter = 0; // Reset the counter for next measurement
    }
}
