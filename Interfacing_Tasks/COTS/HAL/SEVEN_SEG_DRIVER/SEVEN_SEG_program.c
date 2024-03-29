/*
 * 		SEVEN_SEG_program.c
 *
 *  	Created on: Mar 8, 2024
 *      Author: Mohammad Tamer
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_register.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include <util/delay.h>

#define NULL 				0
#define FUNCTION_IS_OK 		0
#define FUNCTION_NOT_OK 	1

#define Anode    1
#define Cathode  2

u8 seven_seg_arr_anode[10] =
	{
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

u8 Seven_Seg_Init (u8 port_copy)
{
	u8 Local_Error_Status = FUNCTION_IS_OK ;

		switch(port_copy)
			{
				case DIO_PORT_A: DDR_A = 0xff ;	    break ;
				case DIO_PORT_B: DDR_B = 0xff ;     break ;
				case DIO_PORT_C: DDR_C = 0xff ; 	break ;
				case DIO_PORT_D: DDR_D = 0xff ; 	break ;
				default : Local_Error_Status = FUNCTION_NOT_OK ;
			}

	return Local_Error_Status;
}


u8 Seven_Seg_TurnON (u8 port_copy, u8 Number , u8 type)
{
	u8 Local_Error_Status = FUNCTION_IS_OK ;
	if((Number <=9) &&(Number >=0))
		{
			if (type == Anode)
			{
			DIO_Set_Port_Value(port_copy, seven_seg_arr_anode[Number] );
			}
			else if (2 == Cathode)
			{
				DIO_Set_Port_Value(port_copy, ~(seven_seg_arr_anode[Number]) );
			}
			else
			{
				Local_Error_Status = FUNCTION_NOT_OK;
			}
	}
	return Local_Error_Status ;
}


u8 Seven_Seg_TurnOff (u8 port_copy , u8 type)
{
	u8 Local_Error_Status = FUNCTION_IS_OK ;
		if (type == Anode)
		{
		DIO_Set_Port_Value(port_copy, 0xff );
		}
		else if (type == Cathode)
		{
			DIO_Set_Port_Value(port_copy, 0x00 );
		}
		else
		{
			Local_Error_Status = FUNCTION_NOT_OK;
		}
	return Local_Error_Status;
}

u8 Seven_Seg_CountUp (u8 port_copy ,u8 Number, u8 type)
{
	u8 Local_Error_Status = FUNCTION_IS_OK ;
		if((Number <=9) &&(Number >=0))
		{
			for(s8 counter = Number ; counter<10 ; counter++ )
			{
				Seven_Seg_TurnON (port_copy, Number , type);
				 _delay_ms(500);
			}
		}
		else
		{
			Local_Error_Status = FUNCTION_NOT_OK;
		}

	return Local_Error_Status;
}



u8 Seven_Seg_Countdown (u8 port_copy,u8 Number ,u8 type)
{
	u8 Local_Error_Status = FUNCTION_IS_OK ;
		if((Number <=9) &&(Number >=0))
		{
			for(s8 counter = Number ; counter>=0 ; counter-- )
			{
				Seven_Seg_TurnON (port_copy, Number , type);
				_delay_ms(500);
			}
		}
		else
		{
			Local_Error_Status = FUNCTION_NOT_OK;
		}

	return Local_Error_Status;

}









