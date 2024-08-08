/*
 * Licensed under the Apache License, Version 2.0.
 * You may not use this file except in compliance with the License.
 * Obtain a copy at http://www.apache.org/licenses/LICENSE-2.0.
 * Distributed on an "AS IS" basis, without warranties or conditions.
 */

/** @file BTM.c
 * @brief Implementation of Time Base 0 and Time Base 1 timers initialization.
 * This file provides the definition for initializing the Time Base timers, configuring
 * their clock source, enabling or disabling the timers, setting time-out periods,
 * and enabling global interrupts.
 * Author: Mohamad Khosravi  https://github.com/Mohamadkhosravi
 * Date: 2024
 */

#include "BTM.h"

/** @brief Initializes the Time Base 0 & 1 timers.
 *
 * This function configures the prescaler clock source for the timers, enables or 
 * disables the Time Base 0 and Time Base 1 timers based on pre-defined macros,
 * sets their time-out periods, and enables global interrupts to allow the timers 
 * to trigger interrupt service routines.
 *
 * @note This function should be called before using the Time Base timers to ensure
 *       proper configuration and operation.
 *
 * @param void
 * @return void
 */
void TimerBaseInit(void)
{
    // Set the prescaler clock source for the base timers
    _pscr = PRESCALER_CLOCK_SOURCE_BASE_TIMER;

    // Enable or disable Time Base 0 and 1 based on the definitions in the header file
    _tb0on = TIME_BASE0;
    _tb1on = TIME_BASE1;

    // Set the time-out period for Time Base 0 and 1
    _tb0c |= TIM_BASE0_PERIOD;
    _tb1c |= TIM_BASE1_PERIOD;

    // Enable global interrupts to allow the timers to trigger interrupt service routines
    InterruptEnable;
}
