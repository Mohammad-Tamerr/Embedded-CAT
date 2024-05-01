/*
 * main.c
 *
 *  Created on: Apr 26, 2024
 *      Author: Mohammad Tamer
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/PORT/PORT_interface.h"

#include "../../HAL/KEYPAD_DRIVER/KPD_interface.h"
#include "../../HAL/LCD_DRIVER/LCD_interface.h"

#include <util/delay.h>
#include "calc.h"

#define KPD_NO_PREESED_KEY      0xff

/* ASCII values */
#define ASCII_0             48
#define ASCII_9             57
#define ASCII_PLUS          43
#define ASCII_MINUS         45
#define ASCII_MULTIPLY      42
#define ASCII_DIVIDE        47
#define ASCII_EQUALS        61

int main(void)
{
    START_CALC();
    s32 NUM_1 = 0;
    s32 NUM_2 = 0;
    u8 OP = 0;
    s32 RES = 0;
    u8 OP_FLAG = 0;
    u8 FLOAT_FLAG = 0 ;
    float F_RES = 0 ;

    while (1)
    {
        s32 RET_KEY = KPD_GetPressedkey();
        if (RET_KEY == '#')
		{
			// Reset calculator
			lcd_clear();
            RESET_CALC(&NUM_1, &NUM_2, &OP, &RES, &OP_FLAG , &FLOAT_FLAG);
		}
        else if ((RET_KEY >= ASCII_0 && RET_KEY <= ASCII_9) && OP_FLAG == 0)
        {
            NUM_1 = (NUM_1 * 10) + (RET_KEY - ASCII_0);
            lcd_send_data(RET_KEY);
        }
        else if ((RET_KEY >= ASCII_0 && RET_KEY <= ASCII_9) && OP_FLAG == 1)
        {
            NUM_2 = (NUM_2 * 10) + (RET_KEY - ASCII_0);
            lcd_send_data(RET_KEY);
        }
        else if (RET_KEY == ASCII_PLUS || RET_KEY == ASCII_MINUS || RET_KEY == ASCII_MULTIPLY || RET_KEY == ASCII_DIVIDE)
        {
            OP_FLAG = 1;
            OP = RET_KEY;
            lcd_send_data(RET_KEY);
        }

       else if (RET_KEY == ASCII_EQUALS)
        {
                // Perform calculation
    	   switch (OP)
              {
                case ASCII_PLUS:
                    RES = NUM_1 + NUM_2;
                    break;
                case ASCII_MINUS:
                    RES = NUM_1 - NUM_2;
                    break;
                case ASCII_MULTIPLY:
                    RES = NUM_1 * NUM_2;
                    break;
                case ASCII_DIVIDE:
                    if (NUM_2 != 0)
                    {
                    	if(NUM_1>=NUM_2)
                    	{
                    		if((NUM_1 % NUM_2) == 0 )
                    		{
                    			 RES = NUM_1 / NUM_2;
                    		}
                    		else
                    		{
                        		FLOAT_FLAG = 1 ;
                        		F_RES = (float)NUM_1 / (float)NUM_2;
                    		}
                    	}
                    	else if (NUM_1<NUM_2)
                    	{
                    		FLOAT_FLAG = 1 ;
                    		F_RES = (float)NUM_1 / (float)NUM_2;
                    	}
                    }
                    else
                    {
                        // Handle division by zero error
                        lcd_send_string("Error: Division");
                        lcd_go_to_xy(1, 0);
                        lcd_send_string("By ZERO");
                        _delay_ms(2000);
                        lcd_clear();
                        RESET_CALC(&NUM_1, &NUM_2, &OP, &RES, &OP_FLAG , &FLOAT_FLAG);
                        continue; // Skip further processing
                    }
                    break;
                default:
                    RES = NUM_1;
                    break;
              }
                // Display result
    	   	   	lcd_go_to_xy(1, 0);
    	   	   	if (1 == FLOAT_FLAG)
    	   	   	{
    	   	   		lcd_show_float(F_RES);
    	   	   	}
    	   	   	else
    	   	   	{
    	   	   		lcd_show_number(RES);
    	   	   	}
                RESET_CALC(&NUM_1, &NUM_2, &OP, &RES, &OP_FLAG , &FLOAT_FLAG);
            }

        }
    	return 0;
    }
