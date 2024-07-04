/*
 * EXI_program.c
 *
 *  Created on: Jun 20, 2024
 *      Author: Mohammad Tamer
 */


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "EXI_config.h"
#include "EXI_interface.h"
#include "EXI_private.h"
#include "EXI_register.h"

void (*PInt0Func)(void) = NULL ;
void (*PInt1Func)(void) = NULL ;
void (*PInt2Func)(void) = NULL ;

void EXI_voidInt0Init(void)
{
	/*check sense control*/
#if INT0_SENSE == low_level
		CLR_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENSE == falling_edge
		CLR_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENSE == rising_edge
		SET_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENSE == on_change
		SET_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);

#else
#error "Wrong INT0_SENSE configuration option"

#endif
		/*peripheral interrupt enable for int0 */
#if INT0_INITIAL_STATE == ENABLED
		SET_BIT(GICR,GICR_INT0);

#elif INT0_INITIAL_STATE == DISABLED
		CLR_BIT(GICR,GICR_INT0);

#else
#error "Wrong INT0_INITIAL_STATE option"

#endif
}

void EXI_voidInt1Init(void)
{
	/*check sense control*/
#if INT1_SENSE == low_level
		CLR_BIT(MCUCR,MCUCR_ISC11);
		CLR_BIT(MCUCR,MCUCR_ISC10);

#elif INT1_SENSE == falling_edge
		CLR_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);

#elif INT1_SENSE == rising_edge
		SET_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);

#elif INT1_SENSE == on_change
		SET_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);

#else
#error "Wrong INT0_SENSE configuration option"

#endif
		/*peripheral interrupt enable for int1 */
#if INT1_INITIAL_STATE == ENABLED
		SET_BIT(GICR,GICR_INT1);

#elif INT1_INITIAL_STATE == DISABLED
		CLR_BIT(GICR,GICR_INT1);

#else
#error "Wrong INT0_INITIAL_STATE option"

#endif
}

void EXI_voidInt2Init(void)
{
#if INT2_SENSE == falling_edge
	CLR_BIT(MCUCSR,MCUCSR_INT2);
#elif INT2_SENSE == rising_edge
	SET_BIT(MCUCSR,MCUCSR_INT2);
#else
#error "Wrong INT0_SENSE configuration option"
#endif

	/*peripheral interrupt enable for int2 */
#if INT2_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT2);
#elif INT2_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT2);
#else
#error "Wrong INT1_INITIAL_STATE option"
#endif
}

u8 EXI_SetSenseControl(u8 Pin_Copy ,u8 Sense_Copy)
{
	u8 Local_Error_Status = OK ;
	switch(Pin_Copy)
	{
	/* PIN INT0 */
		case GICR_INT0:
			switch(Sense_Copy)
			{
				case  low_level:
					CLR_BIT(MCUCR,MCUCR_ISC00);
					CLR_BIT(MCUCR,MCUCR_ISC01);
					break;
				case falling_edge:
					CLR_BIT(MCUCR,MCUCR_ISC00);
					SET_BIT(MCUCR,MCUCR_ISC01);
					break;
				case rising_edge:
					SET_BIT(MCUCR,MCUCR_ISC00);
					SET_BIT(MCUCR,MCUCR_ISC01);
					break;
				case on_change:
					SET_BIT(MCUCR,MCUCR_ISC00);
					CLR_BIT(MCUCR,MCUCR_ISC01);
					break;
				default: Local_Error_Status = NOK ;
				break;
			}
			break ;

			/*PIN INT1*/
			case GICR_INT1:
				switch(Sense_Copy)
				{
					case  low_level:
						CLR_BIT(MCUCR,MCUCR_ISC11);
						CLR_BIT(MCUCR,MCUCR_ISC10);
						break;
					case falling_edge:
						CLR_BIT(MCUCR,MCUCR_ISC10);
						SET_BIT(MCUCR,MCUCR_ISC11);
						break;
					case rising_edge:
						SET_BIT(MCUCR,MCUCR_ISC10);
						SET_BIT(MCUCR,MCUCR_ISC11);
						break;
					case on_change:
						SET_BIT(MCUCR,MCUCR_ISC10);
						CLR_BIT(MCUCR,MCUCR_ISC11);
						break;
					default: Local_Error_Status = NOK ;
				}
				break;
				/*PIN INT2*/
				case GICR_INT2:
					switch(Sense_Copy)
					{
						case falling_edge:
							CLR_BIT(MCUCSR,MCUCSR_INT2);
							break;
						case rising_edge:
							SET_BIT(MCUCSR,MCUCSR_INT2);
							break;
						default: Local_Error_Status = NOK ;
					}
					break;
	}
	return Local_Error_Status ;
}

u8 EXI_IntEnable(u8 Int_Copy)
{
	u8 Local_Error_Status = OK ;

	switch (Int_Copy)
	{
		case GICR_INT0 :
			SET_BIT(GICR,GICR_INT0);
			break;
		case GICR_INT1 :
			SET_BIT(GICR,GICR_INT1);
			break;
		case GICR_INT2 :
			SET_BIT(GICR,GICR_INT2);
			break;
		default : Local_Error_Status = NOK ;
	}

	return Local_Error_Status ;
}

u8 EXI_IntDisable(u8 Int_Copy)
{
	u8 Local_Error_Status = OK ;

	switch (Int_Copy)
	{
		case GICR_INT0 :
			CLR_BIT(GICR,GICR_INT0);
			break;
		case GICR_INT1 :
			CLR_BIT(GICR,GICR_INT1);
			break;
		case GICR_INT2 :
			CLR_BIT(GICR,GICR_INT2);
			break;
		default : Local_Error_Status = NOK ;
	}

	return Local_Error_Status ;
}

/*call back for INT0*/

u8 EXI_SetCallBackINT0(void (*Copy_PInt0Func)(void))
{
	u8 Local_Error_Status = OK ;
	if(Copy_PInt0Func != NULL)
	{
		PInt0Func = Copy_PInt0Func ;
	}
	else
	{
		Local_Error_Status = NOK ;
	}
	return Local_Error_Status ;
}

/* ISR Of INT0 */
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if(PInt0Func != NULL)
	{
		PInt0Func();
	}
	else
	{
		/*NOTHING*/
	}
}

/*call back for INT1*/
u8 EXI_SetCallBackINT1(void (*Copy_PInt1Func)(void))
{
	u8 Local_Error_Status = OK ;
	if(Copy_PInt1Func != NULL)
	{
		PInt1Func = Copy_PInt1Func ;
	}
	else
	{
		Local_Error_Status = NOK ;
	}
	return Local_Error_Status ;
}

/* ISR Of INT1 */
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if(PInt1Func != NULL)
	{
		PInt1Func();
	}
	else
	{
		/*NOTHING*/
	}
}

/*call back for INT2*/
u8 EXI_SetCallBackINT2(void (*Copy_PInt2Func)(void))
{
	u8 Local_Error_Status = OK ;
	if(Copy_PInt2Func != NULL)
	{
		PInt2Func = Copy_PInt2Func ;
	}
	else
	{
		Local_Error_Status = NOK ;
	}
	return Local_Error_Status ;
}

/* ISR Of INT2 */
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if(PInt2Func != NULL)
	{
		PInt2Func();
	}
	else
	{
		/*NOTHING*/
	}
}
