/*
 * Licensed under the Apache License, Version 2.0.
 * You may not use this file except in compliance with the License.
 * Obtain a copy at http://www.apache.org/licenses/LICENSE-2.0.
 * Distributed on an "AS IS" basis, without warranties or conditions.
 */

/** @file PTM.h
 * @brief Header file for the Periodic Timer Module (PTM) for Holtek MCUs.
 * This file defines the macros and function prototypes for the PTM, which is used
 * for generating timing signals, PWM, and input capture functionalities.
 * Author: Mohamad Khosravi  https://github.com/Mohamadkhosravi
 * Date: 2024
 */

#ifndef PTIMER_H
#define PTIMER_H

#include <Main.h>

/** @brief PTM Counter Clock Selection
 * This section defines the clock sources for the PTM counter.
 */
#define PT_SYS_DIVIDE_4     0
#define PT_SYS              1
#define PT_H_DIVIDE_16      2
#define PT_H_DIVIDE_64      3
#define PT_SUB1             4
#define PT_SUB2             5
#define PT_STCK_RISING      6
#define PT_STCK_FALLING     7
//=========================================================================
#define PTIMER_CLOCK    PT_SYS
//=========================================================================

/** @brief PTM Operating Modes
 * This section defines the operating modes for the PTM.
 */
#define PTM_COMPARE_MATCH_OUTPUT_MODE          0
#define PTM_CAPTURE_INPUT_MODE                 1
#define PTM_PWM_OR_SINGLE_PULSE_OUTPUT_MODE    2
#define PTM_TIMER_COUNTER_MODE                 3
//=========================================================================
#define PTM_MODE     PTM_CAPTURE_INPUT_MODE
//=========================================================================

/** @brief PTM External Pins Function
 * This section defines the functions of external pins for the PTM.
 */
#define PTM_NO_CHANGE       0
#define PTM_OUTPUT_LOW      1
#define PTM_OUTPUT_HIGH     2
#define PTM_TOGGLE_OUTPUT   3
#define PTM_PWM_INACTIVE          0
#define PTM_PWM_ACTIVE            1
#define PTM_PWM_OUTPUT            2
#define PTM_SINGLE_PULSE_OUTPUT   3
//=========================================================================
#define PTM_PIN_FUNCTION   PTM_NO_CHANGE
//=========================================================================

/** @brief PTM Output Mode
 * This section defines the output mode of the PTM.
 */
#define PTM_INITIAL_LOW 0
#define PTM_INITIAL_HIGH 1
#define PTM_ACTIVE_LOW 0
#define PTM_ACTIVE_HIGH 1
//=========================================================================
#define PTM_OUTPUT_MODE  PTM_INITIAL_LOW
//=========================================================================

/** @brief PTM Counter On/Off Control
 * This section defines the control for turning the PTM counter on or off.
 */
#define PTM_COUNTER_OFF     0
#define PTM_COUNTER_ON      1
//=========================================================================
#define PTM_COUNTER         PTM_COUNTER_ON
//=========================================================================

/** @brief PTM Output Polarity
 * This section defines the output polarity of the PTM.
 */
#define PTM_NON_INVERT      0
#define PTM_INVERT          1
//=========================================================================
#define PTM_OUTPUT_POLARITY  PTM_NON_INVERT
//=========================================================================

/** @brief PTM Capture Trigger Source Selection
 * This section defines the trigger sources for capturing input signals.
 */
#define PTM_PTPI_INPUT 0
#define PTM_PTCK_INPUT 1
//=========================================================================
#define PTM_CAPTURE_TRIGGER  PTM_PTPI_INPUT
//=========================================================================

/** @brief PTM Comparator Clear Condition Selection
 * This section defines conditions for clearing the PTM comparator.
 */
#define PTM_COMPARE_MATCH_P 0
#define PTM_COMPARE_MATCH_A 1
//=========================================================================
#define PTM_SELECT_CLEAR_COMPARE_MATCH    PTM_COMPARE_MATCH_P
//=========================================================================

/** @brief Select PTM Counter clear condition in capture input mode
 * This section defines clear conditions when in capture input mode.
 */
#define PTM_COMPARE_P_MATCH 0
#define PTM_COMPARE_P_MATCH_OR_PTCK_PTPI_RISING_EDGE 1
#define PTM_COMPARE_P_MATCH_OR_PTCK_PTPI_FALING_EDGE 2
#define PTM_COMPARE_P_MATCH_OR_PTCK_PTPI_DUAL_EDGE   3
//=========================================================================
#define PTM_SELECT_CLEAR_CONDITION_IN_CAPTURE_INPUT  PTM_COMPARE_P_MATCH_OR_PTCK_PTPI_RISING_EDGE
//=========================================================================

/** @brief PTM counter value latch edge flag
 * This section defines the edge flag for latching counter values.
 */
#define FALLING_EDGE_TRIAGE_COUNTER_LATCH 0
#define RISING_EDGE_TRIAGE_COUNTER_LATCH  1
//=========================================================================
#define COUNTER_VALUE_LATCH_EDGE  FALLING_EDGE_TRIAGE_COUNTER_LATCH
//=========================================================================

/** @brief PTM CCRA Low & High Byte Mask
 * This section defines masks for low and high bytes of the PTM CCRA.
 */
#define PTM_CCRA_LOW_BYTE_MASK 0x01  // Mask for PTM CCRA low byte MAX=0xFF
#define PTM_CCRA_HIGH_BYTE_MASK 0 // Mask for PTM CCRA high byte MAX=0x3
//=========================================================================

// PTM CCRB Low & High Byte Mask
//=========================================================================
#define PTM_CCRB_LOW_BYTE_MASK 0x01  // Mask for PTM CCRB low byte MAX=0xFF
#define PTM_CCRB_HIGH_BYTE_MASK 0// Mask for PTM CCRB high byte MAX=0x3
//=========================================================================

// PTM CCRP Low & High Byte Mask
//=========================================================================
#define PTM_CCRP_LOW_BYTE_MASK 0x01  // Mask for PTM CCRP low byte  MIN =1 MAX=0xFF
#define PTM_CCRP_HIGH_BYTE_MASK 1 // Mask for PTM CCRP high byte MIN =1 MAX=0x3
//=========================================================================

/** @brief Function declarations
 *
 * The following functions are declared for initializing and using the PTM.
 */
void PTimerInit(void);  /**< @brief Initializes the PTM */
void PWMSeter(char status); /**< @brief Sets the PWM status (active or inactive) */
unsigned int readPTimer(void);   /**< @brief Reads the current value of the PTM timer */

#endif  // End of PTIMER_H
