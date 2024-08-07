/*
 * DIO_program.c
 *
 *	    Created on: Mar 8, 2024
 *      Author: Mohammad Tamer
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_register.h"
#include "../../MCAL/DIO/DIO_interface.h"

#define NULL 				0
#define FUNCTION_IS_OK 		0
#define FUNCTION_NOT_OK 	1



u8 DIO_Set_Pin_Direction(u8 port_copy , u8 pin_copy , u8 direction_copy  )
{
		u8 Local_Error_Status = FUNCTION_IS_OK ;
		if(pin_copy<=DIO_PIN_7)
		{
			if(direction_copy == DIO_PIN_INPUT)
			{
					switch(port_copy)
				{
						case DIO_PORT_A: CLR_BIT(DDR_A, pin_copy) ; break ;
						case DIO_PORT_B: CLR_BIT(DDR_B, pin_copy) ; break ;
						case DIO_PORT_C: CLR_BIT(DDR_C, pin_copy) ; break ;
						case DIO_PORT_D: CLR_BIT(DDR_D, pin_copy) ; break ;
						default : Local_Error_Status = FUNCTION_NOT_OK ;
				}
		}
		else if (direction_copy == DIO_PIN_OUTPUT)
		{
					switch (port_copy)
				{
					case DIO_PORT_A: SET_BIT(DDR_A, pin_copy) ; break ;
					case DIO_PORT_B: SET_BIT(DDR_B, pin_copy) ; break ;
					case DIO_PORT_C: SET_BIT(DDR_C, pin_copy) ; break ;
					case DIO_PORT_D: SET_BIT(DDR_D, pin_copy) ; break ;
					default : Local_Error_Status = FUNCTION_NOT_OK ;
				}
		}
		else
		{
				Local_Error_Status = FUNCTION_NOT_OK ;
		}
}

	return Local_Error_Status;
}

u8 DIO_Set_Port_Direction(u8 port_copy , u8 direction_copy  )
{
	u8 Local_Error_Status = FUNCTION_IS_OK ;

			switch(port_copy)
		{
			case DIO_PORT_A: PORT_A = direction_copy ;    break ;
			case DIO_PORT_B: PORT_B  = direction_copy ;   break ;
			case DIO_PORT_C: PORT_C = direction_copy ;    break ;
			case DIO_PORT_D: PORT_D  = direction_copy ;   break ;
			default : Local_Error_Status = FUNCTION_NOT_OK ;
		}

	return Local_Error_Status;

}

u8 DIO_Set_Pin_Value(u8 port_copy , u8 pin_copy , u8 value_copy )
{
	u8 Local_Error_Status =  FUNCTION_IS_OK ;
		if(pin_copy <= 7)
		{
			if (value_copy == DIO_PIN_LOW)
			{
				switch(port_copy)
				{
					case DIO_PORT_A: CLR_BIT(PORT_A, pin_copy) ;    break ;
					case DIO_PORT_B: CLR_BIT(PORT_B, pin_copy) ;    break ;
					case DIO_PORT_C: CLR_BIT(PORT_C, pin_copy) ;    break ;
					case DIO_PORT_D: CLR_BIT(PORT_D, pin_copy) ;    break ;
					default : Local_Error_Status = FUNCTION_NOT_OK ;
				}
			}
			else if (value_copy == DIO_PIN_HIGH)
			{
				switch(port_copy)
				{
					case DIO_PORT_A: SET_BIT(PORT_A, pin_copy) ;    break ;
					case DIO_PORT_B: SET_BIT(PORT_B, pin_copy) ;    break ;
					case DIO_PORT_C: SET_BIT(PORT_C, pin_copy) ;    break ;
					case DIO_PORT_D: SET_BIT(PORT_D, pin_copy) ;    break ;
					default : Local_Error_Status = FUNCTION_NOT_OK ;
				}
			}
			else
			{
			  Local_Error_Status = FUNCTION_NOT_OK ;
			}
		}
		else
		{
			 Local_Error_Status = FUNCTION_NOT_OK ;
		}
	return Local_Error_Status ;

}

u8 DIO_Set_Port_Value(u8 port_copy  , u8  value_copy  )
{
	u8 Local_Error_Status =  FUNCTION_IS_OK ;
		switch(port_copy)
		{
			case DIO_PORT_A: PORT_A  =   value_copy ;    break ;
			case DIO_PORT_B: PORT_B  =   value_copy ;    break ;
			case DIO_PORT_C: PORT_C  =   value_copy ;    break ;
			case DIO_PORT_D: PORT_D  =   value_copy ;    break ;
			default : Local_Error_Status = FUNCTION_NOT_OK ;
		}
	return Local_Error_Status ;

}

u8 DIO_Get_Pin_VALUE(u8 port_copy , u8 pin_copy , char* Pin_Value  )
{
	u8 Local_Error_Status =  FUNCTION_IS_OK ;
	if( (Pin_Value!=NULL) && (pin_copy <= 7) )
	{
		switch(port_copy)
		{
			case DIO_PORT_A: (*Pin_Value) = GET_BIT(PIN_A, pin_copy) ;    break ;
			case DIO_PORT_B: (*Pin_Value) = GET_BIT(PIN_B, pin_copy) ;    break ;
			case DIO_PORT_C: (*Pin_Value) = GET_BIT(PIN_C, pin_copy) ;    break ;
			case DIO_PORT_D: (*Pin_Value) = GET_BIT(PIN_D, pin_copy) ;    break ;
			default : Local_Error_Status = FUNCTION_NOT_OK ;
		}
	}
	else
	{
		Local_Error_Status = FUNCTION_NOT_OK ;
	}
	return Local_Error_Status ;

}

u8 DIO_Toggle_Pin_Value(u8 port_copy, u8 pin_copy)
{
    u8 Local_Error_Status = FUNCTION_IS_OK;

    if(pin_copy <= 7)
    {
        switch(port_copy)
        {
            case DIO_PORT_A: TOGGLE_BIT(PORT_A, pin_copy); break;
            case DIO_PORT_B: TOGGLE_BIT(PORT_B, pin_copy); break;
            case DIO_PORT_C: TOGGLE_BIT(PORT_C, pin_copy); break;
            case DIO_PORT_D: TOGGLE_BIT(PORT_D, pin_copy); break;
            default: Local_Error_Status = FUNCTION_NOT_OK;
        }
    }
    else
    {
        Local_Error_Status = FUNCTION_NOT_OK;
    }

    return Local_Error_Status;
}
