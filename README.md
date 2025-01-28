Projects for AVR Atmega328p

/***To install libraries:
 * avr-gcc: a compiler for the AVR 8-bit architecture
 * avr-libc: precompiled libraries and header files for programming
 * avrdude: tool to flash the program to target
 */

sudo apt install gcc-avr avr-libc avrdude

/* To flash to uc */
make 
sudo avrdude -c usbasp -p m328p -U flash:w:hello.hex

(!!!see picture for connections from uc to usb programmer)
