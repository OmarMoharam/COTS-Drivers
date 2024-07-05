#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "TIMERS_Interface.h"
#include "EXTI_Interface.h"
#include "GI_Interface.h"
#include "LCD_Interface.h"

static u16 periodTime = 0;
static u16 onTime = 0;

void ICU_SW(void);

int main(void)
{
    DIO_voidInit();
    LCD_voidInit();

    Timer_voidInitTimer0();
    Timer_voidInitTimer1();


    EXTI_u8EXTISetCallBack(EXTI_u8_INT0, &ICU_SW);
    EXTI_u8Enable(EXTI_u8_INT0, EXTI_u8_RISING_EDGE);

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

void ICU_SW(void)
{
    static u8 counter = 0;
    counter++;
    if(counter == 1)
    {
        Timer_voidTimer1SetValue(0); // Start the timer
    }
    else if(counter == 2)
    {
        periodTime = Timer_u16Timer1ReadValue(); // Capture the period time
        EXTI_u8Enable(EXTI_u8_INT0, EXTI_u8_FALLING_EDGE); // Switch to falling edge
    }
    else if(counter == 3)
    {
        onTime = Timer_u16Timer1ReadValue(); // Capture the on time
        onTime -= periodTime; // Calculate on time
        EXTI_u8Disable(EXTI_u8_INT0); // Disable interrupt
        counter = 0; // Reset the counter for next measurement
    }
}
