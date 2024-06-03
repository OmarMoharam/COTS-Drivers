#include<util/delay.h>
#define F_CPU 8000000UL

/*LIB*/
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

/* MCAL */
#include "EXTI_Interface.h"
#include "DIO_Interface.h"

#define EXTI_u8_SREG *((volatile u8 *)0x5F)

int main(void)
{
    DIO_voidInit();
    /* Enable GIE */
    SET_BIT(EXTI_u8_SREG,7);
    /* Enable EXTI0 */
    EXTI_voiEXTI0Enable();

    while(1); //super loop
    return 0;
}

/* Prototype for ISR of EXTI0 */
void __vector_1(void)     __attribute__((signal));
void __vector_1(void)
{
	static u8 Local_u8Flag = 0; // static to save the value of flag because when entering the ISR it saw the last version of the flag

	if (Local_u8Flag == 0) {
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
		Local_u8Flag = 1;
	}
	else {
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
		Local_u8Flag = 0;
	}
}
