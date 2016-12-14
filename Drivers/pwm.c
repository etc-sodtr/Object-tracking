/*
 * CFile1.c
 *
 * Created: 12/13/2016 2:43:48 PM
 *  Author: bogdan.slujitoru
 */ 
#include <avr/io.h>
void PWMinit(){
	/*initialziare counter */
	TCNT1 = 0;
	/*Fast PWM , 64 prescaler, */
	TCCR1A = 0b00100010;
	TCCR1B = 0b00011010;
	/* 20ms semnal pwm */
	ICR1 = 5000;
}
void setPWM(int pwm1, int pwm2){
	OCR1A = pwm1;
	OCR1B = pwm2;
}