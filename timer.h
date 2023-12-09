/*
 * timer.h
 *
 *  Author: Mohamed Sameh
 */ 


#ifndef TIMER_H_
#define TIMER_H_

/* Section : Includes */
#include <avr/interrupt.h>
#include "dio.h"

/* Section : Macro Declarations */
#define PULSE_PORT_A		DIO_PORTD
#define PULSE1_PIN_A		DIO_PIN5

#define PULSE_PORT_B		DIO_PORTD
#define PULSE1_PIN_B		DIO_PIN4

/* Section : Macro Functions Declarations */

/* Section : Data Types Declarations  */

/* Section : Functions Declarations */
/**
 * @brief Initializes the Normal Mode in Timer0
 * 
 */
void timer0_normalmode_init();

/**
 * @brief Initializes the Clear Timer on Compare Mode in Timer0
 * 
 */
void timer0_CTC_init();

/**
 * @brief Deinitializes the Timer0
 * 
 */
void timer0_deinit();

/**
 * @brief 
 * 
 * @param v 
 */
void timer1_fastPWM_A(double v);

/**
 * @brief 
 * 
 * @param v 
 */
void timer1_fastPWM_B(double v);


#endif /* TIMER_H_ */