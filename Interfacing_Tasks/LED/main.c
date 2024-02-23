
/*
 * main.c
 *
 *  Created on: Feb 23, 2024
 *      Author: Mohammad_Tamer
 */

typedef unsigned char u8;
#define PORT_A *((volatile u8*)0x3B)
#define DDR_A *((volatile u8*)0x3A)
#define PIN_A *((volatile u8*)0x39)
#include <util/delay.h>


int main()
{
	// pin 0 is output //
	DDR_A |= (1<<0);

	while(1)
	{
		// pin 0 is high//
		PORT_A |= (1<<0);
		// delay 1 second //
		_delay_ms(1000);
		// pin 0 is low //
		PORT_A &=~ (1<<0);
		// delay 1 second //
		_delay_ms(1000);
	}
	return 0 ;
}

