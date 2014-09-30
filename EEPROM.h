/*
 * EEPROM.h
 *
 * Created: 9/29/2014 11:30:15 PM
 *  Author: Islam Negm
 */ 

/* This function is used to read a byte from EEPROM */
unsigned char EEPROM_read(unsigned int adress);
/* This function is used to write a byte to EEPROM */
void EEPROM_write(unsigned int adress, unsigned char data);
