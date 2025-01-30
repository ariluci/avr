#include <avr/io.h>
#include <util/delay.h>

#define LED1    PB0
#define LED2    PB1
#define LED3    PB2

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

	uint8_t a[3];
	a[0] = PB0;
	a[1] = PB1;
	a[2] = PB2;
	int counter=0;
	while(1)
	{
		if ((PIND & (1<<BUTTON)) > 0) 
		{	
			_delay_ms(50); /* Debouncing */
			if(state == 0) {
				PORTB ^= (1<<a[counter]);
				counter++;
				counter %= 3;
				state = 1;
			}
			else {
				state = 0;
			}
		}
	}
	return 0;
}

