/**********************************************************************************/
/*************************** Name : Omar Tarek ************************************/
/*************************** Date : 6/7/2024   ************************************/
/*************************** SWC : UART        ************************************/
/*************************** Version : 1.0     ************************************/
/**********************************************************************************/
#ifndef UART_CONFIGURATION_H
#define UART_CONFIGURATION_H

#define CPU_FREQUENCY 8000000

/* Options: 1- ASYNCHRONOUS 
            2- SYNCHRONOUS */
#define USART_MODE ASYNCHRONOUS

/* Options: 1- ENABLE 
            2- DISABLE */
#define MPCM_MODE DISABLE
#define U2X_MODE DISABLE

/* Options: 1- FIVE_BITS 
            2- SIX_BITS
            3- SEVEN_BITS
            4- EIGHT_BITS
            5- NINE_BITS */
#define CHARCTER_SIZE EIGHT_BITS

/* Options: 1- ENABLE_EVEN
            2- ENABLE_LOW
            3- DISABLE */
#define PARITY_BIT DISABLE

/* Options: 1- ONE_BIT
            2- TWO_BITS */
#define STOP_BIT TWO_BITS
#endif