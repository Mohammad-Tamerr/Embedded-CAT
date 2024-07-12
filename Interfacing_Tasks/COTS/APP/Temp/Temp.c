/*
 * Temp.c
 *
 *  Created on: Jul 12, 2024
 *      Author: Mohammad Tamer
 */

/*Including Libraries*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/*Including MCAL Layer Drivers*/
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/PORT/PORT_interface.h"
#include "../../MCAL/ADC/ADC_interface.h"
/*Including HAL Layer Drivers*/
#include "../../HAL/LCD_DRIVER/LCD_interface.h"
#include "../../HAL/LM35_DRIVER/LM35_interface.h"

#include <util/delay.h>
#include "Temp.h"

/*Global pointer to function that take void and return void*/
void (*ADC_pvCallBackNotificationFunc)(void) = NULL;

void Get_Void_ADC_Mood()
{
	if(ADC_MOOD == SYNC)
	{
		Get_Void_Temp_Sync();
	}
	else if (ADC_MOOD == ASYNCH)
	{
		Get_Void_Temp_ASync(ADC_pvCallBackNotificationFunc);
	}
	else
	{
		/*Nothing*/
	}
}


