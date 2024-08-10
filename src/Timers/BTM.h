/*
 * Licensed under the Apache License, Version 2.0.
 * You may not use this file except in compliance with the License.
 * Obtain a copy at http://www.apache.org/licenses/LICENSE-2.0.
 * Distributed on an "AS IS" basis, without warranties or conditions.
 */

/** @file BTM.h
 * @brief Header file for Time Base 0 & 1 control and configuration for Holtek MCUs
 * Provides macros for enabling/disabling timers, setting interrupt flags,
 * selecting clock sources, and configuring time-out periods.
 * Author: Mohamad Khosravi  https://github.com/Mohamadkhosravi
 * Date: 2024
 */

#ifndef BTM_H
#define BTM_H

#include "BA45F5240.h"  // Include the microcontroller-specific header file

// Macros for enabling and disabling features
#define Enable  1
#define Disable 0

// Time Base Enable Configuration
#define TIME_BASE0  Enable
#define TIME_BASE1  Enable

// Timer Base Interrupts Status and Control
#define InterruptEnable          _emi = Enable   // Macro to enable global interrupts
#define InterruptDisable         _emi = Disable  // Macro to disable global interrupts
#define TIME_BASE0_INTERRUPT_FLAG _tb0f           // Interrupt flag for Time Base 0
#define TIME_BASE1_INTERRUPT_FLAG _tb1f           // Interrupt flag for Time Base 1

// Prescaler Clock Source Selection
#define TB_FSYS           0 // fSYS
#define TB_FSYS_DIVIDE_4  1 // fSYS/4
#define TB_FSUB           2 // fSUB

#define PRESCALER_CLOCK_SOURCE_BASE_TIMER   TB_FSUB  // Define the clock source for the base timers

// Time Base n Time-out Period Selection
enum
{
    _256_DIVIDE_PSC ,
    _512_DIVIDE_PSC ,
    _1024_DIVIDE_PSC,
    _2048_DIVIDE_PSC,
    _4096_DIVIDE_PSC,
    _8192_DIVIDE_PSC,
    _16384_DIVIDE_PSC ,
    _32768_DIVIDE_PSC,
    Default = 0,  // Default setting
};

// Define the time-out period for Time Base 0 and 1
#define TIM_BASE0_PERIOD   Default
#define TIM_BASE1_PERIOD   Default

/** @brief Initializes Time Base 0 & 1 timers.
 *
 * This function configures the prescaler clock source, enables/disables the timers,
 * sets the time-out periods, and enables global interrupts.
 *
 * @note This function should be called before using the Time Base timers to ensure
 *       proper configuration and operation.
 *
 * @param void
 * @return void
 */
void TimerBaseInit(void);

#endif // BTM_H
