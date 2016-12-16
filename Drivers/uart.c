/*
 * uart.c
 *
 * Created: 12/8/2016 9:45:36 AM
 *  Author: bogdan.slujitoru
 */ 
#include <avr/io.h>
#include "myfunctions.h"
static  unsigned char my_data[5];
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
	int i = 0;
	while(i < 6){
		while ( !(UCSR0A & (1<<RXC)) ) {
			/* returneaza datele din buffer */
		my_data[i] = UDR0;
		}
		i++;
		if(i = 6){
			i = 0;
		}
		return my_data;
	}
	
}