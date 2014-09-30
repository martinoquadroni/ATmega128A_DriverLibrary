/*
 * EEPROM.c
 *
 * Created: 9/29/2014 11:30:15 PM
 *  Author: Islam Negm
 */ 

#include "EEPROM.h"

/* This function is used to read a byte from EEPROM */
unsigned char EEPROM_read(unsigned int adress)
{
	// Wait until EEWE is cleared this means that the any write operation has ended
	// masking the EECR register with 1 at EEWE bit so if (1) wait :)
	while (EECR &(1<<EEWE)) ;
	
	// Set the Adressing Register to tha adress
	// EEAR = adress; 
	EEARH = (adress>>8); /* Set up address and Data Registers */
        EEARL = adress;
        
        //: asalaheldin : before returning you should set the Read Enable bit 
        EECR |= (1<<EERE);
        
	// Returning Value of DATA REGISTER
	return EEDR;
}

void EEPROM_write(unsigned int adress, unsigned char data)
{
	// Wait unil EEWE is cleared
	while(EECR &(1<<EEWE));
	// Wait for any process on writing on flash SPM : Store Program Memory , CSR Control and Status Register. SPMEN: Store Program Memory Enable
	while(SPMCSR &(1<<SPMEN));
	
	// Writing adress	
	// EEAR = adress;	// asalaheldin: we should assign each 8-bit of the address to EEARH, EEARL
	EEARH = (adress>>8); /* Set up address and Data Registers */
        EEARL = adress;
	// Writing data
	EEDR = data;
	
	cli();			// asalaheldin : datasheet recommends that we disable the interrupts while writing EEPROM
	// Set 1 to the Master Write Enable Bit	
	EECR |= (1<<EEMWE);
	// Set 1 to Write Enable Bit , to complete the operation 
	EECR |= (1<<EEWE);
	sei();
}

