/*
 * SWITCH_program.c
 *
 *  	Created on: Mar 9, 2024
 *      Author: Mohammad Tamer
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_register.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include <util/delay.h>

#define FUNCTION_IS_OK 		  0
#define FUNCTION_NOT_OK 	  1

#define PULL_UP_SWITCH		  0
#define PULL_DOWN_SWITCH	  1

#define SWITCH_IS_PRESSED	  0
#define SWITCH_NOT_PRESSED	  1


u8 Switch_Status (u8 port_copy , u8 pin_copy , u8 type , u8* switch_statues )
{
	u8 Local_Error_Status = FUNCTION_IS_OK ;
	u8 Ret_Val = 0 ;
	if(type == PULL_UP_SWITCH)
	{
		if(pin_copy<=DIO_PIN_7)
		{
			Ret_Val =  GET_BIT(port_copy, pin_copy) ;
			if(Ret_Val == 0)
			{
				_delay_ms(50);
				if(Ret_Val == 0)
				{
					*switch_statues = SWITCH_IS_PRESSED;
				}
				else
				{
					*switch_statues = SWITCH_NOT_PRESSED;
				}
			}
		}
		else
		{
			Local_Error_Status = FUNCTION_NOT_OK ;
		}
	}
	else if(type == PULL_DOWN_SWITCH)
		{
			if(pin_copy<=DIO_PIN_7)
			{
				Ret_Val =  GET_BIT(port_copy, pin_copy) ;
				if(Ret_Val == 1)
				{
					_delay_ms(50);
					if(Ret_Val == 1)
					{
					*switch_statues = SWITCH_IS_PRESSED;
					}
					else
					{
						*switch_statues = SWITCH_NOT_PRESSED;
					}
				}
			}
			else
			{
				Local_Error_Status = FUNCTION_NOT_OK ;
			}
		}

	return Local_Error_Status;
}
