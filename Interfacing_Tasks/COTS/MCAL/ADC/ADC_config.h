/*
 * ADC_config.h
 *
 *  Created on: Jul 1, 2024
 *      Author: Mohammad Tamer
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_

/*Select the reference voltage for ADC :
*	Options :  	1-AREF
*			   	2-AVCC
*			   	3-INTERNAL_VOLT
*/
#define ADC_REF_VOLT	AREF

/*ADC enable/disable
 *Options : 1-ENABLED
 *			2-DISABLED
 */
#define ADC_ENABLE_Status				ENABLED

/*ADC prescaler selection :
 * Option : 1. DIV_BY_2
 * 			2. DIV_BY_4
 * 			3. DIV_BY_8
 * 			4. DIV_BY_16
 * 			5. DIV_BY_32
 * 			6. DIV_BY_64
 * 			7. DIV_BY_128
 * 			*/
#define ADC_PRESCALER			DIV_BY_128


/*ADC resolution:
 *Options : 1- EIGHT_BITS
 *			2- TEN_BITS
 */
#define ADC_RESOLUTION			TEN_BITS

/*ADC trigger enable/disable
 *Options : 1. ENABLED
 *			2. DISABLED
 *			*/
#define ADC_AUTO_TRIGGER_EN		ENABLED

/*ADC interrupt enable/disable
 *Options : 1. ENABLED
 *			2. DISABLED
 */

#define ADC_INT_EN				ENABLED

/*Select trigger source :
 * Options : 1. FREE_RUN
* 			 2. ANALOG_COMP
* 			 3. EXTI
* 			 4. TIMER0_COMP
* 			 5. TIMER0_OVERFLOW
* 			 6. TIMER1_COMP
* 			 7. TIMER1_OVERFLOW
* 			 8. TIMER1_EVENT_CAPT
*/
#define ADC_TRIGGER_SRC			EXTI

#define ADC_u32TIME_OUT			50000

#endif /* MCAL_ADC_ADC_CONFIG_H_ */
