/*
 * BotonesdeAccion.c
 *
 * Created: 9/9/2026 16:02:56
 * Author : Cristian Juarez
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

// --- UART ---
void UART_init(unsigned int ubrr) {
	UBRR0H = (unsigned char)(ubrr >> 8);
	UBRR0L = (unsigned char)ubrr;
	UCSR0B = (1 << TXEN0) | (1 << RXEN0); // habilita TX y RX
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8 bits, sin paridad, 1 stop
}

void UART_transmit(char data) {
	while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}

// --- UART recepción ---
char UART_receive(void) {
	while (!(UCSR0A & (1 << RXC0))); // espera a que llegue un dato
	return UDR0;                     // devuelve el byte recibido
}

// --- Botones ---
void Buttons_init(void) {
	DDRD &= ~((1 << PD2) | (1 << PD3) | (1 << PD4) | (1 << PD5) | (1 << PD6) | (1 << PD7));
	PORTD |= (1 << PD2) | (1 << PD3) | (1 << PD4) | (1 << PD5) | (1 << PD6) | (1 << PD7);
}

int main(void) {
	UART_init(103); // 9600 baudios con F_CPU=16MHz
	Buttons_init();

	// --- Prueba fija de comunicación ---
	UART_transmit('H'); // puedes mandar un carácter de prueba
	UART_transmit('\n');

	uint8_t prevUp = 1, prevDown = 1, prevLeft = 1, prevRight = 1, prevA = 1, prevB = 1;

	while (1) {
		// --- Recepción desde STM32 (opcional eco) ---
		if (UCSR0A & (1 << RXC0)) {
			char c = UART_receive();
			UART_transmit(c); // reenvía lo que llega
		}

		// --- Botones del Nano ---
		uint8_t currentUp    = (PIND & (1 << PD2));
		uint8_t currentDown  = (PIND & (1 << PD3));
		uint8_t currentLeft  = (PIND & (1 << PD4));
		uint8_t currentRight = (PIND & (1 << PD5));
		uint8_t currentA     = (PIND & (1 << PD6));
		uint8_t currentB     = (PIND & (1 << PD7));

		if (prevUp && !currentUp) {
			_delay_ms(30);
			if (!(PIND & (1 << PD2))) UART_transmit('0'); // Arriba
		}
		if (prevDown && !currentDown) {
			_delay_ms(30);
			if (!(PIND & (1 << PD3))) UART_transmit('1'); // Abajo
		}
		if (prevLeft && !currentLeft) {
			_delay_ms(30);
			if (!(PIND & (1 << PD4))) UART_transmit('2'); // Izquierda
		}
		if (prevRight && !currentRight) {
			_delay_ms(30);
			if (!(PIND & (1 << PD5))) UART_transmit('3'); // Derecha
		}
		if (prevA && !currentA) {
			_delay_ms(30);
			if (!(PIND & (1 << PD6))) UART_transmit('4'); // Acción A
		}
		if (prevB && !currentB) {
			_delay_ms(30);
			if (!(PIND & (1 << PD7))) UART_transmit('5'); // Acción B
		}

		// Actualizar estados
		prevUp = currentUp;
		prevDown = currentDown;
		prevLeft = currentLeft;
		prevRight = currentRight;
		prevA = currentA;
		prevB = currentB;

		_delay_ms(10);
	}
}
