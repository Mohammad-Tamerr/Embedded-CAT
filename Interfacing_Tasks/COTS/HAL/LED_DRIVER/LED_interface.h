/*
 * LED_interface.h
 *
 *  Created on: Mar 8, 2024
 *      Author: dell
 */

#ifndef HAL_LED_DRIVER_LED_INTERFACE_H_
#define HAL_LED_DRIVER_LED_INTERFACE_H_

u8 LED_ON (u8 copy_port , u8 copy_pin);

u8 LED_OFF (u8 copy_port , u8 copy_pin);

u8 LED_ALL_PORT_ON (u8 copy_port);

u8 LED_ALL_PORT_OFF (u8 copy_port);


#endif /* HAL_LED_DRIVER_LED_INTERFACE_H_ */
