#include <avr/io.h>
#include <util/delay.h>

#define LED    PB0
#define BUTTON PD7


#define NUM_STATES 4

/* DDRB  - PORT B Data direction register */
/* PORTB - PORT B Data  register */

int main() {
	int state = 0, counter = 0;
	
	/* Init the IOs (PB0-PB7 as output) */
	DDRB = 0x7f; //PB0-PB7 to ou 
	/* Set PD7 to input (~1) */
	DDRD &= ~(1<<PD7); 
	/* Set initial pull up */
	PORTD |= (1 << BUTTON);
	while(1)
	{
		if ((PIND & (1<<BUTTON)) == 0) 
		{
			_delay_ms(50); /* Debouncing */
			if(state == 0) {
				PORTB ^= (1<<LED);
				state = 1;
			}
			else {
				state = 0;
			}
		}
	}
	return 0;
}