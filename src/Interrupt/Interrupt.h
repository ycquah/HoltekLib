/*
 * Licensed under the Apache License, Version 2.0.
 * You may not use this file except in compliance with the License.
 * Obtain a copy at http://www.apache.org/licenses/LICENSE-2.0.
 * Distributed on an "AS IS" basis, without warranties or conditions.
 */

/** @file ISR.h
 * @brief Header file for Interrupt Service Routine (ISR) management for Holtek MCUs.
 * This file defines the necessary macros, function prototypes, and interrupt vector addresses
 * for managing interrupts in the system.
 * Author: Mohamad Khosravi  https://github.com/Mohamadkhosravi
 * Date: 2024
 */

#ifndef ISR_H__
#define ISR_H__

#include "BA45F5240.h"  // Include the microcontroller-specific header file

// Macros for enabling/disabling interrupts
#define Enable 1
#define Disable 0

// Global variables for frame and received frame
extern unsigned short frame;               /**< @brief Frame for communication */
extern volatile unsigned short frameResive; /**< @brief Received frame data */

// RX bit for communication
extern char RXbit;

// Macros for interrupt status
#define InterruptEnable       1
#define InterruptDisable      0

// Global interrupt control
#define GLOBAL_INTERRUPT        _emi

// External interrupt settings
#define EXTERNAL_PIN0_ISR      Disable
#define EXTERNAL_PIN1_ISR      Disable
#define USIM_ISR               Disable
#define LVD_ISR                Disable
#define ADC_ISR                Disable
#define EEPROM_ISR             Disable
#define PTM_COMPAIR_P_ISR      Enable
#define PTM_COMPAIR_A_ISR      Enable
#define STM_COMPAIR_P_ISR      Disable
#define STM_COMPAIR_A_ISR      Disable
#define BASE_TIMER0_ISR        Disable
#define BASE_TIMER1_ISR        Disable
#define PLT_COMPAIR0_ISR       Enable
#define PLT_COMPAIR1_ISR       Enable

/** @brief Function to enable specific interrupts.
 * @param interruptAddress The address of the interrupt to be enabled.
 */
void EnableInterrupt(char interruptAddress);

/** @brief Function to disable specific interrupts.
 * @param interruptAddress The address of the interrupt to be disabled.
 */
void DisableInterrupt(char interruptAddress);

// Interrupt Vector Addresses
/** @brief Interrupt vector addresses for various peripherals. */
#define PLT_COMPAIR0_ISR_ADDRESS   0x04 // Priority 0 (High)
#define EXTERNAL_PIN0_ISR_ADDRESS  0x08 // Priority 1
#define EXTERNAL_PIN1_ISR_ADDRESS  0x0C // Priority 2
#define USIM_ISR_ADDRESS           0x10 // Priority 3 Universal Serial Interface
#define LVD_ISR_ADDRESS            0x14 // Priority 4 Low Voltage Detector
#define ADC_ISR_ADDRESS            0x18 // Priority 5 Analog to Digital Converter
#define EEPROM_ISR_ADDRESS         0x1C // Priority 6
#define PTM_COMPAIR_P_ISR_ADDRESS  0x20 // Priority 7
#define PTM_COMPAIR_A_ISR_ADDRESS  0x24 // Priority 8
#define STM_COMPAIR_P_ISR_ADDRESS  0x28 // Priority 9
#define STM_COMPAIR_A_ISR_ADDRESS  0x2C // Priority 10
#define BASE_TIMER0_ISR_ADDRESS    0x30 // Priority 11
#define BASE_TIMER1_ISR_ADDRESS    0x34 // Priority 12
#define PLT_COMPAIR1_ISR_ADDRESS   0x38 // Priority 13 (Low)

/** @brief Function to initialize interrupts. */
void IntrruptInit(void);

/** @brief External Pin 0 Interrupt Service Routine. */
void __attribute__((interrupt(EXTERNAL_PIN0_ISR_ADDRESS))) ExternalPin0ISR(void);

/** @brief External Pin 1 Interrupt Service Routine. */
void __attribute__((interrupt(EXTERNAL_PIN1_ISR_ADDRESS))) ExternalPin1ISR(void);

/** @brief Universal Serial Interface Interrupt Service Routine. */
void __attribute__((interrupt(USIM_ISR_ADDRESS))) UniversalSerialInterfaceISR(void);

/** @brief Low Voltage Detector Interrupt Service Routine. */
void __attribute__((interrupt(LVD_ISR_ADDRESS))) LowVoltageDetectISR(void);

/** @brief EEPROM Interrupt Service Routine. */
void __attribute__((interrupt(EEPROM_ISR_ADDRESS))) EEPROMISR(void);

/** @brief PTM Compare P Interrupt Service Routine. */
void __attribute__((interrupt(PTM_COMPAIR_P_ISR_ADDRESS))) PTMCompairPISR(void);

/** @brief PTM Compare A Interrupt Service Routine. */
void __attribute__((interrupt(PTM_COMPAIR_A_ISR_ADDRESS))) PTMCompairAISR(void);

/** @brief STM Compare P Interrupt Service Routine. */
void __attribute__((interrupt(STM_COMPAIR_P_ISR_ADDRESS))) STMCompairPISR(void);

/** @brief STM Compare A Interrupt Service Routine. */
void __attribute__((interrupt(STM_COMPAIR_A_ISR_ADDRESS))) STMCompairAISR(void);

/** @brief Base Timer 0 Interrupt Service Routine. */
void __attribute__((interrupt(BASE_TIMER0_ISR_ADDRESS))) BaseTimer0ISR(void);

/** @brief Base Timer 1 Interrupt Service Routine. */
void __attribute__((interrupt(BASE_TIMER1_ISR_ADDRESS))) BaseTimer1ISR(void);

/** @brief PLT Compare 1 Interrupt Service Routine. */
void __attribute__((interrupt(PLT_COMPAIR1_ISR_ADDRESS))) PLT1CompairISR(void);

/** @brief PLT Compare 0 Interrupt Service Routine. */
void __attribute__((interrupt(PLT_COMPAIR0_ISR_ADDRESS))) PLT0CompairISR(void);

#endif // ISR_H__
