/*
 * main.c
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
#include "calc.h"

#define KPD_NO_PREESED_KEY      0xff

int main(void)
{
	START_CALC();
	s32 	NUM_1 = 0 ;
	s32 	NUM_2 = 0 ;
	u8 		OP = 0 ;
	s32 	RES = 0 ;
	u8 		OP_FLAG = 0 ;

    while (1)
    {
        s32 RET_KEY = KPD_GetPressedkey();

        if (RET_KEY != KPD_NO_PREESED_KEY )
        {
            if (RET_KEY == '#')
            {
                lcd_clear();
                RESET_CALC(&NUM_1, &NUM_2, &OP, &RES , & OP_FLAG );
            }
            else if ((RET_KEY >= '0' && RET_KEY <= '9') && OP_FLAG == 0)
            {
            	NUM_1 = (NUM_1 * 10) + (RET_KEY - '0');
                lcd_send_data(RET_KEY);
            }
            else if ((RET_KEY >= '0' && RET_KEY <= '9') && OP_FLAG == 1)
            {
                NUM_2 = (NUM_2 * 10) + (RET_KEY - '0');
                lcd_send_data(RET_KEY);
            }
            else if (RET_KEY == '+' || RET_KEY == '-' || RET_KEY == '*' || RET_KEY == '/')
            {
            	OP_FLAG = 1;
            	OP = RET_KEY;
                lcd_send_data(RET_KEY);
            }
            else if (RET_KEY == '=')
            {
                lcd_clear();
            }
                switch (OP)
                {
                    case '+':
                        RES = NUM_1 + NUM_2;
                        break;
                    case '-':
                    	RES = NUM_1 - NUM_2;
                        break;
                    case '*':
                    	RES = NUM_1 * NUM_2;
                        break;
                    case '/':
                        if (NUM_2 != 0)
                        {
                        	RES = NUM_1 / NUM_2;
                        }
                        else /* Handle division by zero error */
                        {
                            lcd_send_string("Error: Division");
                            lcd_go_to_xy(1,0);
                            lcd_send_string("By ZERO");
                            _delay_ms(2000);
                            lcd_clear();
                            RESET_CALC(&NUM_1, &NUM_2, &OP, &RES , & OP_FLAG );
                        }
                        break;
                    default:
                        RES = NUM_1;
                        break;
                }

                RESET_CALC(&NUM_1, &NUM_2, &OP, &RES , & OP_FLAG );
            }
        }
    return 0;
  }
