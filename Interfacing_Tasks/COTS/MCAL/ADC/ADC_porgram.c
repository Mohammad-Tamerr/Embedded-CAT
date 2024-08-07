/*
 * ADC_porgram.c
 *
 *  Created on: Jul 1, 2024
 *      Author: Mohammad Tamer
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "ADC_config.h"
#include "ADC_private.h"
#include "ADC_interface.h"
#include "ADC_register.h"
#include "../../HAL/LCD_DRIVER/LCD_interface.h"
#include "../../MCAL/GIE/GIE_interface.h"

static u8 ADC_u8State = IDLE;
static u16 *ADC_p16Reading;
static void (*ADC_pvCallBackNotificationFunc)(void);


void ADC_voidInit(void)
{
/* 1- Check the reference voltage for ADC*/
	#if ADC_REF_VOLT == AREF
		CLR_BIT(ADMUX,ADCMUX_REFS0);
		CLR_BIT(ADMUX,ADCMUX_REFS1);
	#elif ADC_REF_VOLT == AVCC
		SET_BIT(ADMUX,ADCMUX_REFS0);
		CLR_BIT(ADMUX,ADCMUX_REFS1);
	#elif ADC_REF_VOLT == INTERNAL_VOLT
		SET_BIT(ADMUX,ADCMUX_REFS0);
		SET_BIT(ADMUX,ADCMUX_REFS1);
	#else
		#error "Wrong ADC_REF_VOLT configuration option"
#endif


/* 2- Check ADC enable or disable*/
	#if	  ADC_ENABLE_Status == ENABLED
		  SET_BIT(ADCSRA,ADCSRA_ADEN);
	#elif ADC_ENABLE_Status == DISABLED
		  CLR_BIT(ADCSRA,ADCSRA_ADEN);
	#else
		#error "Wrong ADC_ENABLE configuration option"
#endif


/*3- Check ADC resolution*/
	#if	  ADC_RESOLUTION == EIGHT_BITS // Left Adjustment
		  SET_BIT(ADMUX,ADCMUX_ADLAR);
	#elif ADC_RESOLUTION == TEN_BITS   // Right Adjustment
		  CLR_BIT(ADMUX,ADCMUX_ADLAR);
	#else
		#error "Wrong ADC_RESOLUTION configuration option"
#endif


/*4. Check auto trigger enable*/
		#if ADC_AUTO_TRIGGER_EN == ENABLED
			SET_BIT(ADCSRA,ADCSRA_ADATE);

			/*Set ADC interrupt source*/
			SFIOR &= TRIGGER_SRC_MASK;
			SFIOR |= ADC_TRIGGER_SRC;


		#elif ADC_AUTO_TRIGGER_EN == DISABLED
			CLR_BIT(ADCSRA,ADCSRA_ADIE);
			CLR_BIT(ADCSRA,ADCSRA_ADATE);
		#else
		#error "Wrong ADC_AUTO_TRIGGER_EN configuration option"

		#endif


/* 5- Check ADC auto interrupt enable*/
	  #if   ADC_INT_EN == ENABLED
	  	    SET_BIT(ADCSRA,ADCSRA_ADIE );
	  #elif ADC_INT_EN == DISABLED
	  	    CLR_BIT(ADCSRA,ADCSRA_ADIE);
	  #else
	  	#error "Wrong ADC_RESOLUTION configuration option"
#endif


/* 6- Set selected trigger source*/
	  SFIOR &= TRIGGER_SRC_MASK;
	  SFIOR |= ADC_TRIGGER_SRC;

/* 7- Set selected PRESCALER using bit masking*/
		ADCSRA &= PRESCALING_MASK;
		ADCSRA |= ADC_PRESCALER;
}


u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel , u16 *Copy_p16Reading)
{
	u8 Local_u8Error_Status = OK ;
	u8 Local_u8Counter = 0 ;
	if(Copy_p16Reading != NULL)
	{
		if(ADC_u8State == IDLE)
		{
			/*ADC is busy for conversion*/
			ADC_u8State = BUSY;

			/*Clear MUX bits in ADMUX register */
			ADMUX &= MUX_MASK;

			/*Set the selected channel into MUX bits*/
			ADMUX |= Copy_u8Channel;

			/*Start Conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			while( ((GET_BIT(ADCSRA,ADCSRA_ADIF))==0) &&(Local_u8Counter != ADC_u32TIME_OUT))
			{
				Local_u8Counter ++ ;
			}
			if(Local_u8Counter == ADC_u32TIME_OUT) /*Loop is broken because timeout is reached*/
			{
				Local_u8Error_Status = NOK ;
			}
			else /*Loop is broken because the flag*/
			{
				/*Clear the conversion complete flag*/
				SET_BIT(ADCSRA,ADCSRA_ADIF);
				#if ADC_RESOLUTION == EIGHT_BITS
				*Copy_p16Reading = ADCH ;
				#elif ADC_RESOLUTION == TEN_BITS
				*Copy_p16Reading = ADC ;
				#else
				#error "Wrong ADC_RESOLUTION configuration option"
				#endif

				/*ADC State is idle after conversion is completed*/
				ADC_u8State = IDLE;
			}
		}
		else
		{
			/*Nothing*/
		}
	}
	else
	{
		Local_u8Error_Status = NOK ;
	}
	return Local_u8Error_Status ;
}


u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel, u16 *Copy_p16Reading, void (*Copy_pvNotificationFunc)(void) )
{
	u8 Local_u8ErrorState = OK;

	if(ADC_u8State == IDLE)
	{
		if((Copy_p16Reading == NULL) || (Copy_pvNotificationFunc == NULL))
		{
			Local_u8ErrorState = NULL_POINTER;
		}

		else
		{
			GIE_Enable();
			/*ADC is busy for conversion*/
			ADC_u8State = BUSY;

			/*Initialize Reading variable globally*/
			ADC_p16Reading = Copy_p16Reading;
			/*Initialize callback notification function globally*/
			ADC_pvCallBackNotificationFunc = Copy_pvNotificationFunc;

			/*Clear MUX bits in ADMUX register */
			ADMUX &= MUX_MASK;

			/*Set the selected channel into MUX bits*/
			ADMUX |= Copy_u8Channel;

			/*Start Conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/*ADC interrupt enable*/
			SET_BIT(ADCSRA,ADCSRA_ADIE);
		}
	}

	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}


void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{

    // Reading ADC result
    if (ADC_RESOLUTION == TEN_BITS)
    {
        *ADC_p16Reading = ADC;
    }
    else if (ADC_RESOLUTION == EIGHT_BITS)
    {
        *ADC_p16Reading = ADCH;
    }

    // ADC State is idle after conversion is completed
    ADC_u8State = IDLE;

    // Call notification function if assigned
    if (ADC_pvCallBackNotificationFunc != NULL)
    {
        ADC_pvCallBackNotificationFunc();
    }

    // Clear ADC interrupt flag
    SET_BIT(ADCSRA, ADCSRA_ADIF);
}
