/*
 * myfunctions.h
 *
 * Created: 12/16/2016 3:45:08 PM
 *  Author: bogdan.slujitoru
 */ 


#ifndef MYFUNCTIONS_H_
#define MYFUNCTIONS_H_
void USART_Init( unsigned int ubrr );
void USART_Transmit( unsigned char data );
unsigned char USART_Receive( void );
void PWMinit();
void setPWM(int pwm1, int pwm2);
void vPWMtask( void *pvParameters );




#endif /* MYFUNCTIONS_H_ */