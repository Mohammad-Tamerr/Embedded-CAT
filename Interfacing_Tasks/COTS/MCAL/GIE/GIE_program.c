/*
 * GIE_program.c
 *
 *  Created on: Jun 20, 2024
 *      Author: Mohammad Tamer
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "GIE_interface.h"
#include "GIE_register.h"

void GIE_Enable(void)
{
	SET_BIT(SREG,SREG_I);
}

void GIE_Disable(void)
{
	CLR_BIT(SREG,SREG_I);
}
