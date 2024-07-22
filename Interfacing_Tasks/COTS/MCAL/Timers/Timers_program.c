/*
 * Timers_program.c
 *
 *  Created on: Jul 19, 2024
 *      Author: Mohammad Tamer
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "Timers_interface.h"
#include "Timers_private.h"
#include "Timers_register.h"

/* Array of pointers to functions (void-void) */
static void (*TIMER_pvCallBackFunc[8])(void) = {NULL};

u8 TIMER0_u8Init(u8 Copy_u8WaveMode , u8 Copy_u8CompereMode ,u8 Copy_u8Prescaler)
{
	u8 Local_u8ErrorState = OK;

	switch (Copy_u8WaveMode)
	{
		case NORMAL:
			CLR_BIT(TCCR0, TCCR0_WGM00);
			CLR_BIT(TCCR0, TCCR0_WGM01);
			SET_BIT(TIMSK, TIMSK_TOIE0);
			break;
		case PHASE_CORRECT:
			SET_BIT(TCCR0, TCCR0_WGM00);
			CLR_BIT(TCCR0, TCCR0_WGM01);
			break;
		case CTC:
			CLR_BIT(TCCR0, TCCR0_WGM00);
			SET_BIT(TCCR0, TCCR0_WGM01);
			SET_BIT(TIMSK, TIMSK_OCIE0);
			break;
		case FAST_PWM:
			SET_BIT(TCCR0, TCCR0_WGM00);
			SET_BIT(TCCR0, TCCR0_WGM01);
			break;
		default:
			Local_u8ErrorState = NOK;
	}

	/* Set Output compare mode */
	TCCR0 &= TIMER0_COM_MASK;  			// Clear bits 4 and 5
	TCCR0 |= (Copy_u8CompereMode << 4);  // Set bits 4 and 5 to the desired compare mode

	/* Set prescaler */
	(TCCR0) &= (TIMER_PRESCALER_MASK);
	(TCCR0) |= (Copy_u8Prescaler);

	return Local_u8ErrorState;
}

void TIMER0_voidSetCompMatchVal(u8 Copy_u8Value)
{
	OCR0 = Copy_u8Value;
}

u8 TIMER_u8SetCallBack(u8 Copy_u8INT_ID, void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if (Copy_pvCallBackFunc != NULL)
	{
		TIMER_pvCallBackFunc[Copy_u8INT_ID] = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if (TIMER_pvCallBackFunc[TIMER0_OUTPUT_COM_INT] != NULL)
	{
		TIMER_pvCallBackFunc[TIMER0_OUTPUT_COM_INT]();
	}
}

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	if (TIMER_pvCallBackFunc[TIMER0_OVERFLOW_INT] != NULL)
	{
		TIMER_pvCallBackFunc[TIMER0_OVERFLOW_INT]();
	}
}
