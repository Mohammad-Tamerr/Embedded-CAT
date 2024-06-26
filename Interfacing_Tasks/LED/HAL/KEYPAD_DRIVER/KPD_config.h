/*
 * KPD_config.h
 *
 *  Created on: Apr 23, 2024
 *      Author: Mohammad Tamer
 */

#ifndef HAL_KEYPAD_DRIVER_KPD_CONFIG_H_
#define HAL_KEYPAD_DRIVER_KPD_CONFIG_H_

#define KPD_PORT        		DIO_PORT_A

#define KPD_COLUMN0_PIN       	DIO_PIN_0
#define KPD_COLUMN1_PIN       	DIO_PIN_1
#define KPD_COLUMN2_PIN       	DIO_PIN_2
#define KPD_COLUMN3_PIN       	DIO_PIN_3

#define KPD_ROW0_PIN       		DIO_PIN_4
#define KPD_ROW1_PIN       		DIO_PIN_5
#define KPD_ROW2_PIN       		DIO_PIN_6
#define KPD_ROW3_PIN       		DIO_PIN_7

#define KPD_NO_PREESED_KEY      0xff

#define KPD_ARR_VALUE   {{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'#','0','=','+'}}


#endif /* HAL_KEYPAD_DRIVER_KPD_CONFIG_H_ */
