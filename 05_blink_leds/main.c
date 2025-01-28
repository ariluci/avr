#include <avr/io.h>
#include <util/delay.h>

#define RED    PB0
#define YELLOW PB1
#define GREEN  PB2

#define NUM_STATES 4

/* DDRB  - PORT B Data direction register */
/* PORTB - PORT B Data  register */

int main() {
	int state = 0;
	
	/* Init the IOs for the LEDs (1 as output) */
	DDRB = (1<<PB0) | (1<<PB1) | (1<<PB2); 

	while(1){
		/* Clear all outputs */
		PORTB &= ~((1<<RED) | (1 << YELLOW) | (1<<GREEN));
		switch(state){
			case 0:
				PORTB |= (1<<GREEN);
				_delay_ms(2000);
				state = (state + 1) % NUM_STATES; 
				break;
			case 1:
				PORTB |= (1<<YELLOW);
				_delay_ms(1000);
				state = (state + 1) % NUM_STATES; 
				break;
			case 2:
				PORTB |= (1<<RED);
				_delay_ms(2000);
				state = (state + 1) % NUM_STATES; 
				break;
			case 3:
				PORTB |= (1<<RED) | (1<<YELLOW);
				_delay_ms(1000);
				state = (state + 1) % NUM_STATES; 
				break;
			default:
				break;
		}

	}
	return 0;
}