/*
 * Licensed under the Apache License, Version 2.0.
 * You may not use this file except in compliance with the License.
 * Obtain a copy at http://www.apache.org/licenses/LICENSE-2.0.
 * Distributed on an "AS IS" basis, without warranties or conditions.
 */

/** @file UART.c
 * @brief Implementation of UART (Universal Asynchronous Receiver-Transmitter) functions.
 * This file provides the definitions for initializing UART, transmitting and receiving data,
 * and enabling/disabling UART interrupts.
 * Author: Mohamad Khosravi  https://github.com/Mohamadkhosravi
 * Date: 2024
 */

#include "UART.h"
#include <BA45F5240.h>

/** @brief Initializes the UART with a specified baud rate.
 * @param baudrate The baud rate for UART communication.
 *
 * This function configures the UART pins, sets the UART mode, and calculates the
 * baud rate register values based on the provided baud rate.
 */
void UART_Init(unsigned int baudrate) {
    // Set PA6 as UART RX (input)
    _pac6 = 1;
    _pas13 = 0;
    _pas14 = 1;
    _pas15 = 1;
    _papu6 = 1;

    // Set PB3 as UART RX (input)
    _pbc3 = 1;
    // Pin share RX
    _pbs06 = 0;
    _pbs07 = 1;

    // Set PA3 as UART TX (output)
    _pas06 = 0;
    _pas07 = 0;
    _pbs02 = 0;
    _pbs03 = 1;

    // Enable UART, TX, and RX
    _uren = 1;
    _utxen = 1;
    _urxen = 1;

    // UMD: UART mode selection bit
    // 0: SPI or I2C mode
    // 1: UART mode
    _umd = 1;
    _ubrgh = SPEED_BAUDRATE;
    unsigned int ubrr = (F_CPU / (CONSTANT_NUMBER * baudrate)) - 1.0;
    _ubrg = ubrr & 0xFF;
    
    // Enable UART by setting UREN bit in UUCR1 register
    _uren = 1; // Enable UART (UREN)
    _ubno = DATA_TRANSFER;
    _upen = PARITY;
    _uprt = TYPE_OF_PARITY;
    _ustops = STOP_BIT;
    _utxen = TRANSMITTER;
    _urxen = RECEIVER;
}

/** @brief Transmits a single character via UART.
 * @param data The character to be transmitted.
 *
 * This function waits until the transmit buffer is empty and then sends the data
 * through the UART.
 */
void UART_Transmit(char data) {
    // Wait for empty transmit buffer
    while (!(_uusr & (1 << 1))); // Wait until UTXIF is set
    _utxr_rxr = data; // Put data into buffer, sends the data
}

/** @brief Receives a single character via UART.
 * @return The received character, or an error code in case of an error.
 *
 * This function waits until data is received and checks for errors such as
 * parity, overrun, or framing errors before returning the received data.
 */
int UART_Receive(void) {
    // Wait for data to be received
    while (!(_uusr & (1 << 0))); // Wait until URXIF is set

    // Check for parity error
    if (_uperr) {
        _uperr = 0; // Clear parity error flag
        return UART_PARITY_ERROR;
    }

    // Check for overrun error
    if (_uoerr) {
        _uoerr = 0; // Clear overrun error flag
        return UART_OVERRUN_ERROR;
    }

    // Check for framing error
    if (_uferr) {
        _uferr = 0; // Clear framing error flag
        return UART_FRAMING_ERROR;
    }

    // Get and return received data from buffer
    return _utxr_rxr;
}

/** @brief Enables UART interrupts for receiving and transmitting.
 *
 * This function enables the receiver interrupt and the transmitter interrupts.
 */
void UART_EnableInterrupts(void) {
    // Enable receiver interrupt
    _uucr2 |= _urie;
    // Enable transmitter interrupt
    _uucr2 |= (_utiie | _uteie);
}

/** @brief Disables all UART interrupts.
 *
 * This function disables all UART interrupts, including receiver and transmitter interrupts.
 */
void UART_DisableInterrupts(void) {
    // Disable all UART interrupts
    _uucr2 &= ~(_urie | _utiie | _uteie);
}
