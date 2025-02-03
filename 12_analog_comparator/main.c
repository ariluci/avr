#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define LEDS  PB0

ISR(ANALOG_COMP_vect) {
	if(ACSR & (1<<ACO))
		PORTB |= 1;
	else
		PORTB |= ~(1);
12_analog_comparator copy}

int main() {
	volatile long int i;

	/* Init the IOs for the LEDs (1 as output) */
	DDRB  = (1<<PB0); 
	PORTB = 1;

	/* Init the Analog Comparator */
	ACSR = (1<<ACIE);
	ADCSRB = 0;
	sei();

	while(1) {
	}
	return 0;
}

