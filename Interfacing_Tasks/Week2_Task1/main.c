/*
 * main.c
 *
 *  Created on: Mar 1, 2024
 *      Author: Mohammad Tamer
 */


typedef unsigned char u8;
typedef signed char s8;
#define PORT_A *((volatile u8*)0x3B)
#define DDR_A *((volatile u8*)0x3A)
#define PIN_A *((volatile u8*)0x39)

#define PORT_B *((volatile u8*)0x38)
#define DDR_B *((volatile u8*)0x37)
#define PIN_B *((volatile u8*)0x36)

#include <util/delay.h>


int main()
{
	// Set PORTA pin 0 as output for LED 1
	DDR_A |= (1 << 0);
	// Set PORTA pin 1 as output for LED 2
	DDR_A |= (1 << 1);
	// Set PORTB pin 0 as input for switch 1
	DDR_B &=~ (1 << 0);
	// Set PORTB pin 1 as input for switch 1
	DDR_B &=~ (1 << 1);
	// Set PORTB pin 2 as input for switch 2
	DDR_B &=~ (1 << 2);
	// Enable pull-up resistors for PORTB pins
	PORT_B |= (1 << 0) | (1 << 1) | (1 << 2);

	while(1)
	{
		if( !( (PIN_B>>0)& 1) ) //Check if switch 1 is pressed
			{
				PORT_A |= (1 << 0); // Turn on LED 1
				PORT_A &=~ (1 << 1); // Turn off LED 2
			}
		else if( !( (PIN_B>>1)& 1) ) //Check if switch 2 is pressed
			{
				PORT_A |= (1 << 1); // Turn on LED 2
				PORT_A &=~ (1 << 0); // Turn off LED 1
			}
		else if( !( (PIN_B>>2)& 1) ) //Check if switch 3 is pressed
			{
				PORT_A |= (1 << 0); // Turn on LED 1
				PORT_A |= (1 << 1); // Turn on LED 2
			}
		else // no switch is pressed
		{
			PORT_A &=~ (1 << 0); // Turn off LED 1
			PORT_A &=~ (1 << 1); // Turn off LED 2
		}
		_delay_ms(100); // Delay 1 second
	}
	return 0 ;
}

