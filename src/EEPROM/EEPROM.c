/*
 * Licensed under the Apache License, Version 2.0.
 * You may not use this file except in compliance with the License.
 * Obtain a copy at http://www.apache.org/licenses/LICENSE-2.0.
 * Distributed on an "AS IS" basis, without warranties or conditions.
 */

/** 
 * @file EEPROM.c
 * @brief Implementation of EEPROM read/write operations.
 * 
 * This file contains the implementation of functions to read from and write to EEPROM.
 * These functions use specific registers to interact with EEPROM memory on the BA45F5240 microcontroller.
 * 
 * Author: Mohamad Khosravi  https://github.com/Mohamadkhosravi
 * Date: 2024
 */

#include "EEPROM.h"

/**
 * @brief Write data to a specific address in the EEPROM.
 * 
 * This function writes a single byte of data to the specified address in the EEPROM.
 * It sets up the necessary registers and starts the write cycle.
 * 
 * @param address The address in the EEPROM where the data will be written.
 * @param data The data byte to be written to the EEPROM.
 */
void writeToEEPROM(char address, char data) {
    // Set the EEPROM address register
    EEPROM_ADDRESS_REG = address;
    
    // Set the data to be written
    EEPROM_DATA_REG = data;
    
    // Set up the memory pointer MP1L
    MEMORY_POINTER = 0x40;
    
    // Set up the memory sector MP1H
    MEMORY_SECTOR = 0x01;
    
    // Enable write operations (set WREN bit in EEPROM control register)
    EEPROM_CONTROL_REG |= (1 << 3);
    
    // Start the write cycle (set WR bit in EEPROM control register)
    EEPROM_CONTROL_REG |= (1 << 2);
    
    // Poll for the end of the write cycle (wait until WR bit is cleared)
    while (EEPROM_CONTROL_REG & (1 << 2));
    
    // Reset the memory sector after the write is complete
    MEMORY_SECTOR = 0x00;  
}

/**
 * @brief Read data from a specific address in the EEPROM.
 * 
 * This function reads a single byte of data from the specified address in the EEPROM.
 * It sets up the necessary registers and starts the read cycle.
 * 
 * @param address The address in the EEPROM from which the data will be read.
 * @param readData Pointer to a variable where the read data will be stored.
 */
void readFromEEPROM(char address, char* readData) {
    // Set the EEPROM address register
    EEPROM_ADDRESS_REG = address;
    
    // Set up the memory pointer MP1L
    MEMORY_POINTER = 0x40;
    
    // Set up the memory sector MP1H
    MEMORY_SECTOR = 0x01;
    
    // Enable read operations (set RDEN bit in EEPROM control register)
    EEPROM_CONTROL_REG |= (1 << 1);
    
    // Start the read cycle (set RD bit in EEPROM control register)
    EEPROM_CONTROL_REG |= (1 << 0);
    
    // Poll for the end of the read cycle (wait until RD bit is cleared)
    while (EEPROM_CONTROL_REG & (1 << 0));
    
    // Disable EEPROM read operations by clearing the control register
    EEPROM_CONTROL_REG = 0;
    
    // Reset the memory sector after the read is complete
    MEMORY_SECTOR = 0x00;
    
    // Store the read data in the provided variable
    *readData = EEPROM_DATA_REG;
}
