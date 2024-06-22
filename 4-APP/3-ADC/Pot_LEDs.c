#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "DIO_Interface.h"
#include "ADC_Interface.h"

int main(void)
{
	u16 Local_u16DigitalValue, Local_u8AnalogValue;
	DIO_voidInit();
	ADC_voidInit();

	while(1)
	{
		ADC_u8GetDigitalValue(ADC_CHANNEL_0, &Local_u16DigitalValue);
		Local_u8AnalogValue = (u16)((Local_u16DigitalValue * 5000UL) / 1024); //to solve float number we * 1000 and convert the V to mV

		if (Local_u8AnalogValue <= 1500) {
			// Turn On LED 1
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_LOW);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_LOW);
		}
		else if ((Local_u8AnalogValue > 1500) && (Local_u8AnalogValue <= 3000)) {
			// Turn On LED 1 and LED 2
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_HIGH);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_LOW);
		}
		else if (Local_u8AnalogValue > 3000) {
			// Turn On LED 1, LED 2 and LED 3
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_HIGH);
			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_HIGH);
		}
	}

	return 0;
}
