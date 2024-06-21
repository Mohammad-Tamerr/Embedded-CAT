/*
 * EXI_interface.h
 *
 *  Created on: Jun 20, 2024
 *      Author: Mohammad Tamer
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_EXI_INTERFACE_H_
#define MCAL_EXTERNAL_INTERRUPT_EXI_INTERFACE_H_

void EXI_voidInt0Init(void);

void EXI_voidInt1Init(void);

void EXI_voidInt2Init(void);

u8 EXI_SetSenseControl(u8 Pin_Copy ,u8 Sense_Copy);

u8 EXI_IntEnable(u8 Int_Copy);

u8 EXI_IntDisable(u8 Int_Copy);

u8 EXI_SetCallBackINT0(void (*Copy_PInt0Func)(void));

u8 EXI_SetCallBackINT1(void (*Copy_PInt1Func)(void));

u8 EXI_SetCallBackINT2(void (*Copy_PInt2Func)(void));



#endif /* MCAL_EXTERNAL_INTERRUPT_EXI_INTERFACE_H_ */
