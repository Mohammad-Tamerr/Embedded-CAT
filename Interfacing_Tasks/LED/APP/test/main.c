/*
 * main.c
 *
 *  Created on: Apr 26, 2024
 *      Author: dell
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/PORT/PORT_interface.h"

#include "../../HAL/KEYPAD_DRIVER/KPD_interface.h"
#include "../../HAL/LCD_DRIVER/LCD_interface.h"


void main()
{
	lcd_initialization();
	port_void_init();
	while (1)
	{
		lcd_show_number(2);
	}
}
