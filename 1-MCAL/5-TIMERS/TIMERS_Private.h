/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 22/6/2024  ************************************/
/*************************** SWC : TIMERS      ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
#ifndef TIMERS_PRIVATE_H
#define TIMERS_PRIVATE_H

/* registers for Timer/Counter 0 */
#define TIMER_u8_TCCR0_REGISTER *((volatile u8*)0x33)
#define TIMER_u8_TCNT0_REGISTER *((volatile u8*)0x52)
#define TIMER_u8_OCR0_REGISTER *((volatile u8*)0x5C)
#define TIMER_u8_TIMSK_REGISTER *((volatile u8*)0x59)
#define TIMER_u8_TIFR_REGISTER *((volatile u8*)0x58)

/* Bits of TCCR0 */
#define TIMER_TCCR0_FOC0_BIT 7
#define TIMER_TCCR0_WGM00_BIT 6
#define TIMER_TCCR0_COM01_BIT 5
#define TIMER_TCCR0_COM00_BIT 4
#define TIMER_TCCR0_WGM01_BIT 3
#define TIMER_TCCR0_CS02_BIT 2
#define TIMER_TCCR0_CS01_BIT 1
#define TIMER_TCCR0_CS00_BIT 0

/* Bits of TIMSK */
#define TIMER_TIMSK_OCIE0_BIT 1
#define TIMER_TIMSK_TOIE0_BIT 0

/* Bits of TIFR */
#define TIMER_TIFR_OCF0_BIT 1
#define TIMER_TIFR_TOV0_BIT 0

#endif