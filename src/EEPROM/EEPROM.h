
#ifndef EEPROM
#define  EEPROM
#include "BA45F5240.h"
	
	#define EEPROM_ADDRESS_REG  _eea// EEPROM address register
	#define EEPROM_DATA_REG	    _eed//EEPROM data register
	#define EEPROM_CONTROL_REG _iar1//EEPROM control register
	
	#define MEMORY_SECTOR _mp1h//EEPROM control register
	#define MEMORY_POINTER _mp1l//EEPROM control register
	
	
	
	
	
	
	
	void writeToEEPROM(char address, char data);
	void readFromEEPROM(char address, char* readData) ;
	
#endif