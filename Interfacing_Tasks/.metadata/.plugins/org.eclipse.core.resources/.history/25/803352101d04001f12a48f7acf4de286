/*
 * KPD_program.c
 *
 *  Created on: Apr 23, 2024
 *      Author: Mohammad Tamer
 */

#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_private.h"

#include <util/delay.h>


u8 KPD_GetPressedkey(void)
{
	u8 Local_Pressed_Key = KPD_NO_PREESED_KEY;
	u8 Local_ColumnIndex;
	u8 Local_RowIndex;
	u8 Local_PinState;

	static u8 Local_KPDArr[4][4] = KPD_ARR_VALUE;
	static u8 Local_KPDColumnArr[COLUMN_NUM]={KPD_COLUMN0_PIN,KPD_COLUMN1_PIN,KPD_COLUMN2_PIN,KPD_COLUMN3_PIN};
	static u8 Local_KPDROWSArr[ROW_NUM]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};

	for(Local_ColumnIndex=0;Local_ColumnIndex<COLUMN_NUM;Local_ColumnIndex++)
		{
			/*Activate current column*/
			DIO_Set_Pin_Value(KPD_PORT,Local_KPDColumnArr[Local_ColumnIndex],DIO_PIN_LOW);

			for(Local_RowIndex=0;Local_RowIndex<ROW_NUM;Local_RowIndex++)
			{
				/*Read the current row*/
				DIO_Get_Pin_Value(KPD_PORT,Local_KPDROWSArr[Local_RowIndex],&Local_PinState);

				/*check if switch is pressed*/
				if(DIO_PIN_LOW==Local_PinState)
				{
					Local_Pressed_Key=Local_KPDArr[Local_RowIndex][Local_ColumnIndex];

					/*poling(busy waiting) until the key is released*/
					while(DIO_PIN_LOW==Local_PinState)
					{
						DIO_Get_Pin_Value(KPD_PORT,Local_KPDROWSArr[Local_RowIndex],&Local_PinState);
					}
					return Local_Pressed_Key;
				}
			}
			/*Deactivate current column*/
			DIO_Set_Pin_Value(KPD_PORT,Local_KPDColumnArr[Local_ColumnIndex],DIO_PIN_HIGH);
		}

	return Local_Pressed_Key;
}
