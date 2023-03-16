/*
 * Traffic-Ligth.c
 *
 * Created: 3/12/2023 10:53:19 PM
 * Author : DeSkToP
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "7seg.h"
#include "timer.h"

#define	SEG_PORT	DIO_PORTC
#define	LEDS_PORT	DIO_PORTD

#define	RED_LED_PIN	DIO_PIN0
#define	YELLOW_LED_PIN	DIO_PIN1
#define	GREEN_LED_PIN	DIO_PIN2

unsigned char counter = 0;


int main(void)
{
	seven_seg_init(SEG_PORT);
	dio_set_pin_direction(LEDS_PORT, RED_LED_PIN, DIO_DIRECTION_OUTPUT);
	dio_set_pin_direction(LEDS_PORT, YELLOW_LED_PIN, DIO_DIRECTION_OUTPUT);
	dio_set_pin_direction(LEDS_PORT, GREEN_LED_PIN, DIO_DIRECTION_OUTPUT);
	
    timer0_CTC_init();

	while (1) 
    {
		unsigned char red_counter = 9;
		unsigned char yellow_counter = 5;
		unsigned char green_counter = 9;
		
		seven_seg_write(SEG_PORT, green_counter);
		//turn on the green led
		dio_write_pin(LEDS_PORT, GREEN_LED_PIN, DIO_LEVEL_HIGH);
		
		while (green_counter > 0)
		{
			//1 sec has passed
			if (counter >= 100)
			{
				counter = 0;
				green_counter--;
				seven_seg_write(SEG_PORT, green_counter);
			}
		}
		_delay_ms(400);
		//turn off the green led
		dio_write_pin(LEDS_PORT, GREEN_LED_PIN, DIO_LEVEL_LOW);
		//turn on the yellow led
		dio_write_pin(LEDS_PORT, YELLOW_LED_PIN, DIO_LEVEL_HIGH);
		seven_seg_write(SEG_PORT, yellow_counter);
		
		while (yellow_counter > 0)
		{
			//1 sec has passed
			if (counter >= 100)
			{
				counter = 0;
				yellow_counter--;
				seven_seg_write(SEG_PORT, yellow_counter);
			}
		}
		_delay_ms(400);
		//turn off the yellow led
		dio_write_pin(LEDS_PORT, YELLOW_LED_PIN, DIO_LEVEL_LOW);
		//turn on the red led
		dio_write_pin(LEDS_PORT, RED_LED_PIN, DIO_LEVEL_HIGH);
		seven_seg_write(SEG_PORT, red_counter);
		
		while (red_counter > 0)
		{
			//1 sec has passed
			if (counter >= 100)
			{
				counter = 0;
				red_counter--;
				seven_seg_write(SEG_PORT, red_counter);
			}
		}
		_delay_ms(400);
		//turn off the red led
		dio_write_pin(LEDS_PORT, RED_LED_PIN, DIO_LEVEL_LOW);
    }
}

ISR(TIMER0_COMP_vect)
{
	counter++;
}
