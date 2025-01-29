#include <avr/io.h>
#include <util/delay.h>

#define LED    PB0
#define BUTTON PD7


#define NUM_STATES 4

/* DDRB  - PORT B Data direction register */
/* PORTB - PORT B Data  register */

int main() {
	int state = 0;
	
	/* Init the IOs for the LEDs (1 as output) */
	DDRB = (1<<PB0); 
	/* Set PD7 to input (~1) */
	DDRD &= ~(1<<PD7); 

	while(1)
	{
		if ((PIND & (1<<BUTTON)) > 0) 
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