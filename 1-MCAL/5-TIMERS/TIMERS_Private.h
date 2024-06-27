/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 22/6/2024  ************************************/
/*************************** SWC : TIMERS      ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
#ifndef TIMERS_PRIVATE_H
#define TIMERS_PRIVATE_H

/* All Timers Flags */
#define TIMER_u8_TIMSK_REGISTER *((volatile u8 *)0x59)
#define TIMER_u8_TIFR_REGISTER *((volatile u8 *)0x58)

/* Bits of TIMSK */
#define TIMER_TIMSK_OCIE2_BIT 7
#define TIMER_TIMSK_TOIE2_BIT 6
#define TIMER_TIMSK_TICIE1_BIT 5
#define TIMER_TIMSK_OCIE1A_BIT 4
#define TIMER_TIMSK_OCIE1B_BIT 3
#define TIMER_TIMSK_TOIE1_BIT 2
#define TIMER_TIMSK_OCIE0_BIT 1
#define TIMER_TIMSK_TOIE0_BIT 0

/* Bits of TIFR */
#define TIMER_TIFR_OCF2_BIT 7
#define TIMER_TIFR_TOV2_BIT 6
#define TIMER_TIFR_ICF1_BIT 5
#define TIMER_TIFR_OCF1A_BIT 4
#define TIMER_TIFR_OCF1B_BIT 3
#define TIMER_TIFR_TOV1_BIT 2
#define TIMER_TIFR_OCF0_BIT 1
#define TIMER_TIFR_TOV0_BIT 0

/********************************************* Timer 0 *********************************************/
/* registers for Timer/Counter 0 */
#define TIMER_u8_TCCR0_REGISTER *((volatile u8 *)0x53)
#define TIMER_u8_TCNT0_REGISTER *((volatile u8 *)0x52)
#define TIMER_u8_OCR0_REGISTER *((volatile u8 *)0x5C)

/* Bits of TCCR0 */
#define TIMER_TCCR0_FOC0_BIT 7
#define TIMER_TCCR0_WGM00_BIT 6
#define TIMER_TCCR0_COM01_BIT 5
#define TIMER_TCCR0_COM00_BIT 4
#define TIMER_TCCR0_WGM01_BIT 3
#define TIMER_TCCR0_CS02_BIT 2
#define TIMER_TCCR0_CS01_BIT 1
#define TIMER_TCCR0_CS00_BIT 0

/***************************************************************************************************/
/********************************************* Timer 1 *********************************************/
#define TIMER_u8_TCCR1A_REGISTER *((volatile u8 *)0x4F)
#define TIMER_u8_TCCR1B_REGISTER *((volatile u8 *)0x4E)

#define TIMER_u8_TCNT1H_REGISTER *((volatile u8 *)0x4D)
#define TIMER_u8_TCNT1L_REGISTER *((volatile u8 *)0x4C)
#define TIMER_u16_TCNT1_REGISTER *((volatile u16 *)0x4C)

#define TIMER_u8_OCR1AH_REGISTER *((volatile u8 *)0x4B)
#define TIMER_u8_OCR1AL_REGISTER *((volatile u8 *)0x4A)
#define TIMER_u16_OCR1A_REGISTER *((volatile u16 *)0x4A)

#define TIMER_u8_OCR1BH_REGISTER *((volatile u8 *)0x49)
#define TIMER_u8_OCR1BL_REGISTER *((volatile u8 *)0x48)
#define TIMER_u16_OCR1B_REGISTER *((volatile u16 *)0x48)

#define TIMER_u8_ICR1AH_REGISTER *((volatile u8 *)0x47)
#define TIMER_u8_ICR1AL_REGISTER *((volatile u8 *)0x46)
#define TIMER_u16_ICR1A_REGISTER *((volatile u16 *)0x46)

/* Bits of TCCR1A */
#define TIMER_TCCR1A_COM1A1_BIT 7
#define TIMER_TCCR1A_COM1A0_BIT 6
#define TIMER_TCCR1A_COM1B1_BIT 5
#define TIMER_TCCR1A_COM1B0_BIT 4
#define TIMER_TCCR1A_FOC1A_BIT 3
#define TIMER_TCCR1A_FOC1B_BIT 2
#define TIMER_TCCR1A_WGM11_BIT 1
#define TIMER_TCCR1A_WGM10_BIT 0

/* Bits of TCCR1B */
#define TIMER_TCCR1B_ICNC1_BIT 7
#define TIMER_TCCR1B_ICES1_BIT 6
#define TIMER_TCCR1B_WGM13_BIT 4
#define TIMER_TCCR1B_WGM12_BIT 3
#define TIMER_TCCR1B_CS12_BIT 2
#define TIMER_TCCR1B_CS11_BIT 1
#define TIMER_TCCR1B_CS10_BIT 0

#endif