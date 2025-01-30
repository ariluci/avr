/* By default AVR uses *8MHz oscillator 
 * go to https://eleccelerator.com/fusecalc/fusecalc.php?chip=atmega328p&LOCKBIT=FF 
 * select external oscilattor and use the generated command paraneter to load via AVRDUDE
 * example :
 * sudo avrdude -c usbasp -p m328p	-U lfuse:w:0xEF:m	-U hfuse:w:0xD9:m	-U efuse:w:0xFF:m	-U lock:w:0xFF:m
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define LEDS  PB0

int main() {
	volatile long int i;

	/* Init the IOs for the LEDs (1 as output) */
	DDRB  = (1<<PB0); 
	PORTB = 1;

	while(1) {
		PORTB ^= 0x1;
		for(i = 0; i < 20000; i++)
			asm("NOP"); 
	}
	return 0;
}

