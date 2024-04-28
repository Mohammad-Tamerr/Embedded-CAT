/*
 * DIO_interface.h
 *
 *      Created on: Mar 8, 2024
 *      Author: Mohammad Tamer
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

#define DIO_PIN_OUTPUT		1
#define DIO_PIN_INPUT		0

#define DIO_PIN_HIGH		1
#define DIO_PIN_LOW			0

#define DIO_PORT_OUTPUT		0XFF
#define DIO_PPRT_INPUT		0

#define DIO_PORT_HIGH		0XFF
#define DIO_PPRT_LOW		0

#define DIO_PORT_A			0
#define DIO_PORT_B			1
#define DIO_PORT_C			2
#define DIO_PORT_D			3

#define DIO_PIN_0			0
#define DIO_PIN_1			1
#define DIO_PIN_2			2
#define DIO_PIN_3			3
#define DIO_PIN_4			4
#define DIO_PIN_5			5
#define DIO_PIN_6			6
#define DIO_PIN_7			7



u8 DIO_Set_Pin_Direction(u8 port_copy , u8 pin_copy , u8 direction_copy );

u8 DIO_Set_Port_Direction(u8 port_copy , u8 direction_copy );

u8 DIO_Set_Pin_Value(u8 port_copy , u8 pin_copy , u8  value_copy );

u8 DIO_Set_Port_Value(u8 port_copy  , u8 value_copy  );

u8 DIO_Get_Pin_VALUE(u8 port_copy , u8 pin_copy , u8* Pin_Value );


#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
