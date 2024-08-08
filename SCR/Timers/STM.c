/*
 * Licensed under the Apache License, Version 2.0.
 * You may not use this file except in compliance with the License.
 * Obtain a copy at http://www.apache.org/licenses/LICENSE-2.0.
 * Distributed on an "AS IS" basis, without warranties or conditions.
 */

/** @file STM.c
 * @brief Implementation of the STM (Standard Timer Module) for Holtek MCUs.
 * This file provides functions to initialize the STM and read the timer value.
 * Author: Mohamad Khosravi  https://github.com/Mohamadkhosravi
 * Date: 2024
 */

#include <STM.h>

/** @brief Initializes the Standard Timer Module (STM).
 *
 * This function configures the STM counter, clock, mode, and other parameters
 * according to the specified settings.
 *
 * @note Ensure to define the required macros (STIMER_CLOCK, STM_PERIOD, etc.)
 *       before calling this function.
 *
 * @param void
 * @return void
 */
void STimerInit(void) {
    // STPAU: STM Counter Pause Control
    // 0: Run, 1: Pause
    _stpau = 0; // Set STM counter to run mode

    // Select STM Counter Clock
    _stck0 = STIMER_CLOCK & 1;
    _stck1 = (STIMER_CLOCK >> 1) & 1;
    _stck2 = (STIMER_CLOCK >> 2) & 1;

    // STON: STM Counter On/Off Control
    _ston = STM_COUNTER; // Turn on STM counter

    // Set STM Comparator P Match Period
    _strp0 = STM_PERIOD & 1;
    _strp1 = (STM_PERIOD >> 1) & 1;
    _strp2 = (STM_PERIOD >> 2) & 1;

    // Set STM Operating Mode
    _stm0 = STM_MODE & 1;
    _stm1 = (STM_MODE >> 1) & 1;

    // Set STM Pin Function
    _stio0 = STM_PIN_FUNCTION & 1;
    _stio1 = (STM_PIN_FUNCTION >> 1) & 1;

    // Output Control
    _stoc = STM_OUTPUT_MODE;
    
    // Set STM Output Polarity
    _stpol = STM_OUTPUT_POLARITY;

    // Set STM PWM Duty/Period Control
    _stdpx = STM_PWM_DUTY;

    // Set STM Compare Clear Condition
    _stcclr = STM_SELECT_CLEAR_COMPARE_MATCH;

    // Set STM Comparator CCRA Low Byte
    _stmal = STM_CCRA_LOW_BYTE_MASK;

    // Set STM Comparator CCRA High Byte
    _stmah = STM_CCRA_HIGH_BYTE_MASK & 3;
}

/** @brief Reads the value of the Standard Timer Module (STM).
 *
 * This function reads the current value of the STM timer.
 *
 * @return The current timer value as an unsigned integer.
 */
unsigned int readSTimer(void)
{
    // Read STM Timer Value
    return ((_stmdl) | (_stmdh << 8));
}
