/*
 * GccApplication1.c
 *
 * Created: 1/31/2025 12:18:49 PM
 * Author : acooper1171
 */ 

#define F_CPU 16000000UL // 16MHz clock from the debug processor
#include <avr/io.h>
#include <util/delay.h>

void AsciiToMorse(const char);

void On() {
	PORTB |= (1<<PORTB5); //Set port bit B5 to 1 to turn on the LED
}

void Off() {
	PORTB &= ~(1<<PORTB5); //Clear port bit B5 to 0 to turn off the LED
}

void Dot() {
	On();
	_delay_ms(200);
	Off();
	_delay_ms(600);
}

void Dash() {
	On();
	_delay_ms(600);
	Off();
	_delay_ms(600);
}

void Space() {
	_delay_ms(1400);
}

void Output(const char* str, uint8_t size) {
	for (uint8_t i = 0; i < size; i++) {
		AsciiToMorse(str[i]);
	}	
}

int main(void) {
	/* Replace with your application code */
	DDRB |= (1<<DDB5); //0x20 (hex) // Set port bit B5 in data direction register to 1: an OUTput
	while(1) {
		Output("ABC123", 6);
	}
}

void AsciiToMorse(const char ascii) {
	switch (ascii) {
		case 'A':
		case 'a':
			Dot();Dash();
			break;
		case 'B':
		case 'b':
			Dash();Dot();Dot();Dot();
			break;
		case 'C':
		case 'c':
			Dash();Dot();Dash();Dot();
			break;
		case 'D':
		case 'd':
			Dash();Dot();Dot();
			break;
		case 'E':
		case 'e':
			Dot();
			break;
		case 'F':
		case 'f':
			Dot();Dot();Dash();Dot();
			break;
		case 'G':
		case 'g':
			Dash();Dash();Dot();
			break;
		case 'H':
		case 'h':
			Dot();Dot();Dot();Dot();
			break;
		case 'I':
		case 'i':
			Dot();Dot();
			break;
		case 'J':
		case 'j':
			Dot();Dash();Dash();Dash();
			break;
		case 'K':
		case 'k':
			Dash();Dot();Dash();
			break;
		case 'L':
		case 'l':
			Dot();Dash();Dot();Dot();
			break;
		case 'M':
		case 'm':
			Dash();Dash();
			break;
		case 'N':
		case 'n':
			Dash();Dot();
			break;
		case 'O':
		case 'o':
			Dash();Dash();Dash();
			break;
		case 'P':
		case 'p':
			Dot();Dash();Dash();Dot();
			break;
		case 'Q':
		case 'q':
			Dash();Dash();Dot();Dash();
			break;
		case 'R':
		case 'r':
			Dot();Dash();Dot();
			break;
		case 'S':
		case 's':
			Dot();Dot();Dot();
			break;
		case 'T':
		case 't':
			Dash();
			break;
		case 'U':
		case 'u':
			Dot();Dot();Dash();
			break;
		case 'V':
		case 'v':
			Dot();Dot();Dot();Dash();
			break;
		case 'W':
		case 'w':
			Dot();Dash();Dash();
			break;
		case 'X':
		case 'x':
			Dash();Dot();Dot();Dash();
			break;
		case 'Y':
		case 'y':
			Dash();Dot();Dash();Dash();
			break;
		case 'Z':
		case 'z':
			Dash();Dash();Dot();Dot();
			break;
		case '1':
			Dot();Dash();Dash();Dash();Dash();
			break;
		case '2':
			Dot();Dot();Dash();Dash();Dash();
			break;
		case '3':
			Dot();Dot();Dot();Dash();Dash();
			break;
		case '4':
			Dot();Dot();Dot();Dot();Dash();
			break;
		case '5':
			Dot();Dot();Dot();Dot();Dot();
			break;
		case '6':
			Dash();Dot();Dot();Dot();Dot();
			break;
		case '7':
			Dash();Dash();Dot();Dot();Dot();
			break;
		case '8':
			Dash();Dash();Dash();Dot();Dot();
			break;
		case '9':
			Dash();Dash();Dash();Dash();Dot();
			break;
		case '0':
			Dash();Dash();Dash();Dash();Dash();
			break;
	}
}
