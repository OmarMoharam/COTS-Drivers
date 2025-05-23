# COTS Drivers for Embedded Systems

## Overview
This repository contains a structured collection of COTS (Component Off The Shelf) drivers for embedded systems development.  
It follows a clean layered architecture approach (MCAL, HAL, APP, and LIB).

## Repository Structure

### 📂 MCAL (Microcontroller Abstraction Layer)
- **DIO** — Digital Input/Output Control
- **EXTI** — External Interrupts
- **GI** — Global Interrupt Enable/Disable
- **ADC** — Analog to Digital Converter
- **TIMERS** — Timer Drivers (Timer0, Timer1, Timer2)
- **WDT** — Watchdog Timer
- **UART** — Universal Asynchronous Receiver Transmitter
- **TWI** — Two-Wire Interface (I2C)
- **SPI** — Serial Peripheral Interface

### 📂 HAL (Hardware Abstraction Layer)
- **LCD** — Liquid Crystal Display Control
- **KPD** — Keypad Interface
- **Stepper Motor** — Stepper Motor Control
- **Servo** — Servo Motor Control
- **EEPROM** — External EEPROM Communication

### 📂 APP (Application Layer)
- Application examples showcasing usage of the drivers:
  - Stepper Motor App
  - EXTI App
  - ADC App
  - Timers App
  - ICU App

### 📂 LIB (Common Libraries)
- **BIT_MATH.h** — Common macros for bit manipulation
- **STD_TYPES.h** — Standard data types

## License
This project is licensed under the MIT License.

## Author
Omar Moharam  
📧 omarmoharam193@gmail.com  
🔗 [GitHub Profile](https://github.com/OmarMoharam)
