/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 6/6/2024   ************************************/
/*************************** SWC : ADC         ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/* Define ADC Registers */
#define ADC_u8_ADMUX_REGISTER   *((volatile u8 *)0x27)
#define ADC_u8_ADCSRA_REGISTER  *((volatile u8 *)0x26)
#define ADC_u8_ADCH_REGISTER    *((volatile u8 *)0x25)
#define ADC_u8_ADCL_REGISTER    *((volatile u8 *)0x24)
#define ADC_u8_SFIOR_REGISTER   *((volatile u8 *)0x50)


/* The ADC must first read ADC Low then ADC Hight to prevent losing data before read it
so we will cast the register of ADC_u8_ADCL_REGISTER to u16 so the pointer can see the ADCH and ADCL at once */
#define ADC_u16_ADC_REGISTER   *((volatile u16 *)0x24)

/* ADMUX Bits */
#define ADC_u8_ADMUX_REFS1 7
#define ADC_u8_ADMUX_REFS0 6
#define ADC_u8_ADMUX_ADLAR 5
#define ADC_u8_ADMUX_MUX4 4
#define ADC_u8_ADMUX_MUX3 3
#define ADC_u8_ADMUX_MUX2 2
#define ADC_u8_ADMUX_MUX1 1
#define ADC_u8_ADMUX_MUX0 0

/* ADCSRA Bits */
#define ADC_u8_ADCSRA_ADEN 7
#define ADC_u8_ADCSRA_ADSC 6
#define ADC_u8_ADCSRA_ADATE 5
#define ADC_u8_ADCSRA_ADIF 4
#define ADC_u8_ADCSRA_ADIE 3
#define ADC_u8_ADCSRA_ADPS2 2
#define ADC_u8_ADCSRA_ADPS1 1
#define ADC_u8_ADCSRA_ADPS0 0

/* SFIOR Bits */
#define ADC_u8_SFIOR_ADTS2 7
#define ADC_u8_SFIOR_ADTS1 6
#define ADC_u8_SFIOR_ADTS0 5

#endif