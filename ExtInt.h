#define EXTERNAL_INTERRUPT_PORT PORTD //PORTD for (INT0-INT3), PORTE for (INT4-INT7)
#define EXTERNAL_INTERRUPT_DIR DDRD //set direction of External interrupt "DDRD for (INT0-INT3) ,DDRE for (INT4-INT7)

#define INTERRUPT_INDICATOR_PORT PORTB //TWO LEDS to indicate an External Interrupt on PORTB (PB0)
#define INTERRUPT_INDICATOR_DIR (DDRB=0b00000001) //Set direction for indicator LEDS as OUTPUT on PORTB (PB0)

#define INT_BIT INT0 //INT0-INT7
#define SENSE_CONTROL ISC00 //ISCn0 - ISCn1 (n=0,1,2,3 "Asynchronous")
//(n=4,5,6,7 "Synchronous" )

void set_extint_register();


 
