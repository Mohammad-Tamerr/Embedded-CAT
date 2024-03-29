
/*
 * main.c
 *
 *  Created on: Feb 23, 2024
 *      Author: Mohammad_Tamer
 */

typedef unsigned char u8;
typedef signed char s8;
#define PORT_A *((volatile u8*)0x3B)
#define DDR_A *((volatile u8*)0x3A)
#define PIN_A *((volatile u8*)0x39)
#include <util/delay.h>


int main()
{
	DDR_A = 0b11111111;

	while(1)
	{
		for(s8 i=0 ; i<=7 ; i++)
			{
				PORT_A ^= (1<<i);
				_delay_ms(50);
			}

		for(s8 i=7 ; i>=0 ; i--)
			{
				PORT_A ^= (1<<i);
				_delay_ms(50);
			}
	}
	return 0 ;
}

