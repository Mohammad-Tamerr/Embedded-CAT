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

#define WELCOME_MESSAGE_1   "Welcome"
#define WELCOME_MESSAGE_2   "This Is Mo's"
#define WELCOME_MESSAGE_3   "Calculator"

void START_CALC(void)
{
    PORT_voidInit();
    lcd_initialization();
    lcd_go_to_xy(1, 4);
    lcd_send_string(WELCOME_MESSAGE_1);
    _delay_ms(1500);
    lcd_clear();
    lcd_go_to_xy(0, 2);
    lcd_send_string(WELCOME_MESSAGE_2);
    lcd_go_to_xy(1, 3);
    lcd_send_string(WELCOME_MESSAGE_3);
    _delay_ms(1500);
    lcd_clear();
}

void RESET_CALC ( s32 * NUM_1 , s32 * NUM_2 , u8 * OP , s32 * RES , u8 * OP_FLAG ,u8 *FLOAT_FLAG )
{
    *NUM_1 = 0;
    *NUM_2 = 0;
    *OP = 0;
    *RES = 0;
    *OP_FLAG = 0;
    *FLOAT_FLAG = 0 ;
}

