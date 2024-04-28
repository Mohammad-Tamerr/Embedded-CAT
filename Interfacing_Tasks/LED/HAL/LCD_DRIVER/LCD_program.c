/*
 * LCD_program.c
 *
 * 	    Created on: Apr 21, 2024
 *      Author: Mohammad Tamer
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"

#include <util/delay.h>



void lcd_send_command(u8 command_copy)
{
	/* Set RS PIN to Low to Send Command */
	DIO_Set_Pin_Value( LCD_CTRL_PORT, LCD_RS_PIN, DIO_PIN_LOW);

	/* Set RW PIN to Low to Write on LCD */
	DIO_Set_Pin_Value( LCD_CTRL_PORT, LCD_RW_PIN, DIO_PIN_LOW);

	/* Send command to data pins */
	DIO_Set_Port_Value(LCD_DATA_PORT, command_copy);

	/* Send Enable Pulse */
	DIO_Set_Pin_Value( LCD_CTRL_PORT, LCD_E_PIN, DIO_PIN_HIGH);

	/* delay 2 MS to support initialization delay */
	_delay_ms(2);
}

void lcd_send_data(u8 data_copy)
{
	/* Set RS PIN to Low to Send data */
	DIO_Set_Pin_Value( LCD_CTRL_PORT, LCD_RS_PIN, DIO_PIN_HIGH);

	/* Set RW PIN to Low to Write on LCD */
	DIO_Set_Pin_Value( LCD_CTRL_PORT, LCD_RW_PIN, DIO_PIN_LOW);

	/* Send data to data pins */
	DIO_Set_Port_Value(LCD_DATA_PORT, data_copy);

	/* Send Enable Pulse */
	DIO_Set_Pin_Value( LCD_CTRL_PORT, LCD_E_PIN, DIO_PIN_HIGH);

	/* delay 2 MS to support initialization delay */
	_delay_ms(2);
}

void lcd_initialization(void)
{
	/* Wait For More Than 30 MS */
	_delay_ms(40);

	/* Function Set Command : 5*8 Font Size and 2 lines */
	lcd_send_command(0b00111000);

	/* Display On Off Control : Display Enable , Disable Cursor , No Blink Cursor  */
	lcd_send_command(0b00001100);

	/* Clear Display */
	lcd_send_command(1);
}

u8 lcd_send_string (const char* string_copy)
{
	u8 local_error_status = FUNCTION_NOT_OK;
	u8 local_counter = 0;
	/* check Null pointer case */
	if (NULL == string_copy) /* null pointer */
	{
		local_error_status = FUNCTION_NOT_OK;
	}
	else /* not null pointer */
	{
		/* check null terminator */
		while(string_copy[local_counter] != '\0');
		/* send letter whose number is = local_counter  */
		lcd_send_data(string_copy[local_counter]);
		/* counter increment */
		local_counter++;
		local_error_status = FUNCTION_IS_OK;
	}
	return local_error_status;
}

u8 lcd_go_to_xy (u8 x_dimension_copy ,u8 y_dimension_copy)
{
	u8 local_error_status = FUNCTION_NOT_OK;
	u8 local_adress = 0;
	if (0 == x_dimension_copy)
	{
		local_adress = y_dimension_copy ;
		local_error_status = FUNCTION_IS_OK	;
	}
	else if (1 == x_dimension_copy )
	{
		local_adress = y_dimension_copy + 0x40 ;
		local_error_status = FUNCTION_IS_OK ;
	}
	else
	{
		local_error_status = FUNCTION_NOT_OK ;
	}

	lcd_send_command(local_adress + 128);

	return local_error_status ;
}

u8 lcd_store_special_character (u8* pattern_copy, u8 location_number)
{
	u8 local_error_status;
	u8 local_adress = 0;
	u8 local_counter = 0;
	/* check Null pointer case */
	if (NULL == pattern_copy)
	{
		local_error_status = FUNCTION_NOT_OK; /* null pointer */
	}
	else /* not null pointer */
	{
		/* calculate the address */
		local_adress = location_number * 8 ;

		/* send CGRAM command to LCD */
		lcd_send_command(local_adress + 64) ;

		/* write the pattern in CGRAM */
		for  (local_counter=0 ; local_counter<8 ; local_counter++ )
		{
			lcd_send_data(pattern_copy[local_counter]);
		}
		local_error_status = FUNCTION_IS_OK;
	}

	return local_error_status ;
}

void lcd_show_special_character (u8 location_number, u8 x_dimension_copy,u8 y_dimension_copy)
{
	/* go to CGRAM to display the pattern  */
	lcd_go_to_xy(x_dimension_copy , y_dimension_copy );

	/* display the pattern on LCD from CGRAM */
	lcd_send_data(location_number);
}

void lcd_show_number(s32 number_copy)
{
		/* check negative numbers */
	  if (number_copy < 0)
	  	{
	        lcd_send_data('-'); /* send negative to LCD */
	        number_copy = -number_copy;
	    }
	  /* check if the number is = 0 */
	if (number_copy == 0) /* 0 */
	{
		lcd_send_data('0');
	}
	else /* not 0 */
	{
		u8 Local_digits = 	0;
		u8 Local_counter_Of_digits = 0;
		u8 Local_Counter =	0 ;
		u8 Local_Number_Copy   = number_copy;
		/* calculate how many digits */
		do {
			Local_counter_Of_digits++;
			Local_Number_Copy /= 10;
			} while (Local_Number_Copy != 0);

		u8 Local_Arr_Of_Digits [Local_counter_Of_digits]; /* array to store digits */
		Local_Counter = Local_counter_Of_digits ;
		while (Local_Counter) /* get each digit */
		{
			Local_Counter -- ;
			Local_digits = number_copy % 10 ;
			Local_Arr_Of_Digits [Local_Counter] = Local_digits;
			Local_Counter++ ;
			number_copy /= 10 ;
		}
		/* show digits on LCD */
		for(Local_Counter = 0 ; Local_Counter < Local_counter_Of_digits ; Local_Counter ++)
		{
            lcd_send_data(Local_Arr_Of_Digits[Local_Counter] + '0');

		}
	}
}

void lcd_clear (void)
{
	lcd_send_command(LCD_CLEAR_CMD);
}

