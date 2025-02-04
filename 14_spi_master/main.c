#include <avr/io.h>
#include <util/delay.h>

#define LED    PB0
#define BUTTON PD7
#define PRESCALER 3

#define NUM_STATES 4

/* DDRB  - PORT B Data direction register */
/* PORTB - PORT B Data  register */
#define BUTTON PD7

int main() {
	int state=0, counter = 0;
	uint8_t segment_values[16] = { 63, 6, 91, 79, 102, 109, 125, 7, 127, 111, 119, 124, 57, 94, 121, 113 };

	/* Init the IOs for the display */
	DDRB = (1<<PB5) | (1<<PB3) | (1<<PB2) | (1<<PB1);
	PORTB &= (1<<PB1); /*PB1 -> RCLK */

	/* Init SPI interface */
	SPCR = (1<<MSTR) | PRESCALER; /* 3 - we divide the SCLK by 128*/
	SPCR |= (1<<SPE);

	while(1) {
		SPDR = segment_values[counter & 0xf];
		while(!(SPSR & (1<<SPIF)))
		/* Toggle the RCLK */
		PORTB &= ~(1<<PB1); /* Set RCLK */
		_delay_ms(5);
		PORTB &= ~(1<<PB1); /* Reset  RCLK */
		counter++;
		_delay_ms(500);

	}
	return 0;
}