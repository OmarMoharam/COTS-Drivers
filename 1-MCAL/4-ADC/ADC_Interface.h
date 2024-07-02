/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 6/6/2024   ************************************/
/*************************** SWC : ADC         ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

void ADC_voidInit(void);
u8 ADC_u8GetDigitalValueSynchNonBlocking(u8 Copy_u8Channel, u16 * Copy_Pu16DigitalValue);
u8 ADC_u8Asynchronous(u8 Copy_u8Channel, void(*Copy_pfNotification)(u16));
u8 ADC_u8GetDigitalValueAsyn(u16 *Copy_u16pu16DigitalValue);

/* Channel Numbers */
#define ADC_CHANNEL_0 0
#define ADC_CHANNEL_1 1
#define ADC_CHANNEL_2 2
#define ADC_CHANNEL_3 3
#define ADC_CHANNEL_4 4
#define ADC_CHANNEL_5 5
#define ADC_CHANNEL_6 6
#define ADC_CHANNEL_7 7

/* for no digital value */
#define ADC_u8_NO_DIGITAL_VALUE 0xFFFF;

#endif