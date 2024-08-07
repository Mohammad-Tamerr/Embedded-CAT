/*
 * ping_pong.c
 *
 *  Created on: Jul 3, 2024
 *      Author: Mohammad Tamer
 */

/*Including Libraries*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/*Including MCAL Layer Drivers*/
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/PORT/PORT_interface.h"
#include "../../MCAL/External_Interrupt/EXI_interface.h"
#include "../../MCAL/GIE/GIE_interface.h"

/*Including HAL Layer Drivers*/
#include "../../HAL/LCD_DRIVER/LCD_interface.h"
#include "../../HAL/SWITCH_DRIVER/SWITCH_inerface.h"

#include "Ping_Pong.h"
#include <util/delay.h>


#define WELCOME_MESSAGE_1		"Are You Ready?!"
#define WELCOME_MESSAGE_2		"Game  Has"
#define WELCOME_MESSAGE_3		"Started"
#define WELCOME_MESSAGE_4		"Good Luck!"

u8 ball_pattern[8] = {
    0b00000,
    0b01110,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b01110,
    0b00000
};


u8 positions[17][2] = {
    {1, 0}, {1, 1}, {0, 2}, {0, 3}, {0, 4},
    {0, 5}, {0, 6}, {0, 7}, {0, 8}, {0, 9},
    {0, 10}, {0, 11}, {0, 12}, {0, 13}, {0, 14},
    {1, 15}, {1, 16}
};

void Game_VoidIntialization()
{
	PORT_voidInit();
	lcd_initialization();

	lcd_go_to_xy(0,1);
	lcd_send_string(WELCOME_MESSAGE_1);
    _delay_ms(500);
	lcd_clear();

	lcd_go_to_xy(0,4);
	lcd_send_string(WELCOME_MESSAGE_2);
	lcd_go_to_xy(1,5);
	lcd_send_string(WELCOME_MESSAGE_3);
    _delay_ms(500);
	lcd_clear();

	lcd_go_to_xy(1,3);
	lcd_send_string(WELCOME_MESSAGE_4);
    _delay_ms(500);
	lcd_clear();
}


void Ball_VoidMovingLeftToRight()
{
	lcd_store_special_character(ball_pattern,0);
    for (int i = 0; i < 17; i++)
    {
        lcd_show_special_character(0, positions[i][0], positions[i][1]);
        _delay_ms(70);
        lcd_clear();
    }
}

void Ball_VoidMovingRightToLeft()
{
	lcd_store_special_character(ball_pattern,0);
	for (int i = 16 ; i >= 0; i--)
    {
        lcd_show_special_character(0, positions[i][0], positions[i][1]);
        _delay_ms(70);
        lcd_clear();
    }
}

void View_u8Score(u8 Player_One_u8Score_Copy, u8 Player_Two_u8Score_Copy)
{
	lcd_go_to_xy(1,6);
	lcd_show_number(Player_One_u8Score_Copy);
	lcd_go_to_xy(1,8);
	lcd_send_string("-");
	lcd_go_to_xy(1,10);
	lcd_show_number(Player_Two_u8Score_Copy);
	_delay_ms(500);
	lcd_clear();
}
