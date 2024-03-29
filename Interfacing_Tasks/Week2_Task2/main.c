/*
 * main.c
 *
 *  Created on: Mar 1, 2024
 *  Author: Mohammad Tamer
 *
 */


typedef unsigned char u8;
typedef signed char s8;
#define PORT_A *((volatile u8*)0x3B)
#define DDR_A *((volatile u8*)0x3A)
#define PIN_A *((volatile u8*)0x39)

#define PORT_B *((volatile u8*)0x38)
#define DDR_B *((volatile u8*)0x37)
#define PIN_B *((volatile u8*)0x36)

#define PORT_C *((volatile u8*)0x35)
#define DDR_C *((volatile u8*)0x34)
#define PIN_C *((volatile u8*)0x33)

#define PORT_D *((volatile u8*)0x32)
#define DDR_D *((volatile u8*)0x31)
#define PIN_D *((volatile u8*)0x30)

#include <util/delay.h>


int main() {
    s8 counter = 0;
    // Intialize seven-segment common anode
    u8 seven_seg_arr[10] = {
    		0b00111111, // 0
			0b00000110, // 1
			0b01011011, // 2
			0b01001111, // 3
			0b01100110, // 4
			0b01101101, // 5
			0b01111101, // 6
			0b00000111, // 7
			0b01111111, // 8
			0b01101111  // 9
    };

    // Set PORTA pin 0 as input for switch 1
    DDR_A &= ~(1 << 0);
    // Set PORTA pin 1 as input for switch 2
    DDR_A &= ~(1 << 1);
    // Enable pull-up resistor for PORTA pin 0
    PORT_A |= (1 << 0);
    // Enable pull-up resistor for PORTA pin 1
    PORT_A |= (1 << 1);
    // Set PORTC as output for seven-segment
    DDR_C = 0xFF;
    // Set seven-segment common anode
    PORT_C = 0xFF;
    while (1) {
        if ( !( (PIN_A>>0)& 1) ) // Check if switch 1 is pressed
        {
            _delay_ms(50); // Debouncing delay
            if ( !( (PIN_A>>0)& 1) ) // Check if switch 1 is pressed again
            {
                for (counter = 0; counter <= 9; counter++)
                {
                    PORT_C = ~(seven_seg_arr[counter]); // Display the number
                    _delay_ms(500); // Delay 0.5 second
                }
                while ( !( (PIN_A>>0)& 1) ) // Wait until switch 1 is released
                {
                    _delay_ms(50); // Debouncing delay
                }
            }
        }
        else if ( !( (PIN_A>>1)& 1) ) // Check if switch 2 is pressed
        {
            _delay_ms(50); // Debouncing delay
            if ( !( (PIN_A>>1)& 1) ) // Check if switch 2 is pressed
            {
                for (counter = 9; counter >= 0; counter--)
                {
                    PORT_C = ~(seven_seg_arr[counter]); // Display the number
                    _delay_ms(500); // Delay 0.5 second
                }
                while ( !( (PIN_A>>1)& 1) ) // Wait until switch 2 is released
                {
                    _delay_ms(50); // Debouncing delay
                }
            }
        }
    }
    return 0;
}
