/*
 * uart.c
 *
 * Created: 12/8/2016 9:45:36 AM
 *  Author: bogdan.slujitoru
 */ 
#include <avr/io.h>

void USART_Init(unsigned int ubrr )
{
	/* setarea baud rate-ului */
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	/* setarea registrului UCSR0B pentru receptie si transmisie */
	UCSR0B = (1<<RXEN)|(1<<TXEN);
	/* cadre de 8 biti , 1 bit stop */
	UCSR0C = (0<<USBS)|(3<<UCSZ0);
}

unsigned char USART_Receive( void )
{
	/* primirea datelor */
	while ( !(UCSR0A & (1<<RXC)) ) 
	;
	/* returneaza datele din buffer */
	return UDR0;
}