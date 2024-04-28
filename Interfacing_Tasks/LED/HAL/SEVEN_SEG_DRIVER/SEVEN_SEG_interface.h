/*
 * SEVEN_SEG_interface.h
 *
 *  	Created on: Mar 8, 2024
 *      Author: Mohammad Tamer
 */

#ifndef HAL_SEVEN_SEG_DRIVER_SEVEN_SEG_INTERFACE_H_
#define HAL_SEVEN_SEG_DRIVER_SEVEN_SEG_INTERFACE_H_


u8 Seven_Seg_Init (u8 port_copy);
u8 Seven_Seg_TurnON (u8 port_copy, u8 Number , u8 type);
u8 Seven_Seg_TurnOff (u8 port_copy , u8 type);
u8 Seven_Seg_CountUp (u8 port_copy ,u8 Number, u8 type);
u8 Seven_Seg_Countdown (u8 port_copy,u8 Number ,u8 type);

#endif /* HAL_SEVEN_SEG_DRIVER_SEVEN_SEG_INTERFACE_H_ */
