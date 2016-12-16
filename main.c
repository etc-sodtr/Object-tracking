/*
 * AT128.c
 *
 * Created: 12/8/2016 8:05:23 AM
 * Author : bogdan.slujitoru
 */ 

#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include "FreeRTOSConfig.h"
#include "myfunctions.h"
int main(void)
{
	xTaskCreate(vPWMtask,"oTracking",configMINIMAL_STACK_SIZE,NULL,1,NULL);
	vTaskStartScheduler();
	return 0;
		   
}

