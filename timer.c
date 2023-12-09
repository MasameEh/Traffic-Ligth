/*
 * timer.c
 *
 *  Author: Mohamed Sameh
 */ 

#include "timer.h"

/**
 * @brief Initializes the Normal Mode in Timer0
 * 
 */
void timer0_normalmode_init()
{
	
	//PRESCALER -> 1024
	SET_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS02);
	//Enable interrupt
	sei();
	SET_BIT(TIMSK,TOIE0);
}

/**
 * @brief Initializes the Clear Timer on Compare Mode in Timer0
 * 
 */
void timer0_CTC_init()
{
	//Select CTC mode
	SET_BIT(TCCR0,WGM01);
	//Load a value in OCR0 
	OCR0=78;
	//PRESCALER -> 1024
	SET_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS02);
	//Enable interrupt
	sei();
	SET_BIT(TIMSK,OCIE0);
}

/**
 * @brief Deinitializes the Timer0
 * 
 */
void timer0_deinit()
{
	//PRESCALER -> NOCLOCK SOURCE
	CLR_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);
	//disable interrupt
	CLR_BIT(TIMSK, TOIE0);
}


void timer1_fastPWM_A(double v)
{
	//Sets OC1A as output pin 
	dio_set_pin_direction(PULSE_PORT_A,PULSE1_PIN_A,DIO_DIRECTION_OUTPUT);
	//Selects fastPWM mode
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	//
	OCR1A = v*1000;
	ICR1 = 20000; 
	//Selects timer clock, no prescaling
	SET_BIT(TCCR1B,CS10);
	//Clears OC1A on compare match, set OC1A at BOTTOM
	SET_BIT(TCCR1A,COM1A1);
}

void timer1_fastPWM_B(double v)
{
	//Sets OC1B as output pin
	dio_set_pin_direction(PULSE_PORT_B,PULSE1_PIN_B,DIO_DIRECTION_OUTPUT);
	//selects fastPWM mode
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	//
	OCR1B = v*1000;
	ICR1 = 20000;
	//Selects timer clock, no prescaling
	SET_BIT(TCCR1B,CS10);
	//Clears OC1B on compare match, set OC1B at BOTTOM
	SET_BIT(TCCR1A,COM1B1);
}