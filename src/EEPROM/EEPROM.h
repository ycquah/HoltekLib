/*
 * Licensed under the Apache License, Version 2.0.
 * You may not use this file except in compliance with the License.
 * Obtain a copy at http://www.apache.org/licenses/LICENSE-2.0.
 * Distributed on an "AS IS" basis, without warranties or conditions.
 */

/** 
 * @file EEPROM.h
 * @brief Header file for EEPROM read/write operations.
 * 
 * This file contains macros and function prototypes for interacting with the EEPROM.
 * It provides methods to read from and write to specific addresses in the EEPROM.
 * 
 * Author: Mohamad Khosravi  https://github.com/Mohamadkhosravi
 * Date: 2024
 */

#ifndef EEPROM_H
#define EEPROM_H

#include "BA45F5240.h"

/** @brief EEPROM address register. */
#define EEPROM_ADDRESS_REG  _eea

/** @brief EEPROM data register. */
#define EEPROM_DATA_REG     _eed

/** @brief EEPROM control register. */
#define EEPROM_CONTROL_REG  _iar1

/** @brief EEPROM memory sector register (high byte). */
#define MEMORY_SECTOR       _mp1h

/** @brief EEPROM memory pointer register (low byte). */
#define MEMORY_POINTER      _mp1l

/**
 * @brief Write data to a specific address in the EEPROM.
 * 
 * This function writes a single byte of data to the specified address in the EEPROM.
 * 
 * @param address The address in the EEPROM where the data will be written.
 * @param data The data byte to be written to the EEPROM.
 */
void writeToEEPROM(char address, char data);

/**
 * @brief Read data from a specific address in the EEPROM.
 * 
 * This function reads a single byte of data from the specified address in the EEPROM.
 * 
 * @param address The address in the EEPROM from which the data will be read.
 * @param readData Pointer to a variable where the read data will be stored.
 */
void readFromEEPROM(char address, char* readData);

#endif /* EEPROM_H */
