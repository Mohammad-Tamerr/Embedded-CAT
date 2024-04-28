/*
 * calc.c
 *
 *  Created on: Apr 26, 2024
 *      Author: Mohammad Tamer
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/PORT/PORT_interface.h"

#include "../../HAL/KEYPAD_DRIVER/KPD_interface.h"
#include "../../HAL/LCD_DRIVER/LCD_interface.h"
#include <util/delay.h>



void START_CALC(void)
{
			port_void_init();
			lcd_initialization();
			lcd_send_string("Welcome");
			_delay_ms(1500);
			lcd_clear();
			lcd_send_string("This Is Mo's");
			lcd_go_to_xy(1,0);
			lcd_send_string("Calculator");
			_delay_ms(1500);
			lcd_clear();
			lcd_show_number(32);
			_delay_ms(1500);
			lcd_clear();
			lcd_show_number(-32);
			_delay_ms(1500);
			lcd_clear();
}

void RESET_CALC ( s32 * NUM_1 , s32 * NUM_2 , u8 * OP , s32 * RES , u8 * OP_FLAG )
{
	*NUM_1 = 0 ;
	*NUM_2 = 0 ;
	*OP 	  = 0 ;
	*RES   = 0 ;
	*OP_FLAG = 0 ;
}

