#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define BUTTON    PD2
#define NUM_LEDS  3

uint8_t led[NUM_LEDS] = {PB0, PB1, PB2};
int index = 0;

ISR(INT0_vect) {
	cli();  /* Disable global IRQs */
	_delay_ms(100); /* Debouncing */
	index = (index + 1) % NUM_LEDS;
	sei();
}

/* DDRB  - PORT B Data direction register */
/* PORTB - PORT B Data  register */

int main() {

	/* Init the IOs for the LEDs (1 as output) */
	DDRB = (1<<PB0) | (1<<PB1) | (1<<PB2); 
	
	/* Set PD2 to input (~1) */
	DDRD &= ~(1<<PD2); 

	/* Set internall pull up */
	PORTD |= (1 << BUTTON);

	/* Interrupt setup */
	EICRA = 0x2; /* IRQ trigger falling edge */
	EIMSK = 1;   /* Ebalbe INT0 */
	sei(); 	 	 /*Globally enable IRQs*/

	while(1)
		PORTB ^= (1<<led[index]);  /* TOGGLE LEDS one BY ONE*/

	return 0;
}

