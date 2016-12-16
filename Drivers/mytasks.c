/*
 * mytasks.c
 *
 * Created: 12/8/2016 10:46:17 AM
 *  Author: bogdan.slujitoru
 */ 
#include "FreeRTOSConfig.h"
#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include "myfunctions.h"
#include "mpu_wrappers.h"
#define FOSC 16000000// Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1
static  unsigned char x[3];
static  unsigned char y[3];
static int a;
static int b;

void vUSARTtask( void *pvParameters ){
	
	USART_Init(MYUBRR);
	for(;;){
		USART_Receive();
	}
} 
void vPWMtask( void *pvParameters ){
	PWMinit();
	setPWM(2500,2500);
	xTaskCreate(vUSARTtask,"USART",configMINIMAL_STACK_SIZE,NULL,1,NULL);
	/* rastrangele datele in 2 array, x pentru orizontala si y pentru verticala */
	static unsigned char my_data[5];
	for(;;){
		vTaskSuspend( NULL );
		strncpy(x,my_data,3);
		x[3]='\0';
		strncpy(y,my_data+3,3);
		y[3]='\0';
		
		a = atoi(x);
		b = atoi(y);
	/* urmarire pe orizontala */
	/* calculeaza diferenta dintre pozitia obiectului si centrul imaginii pentru calculul PWM pentru urmarire */
		if((a - 320) > 0)
		{
			OCR1A = OCR1A - (a - 320);	
			vTaskDelay(500);
		}
		else
		{
			OCR1A = OCR1A + (a - 320);
			vTaskDelay(500);
		}
	/* urmarirea pe verticala */
		if((b - 240) > 0)
		{
			OCR1B = OCR1B - (b - 240);
			vTaskDelay(500);	
		}
		else
		{
			OCR1B = OCR1B + (b + 240);
			vTaskDelay(500);
		}
		vTaskResume (NULL);
	
	}
}