/*
 * LED_program.c
 *
 *  	Created on: Mar 8, 2024
 *      Author: Mohammad Tamer
 */


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/DIO/DIO_register.h"

#define NULL 				0
#define FUNCTION_IS_OK 		0
#define FUNCTION_NOT_OK 	1

u8 LED_ON (u8 copy_port , u8 copy_pin)
{
	u8 Local_Status_Error = FUNCTION_IS_OK ;
	if(copy_pin<=DIO_PIN_7)
	{
			switch(copy_port)
			{
				case DIO_PORT_A : SET_BIT(PORT_A,copy_pin); break;
				case DIO_PORT_B : SET_BIT(PORT_B,copy_pin); break;
				case DIO_PORT_C : SET_BIT(PORT_C,copy_pin); break;
				case DIO_PORT_D : SET_BIT(PORT_D,copy_pin); break;
				default : Local_Status_Error = FUNCTION_NOT_OK ;
			}
	}
	else
	{
		Local_Status_Error = FUNCTION_NOT_OK ;
	}
	return Local_Status_Error;
}
u8 LED_OFF (u8 copy_port , u8 copy_pin)
{
	u8 Local_Status_Error = FUNCTION_IS_OK ;
	if(copy_pin<=DIO_PIN_7)
		{
			switch(copy_port)
			{
				case DIO_PORT_A : CLR_BIT(PORT_A,copy_pin); break;
				case DIO_PORT_B : CLR_BIT(PORT_B,copy_pin); break;
				case DIO_PORT_C : CLR_BIT(PORT_C,copy_pin); break;
				case DIO_PORT_D : CLR_BIT(PORT_D,copy_pin); break;
				default : Local_Status_Error = FUNCTION_NOT_OK ;
			}
		}
		else
		{
			Local_Status_Error = FUNCTION_NOT_OK ;
		}

	return Local_Status_Error;

}

u8 LED_ALL_PORT_ON (u8 copy_port)
{
	u8 Local_Status_Error = FUNCTION_IS_OK ;
	switch(copy_port)
		{
			case DIO_PORT_A : PORT_A = 0xff;  break;
			case DIO_PORT_B : PORT_B = 0xff;  break;
			case DIO_PORT_C : PORT_C = 0xff;  break;
			case DIO_PORT_D : PORT_D = 0xff;  break;
			default : Local_Status_Error = FUNCTION_NOT_OK ;
		}
	return Local_Status_Error;

}

u8 LED_ALL_PORT_OFF (u8 copy_port)
{
	u8 Local_Status_Error = FUNCTION_IS_OK ;
	switch(copy_port)
		{
			case DIO_PORT_A : PORT_A = 0;  break;
			case DIO_PORT_B : PORT_B = 0;  break;
			case DIO_PORT_C : PORT_C = 0;  break;
			case DIO_PORT_D : PORT_D = 0;  break;
			default : Local_Status_Error = FUNCTION_NOT_OK ;
		}
	return Local_Status_Error;

}
