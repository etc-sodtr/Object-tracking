/*
 * mytasks.c
 *
 * Created: 12/8/2016 10:46:17 AM
 *  Author: bogdan.slujitoru
 */ 
#include <avr/io.h>
#define FOSC 16000000// Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1
static char my_data [5];
void vUSARTtask( void *pvParameters ){
	
	USART_Init(MYUBRR);
	for(;;){
		USART_Receive();
	}
}
void vPWMtask( void *pvParameters ){
	
}