
#include"EEPROM.h"







void writeToEEPROM(char address, char data) {
	
	// Set the EEPROM address register
	EEPROM_ADDRESS_REG =address;
	// Set the data to write
	EEPROM_DATA_REG =  data;
	// Setup memory pointer MP1L
	MEMORY_POINTER=0x40;
	// Setup memory SECTOR MP1H
	MEMORY_SECTOR=0x01;
	// Enable write operations (set WREN bit)
	EEPROM_CONTROL_REG |= (1 << 3);
	// Start Write Cycle (set WR bit)
	EEPROM_CONTROL_REG |= (1 << 2);
	// Poll for write cycle end
	while ((EEPROM_CONTROL_REG & (1 << 2)));
	// set sector to 0
	MEMORY_SECTOR=0x0;	
	

}


void readFromEEPROM(char address, char* readData) {
	
	// Set the EEPROM address register
	EEPROM_ADDRESS_REG = address;
	// Setup memory pointer MP1L
	MEMORY_POINTER=0x40;
	// Setup memory SECTOR MP1H
	MEMORY_SECTOR=0x01;
	// Enable read operations (set RDEN bit)
	EEPROM_CONTROL_REG|= (1 << 1);
	// Start Read Cycle (set RD bit)
	EEPROM_CONTROL_REG|= (1 << 0);
	// Poll for read cycle end
	while( ((EEPROM_CONTROL_REG & (1 << 0))));
	// Disable EEPROM read
	EEPROM_CONTROL_REG=0;
	// set sector to 0
	MEMORY_SECTOR=0;
	// Read data from EEPROM and store it in readData
	*readData =EEPROM_DATA_REG;
	

}