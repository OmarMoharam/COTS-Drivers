#include<util/delay.h>
#define F_CPU 8000000UL

/*LIB*/
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

/* MCAL */
#include "EXTI_Interface.h"
#include "DIO_Interface.h"

int main(void)
{
    DIO_voidInit();
    return 0;
}
