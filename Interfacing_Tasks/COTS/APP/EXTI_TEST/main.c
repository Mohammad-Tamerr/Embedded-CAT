///*
// * EXTI.C
// *
// *  Created on: Jun 20, 2024
// *      Author: dell
// */
//
//#include "../../LIB/STD_TYPES.h"
//#include "../../LIB/BIT_MATH.h"
//
//#include "../../MCAL/DIO/DIO_interface.h"
//#include "../../MCAL/PORT/PORT_interface.h"
//#include "../../MCAL/External_Interrupt/EXI_interface.h"
//#include "../../MCAL/GIE/GIE_interface.h"
//
//void INT0_ISR (void);
//
//void main (void)
//{
//	PORT_voidInit();
//	EXI_voidInt0Init();
//
//	EXI_SetCallBackINT0(INT0_ISR);
//	GIE_Enable();
//	while(1)
//	{
//
//	}
//}
//
//void INT0_ISR (void)
//{
//	DIO_Set_Pin_Direction(DIO_PORT_C,DIO_PIN_0,DIO_PIN_OUTPUT);
//	DIO_Set_Pin_Value(DIO_PORT_C,DIO_PIN_0,DIO_PIN_HIGH);
//}
