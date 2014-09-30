#include <avr/io.h>
#include <avr/interrupt.h>
#include "ExtInt.h"


void set_extint_register() {
	INTERRUPT_INDICATOR_DIR; //Set direction for indicator LEDS as OUTPUT on PORTB (PB0)
	INTERRUPT_INDICATOR_PORT=0x00;//initial state of interrupt indicator LED is (OFF)

	EXTERNAL_INTERRUPT_DIR|=(0<<INT_BIT); // Initialize the switch on External Interrupt Pin as Input
	EXTERNAL_INTERRUPT_PORT|=(1<<INT_BIT); //Enable (Pull-UP resistor) "To PREVENT input floating" on External Interrupt Pin
	EIMSK|=(1<<INT_BIT);//Enable External Interrupt Mask Register bit (INT0-INT7)
	EICRA|=(0<<SENSE_CONTROL);//Enable Interrupt Control Register bit (ISC00) "ISC interrupt sense control "
	//ISCn0 - ISCn1 (n=0,1,2,3 "Asynchronous")
	//(n=4,5,6,7 "Synchronous" )
	sei();
} 
