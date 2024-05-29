/*
Connections : Seek the datasheet of the stepper motor
Red -> Common VCC
Activation Sequence :
                        1 -> Blue
                        2 -> Pink
                        3 -> Yellow
                        4 -> Orange
                        and all should get LOW PINs State to operate
Degree/Step : Seek datasheet of the stepper motor used ("Degree\Step" "Resolution" 
                                                        "Stride Angle(Smallest angle = angle/half step)")
Stride Angle = 5.625/64
Angle/Half Step = 0.08789 Degree
Angle/Full Step = 0.08789 Degree * 2 = 0.1757 Degree

1 Step ----> 0.1757 Degree
No. of Steps ----> 360 Degree
No. of Steps = 2048 Step/360 Degree
*/

#include<util/delay.h>
#define F_CPU 8000000UL

/*LIB*/
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

/* MCAL */
#include "DIO_Interface.h"

int main(void)
{
    DIO_voidInit();

    while (1)
    {
        for (u8  Local_u8Angel = 0; i < count; i++)
        {
            /********************* CCW *****************************/
            //step 1
            DIO_u8SetPinValue(DIO_u8_PORTA, DIO_u8_PIN0, DIO_u8_LOW); //blue
            DIO_u8SetPinValue(DIO_u8_PORTA, DIO_u8_PIN1, DIO_u8_HIGH); //pink
            DIO_u8SetPinValue(DIO_u8_PORTA, DIO_u8_PIN2, DIO_u8_HIGH); //yellow
            DIO_u8SetPinValue(DIO_u8_PORTA, DIO_u8_PIN3, DIO_u8_HIGH); //orange
            _delay_ms(10); //for the step to complete
            //step 2
            DIO_u8SetPinValue(DIO_u8_PORTA, DIO_u8_PIN0, DIO_u8_HIGH); //blue
            DIO_u8SetPinValue(DIO_u8_PORTA, DIO_u8_PIN1, DIO_u8_LOW); //pink
            DIO_u8SetPinValue(DIO_u8_PORTA, DIO_u8_PIN2, DIO_u8_HIGH); //yellow
            DIO_u8SetPinValue(DIO_u8_PORTA, DIO_u8_PIN3, DIO_u8_HIGH); //orange
            _delay_ms(10); //for the step to complete
            //step 3
            DIO_u8SetPinValue(DIO_u8_PORTA, DIO_u8_PIN0, DIO_u8_HIGH); //blue
            DIO_u8SetPinValue(DIO_u8_PORTA, DIO_u8_PIN1, DIO_u8_HIGH); //pink
            DIO_u8SetPinValue(DIO_u8_PORTA, DIO_u8_PIN2, DIO_u8_LOW); //yellow
            DIO_u8SetPinValue(DIO_u8_PORTA, DIO_u8_PIN3, DIO_u8_HIGH); //orange
            _delay_ms(10); //for the step to complete
            //step 4
            DIO_u8SetPinValue(DIO_u8_PORTA, DIO_u8_PIN0, DIO_u8_HIGH); //blue
            DIO_u8SetPinValue(DIO_u8_PORTA, DIO_u8_PIN1, DIO_u8_HIGH); //pink
            DIO_u8SetPinValue(DIO_u8_PORTA, DIO_u8_PIN2, DIO_u8_HIGH); //yellow
            DIO_u8SetPinValue(DIO_u8_PORTA, DIO_u8_PIN3, DIO_u8_LOW); //orange
            _delay_ms(10); //for the step to complete
        }
        
    }

    return 0;
}