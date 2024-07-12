/*
 * LM35_program.c
 *
 *  Created on: Jul 12, 2024
 *      Author: Mohammad Tamer
 */
/*Including Libraries*/
#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
/*Including upper layers*/
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/PORT/PORT_interface.h"
#include "../../MCAL/ADC/ADC_interface.h"
#include "../../HAL/LCD_DRIVER/LCD_interface.h"
/**/
#include "LM35_config.h"
#include "LM35_interface.h"
#include "LM35_private.h"

#include <util/delay.h>

/*Constant message to show on LCD*/
#define		MESSAGE		"Temperature: "

/*Global variable to hold the ADC reading value*/
u16 ADC_READING_VALUE;

/*Global pointer to function that take void and return void*/
void (*ADCpvCallBackNotificationFunc)(void) = NULL;

void Get_Void_Temp_Sync()
{
		/*Initialize ADC_READING_VALUE with not null value*/
		ADC_READING_VALUE = 1 ;
		/*Start synchronous ADC conversion*/
		ADC_u8StartConversionSynch(ADC_CHANNEL, &ADC_READING_VALUE);
		/*show the message on LCD*/
        lcd_send_string(MESSAGE);
        /*Get ADC reading*/
        u16 Millivolt = (u16)((u32)(ADC_READING_VALUE) * 5000UL / 1024);
        /*Convert millivolt to Celsius*/
        u16 Temp = (Millivolt / 10);
        lcd_go_to_xy(0, 13);
        /*show Temperature on LCD*/
        lcd_show_number(Temp);
        _delay_ms(500);
        lcd_clear();
}

void Get_Void_Temp_ASync(void (*Copy_pvNotificationFunc)(void))
{
    /*Assign the callback function to the global variable*/
	Copy_pvNotificationFunc = Get_Void_Temp_ASync_Handle ;
	/*Make ADCpvCallBackNotificationFunc point to Copy_pvNotificationFunc(ISR)*/
	ADCpvCallBackNotificationFunc = Copy_pvNotificationFunc;

	/*Initialize ADC_READING_VALUE with not null value*/
    ADC_READING_VALUE = 1 ;
    /*Start asynchronous ADC conversion*/
    ADC_u8StartConversionAsynch(ADC_CHANNEL, &ADC_READING_VALUE, ADCpvCallBackNotificationFunc);
}


void Get_Void_Temp_ASync_Handle()
{
	/*show the message on LCD*/
    lcd_send_string(MESSAGE);
    /*Get ADC reading*/
    u16 Millivolt = (u16)((u32)(ADC_READING_VALUE) * 5000UL / 1024);
    /*Convert millivolt to Celsius*/
    u16 Temp = (Millivolt / 10);
    lcd_go_to_xy(0, 13);
    /*show Temperature on LCD*/
    lcd_show_number(Temp);
    _delay_ms(500);
    lcd_clear();
}


