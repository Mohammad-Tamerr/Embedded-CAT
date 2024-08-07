/*
 * ADC_private.h
 *
 *  Created on: Jul 1, 2024
 *      Author: Mohammad Tamer
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

/*Reference Voltage Modes */
#define    AREF          			1
#define    AVCC          			2
#define    INTERNAL_VOLT 			3

#define ENABLED			            1
#define DISABLED		            2

#define EIGHT_BITS		            1
#define TEN_BITS		            2

/*PRESCALING Modes*/
#define DIV_BY_2   		            1
#define DIV_BY_4     	            2
#define DIV_BY_8     	            3
#define DIV_BY_16     	            4
#define DIV_BY_32     	            5
#define DIV_BY_64     	            6
#define DIV_BY_128     	            7
/*This mask is used to manipulate the prescaler setting of the ADC*/
#define PRESCALING_MASK	 	        0b11111000

/* ADC Auto Trigger Source */
#define FREE_RUN		 	       ( 0  << 5 )
#define ANALOG_COMP		 	       ( 1  << 5 )
#define EXTI			 	       ( 2  << 5 )
#define TIMER0_COMP		 	       ( 3  << 5 )
#define TIMER0_OVERFLOW	 	       ( 4  << 5 )
#define TIMER1_COMP		 	       ( 5  << 5 )
#define TIMER1_OVERFLOW	 	       ( 6  << 5 )
#define TIMER1_EVENT_CAPT	       ( 7  << 5 )
/*This mask is used to select or clear the trigger source bits of the ADC*/
#define TRIGGER_SRC_MASK 	        0b00011111

/*ADC Selection MUX Channel*/
#define CHANNEL_ADC0				0b00000
#define CHANNEL_ADC1				0b00001
#define CHANNEL_ADC2				0b00010
#define CHANNEL_ADC3				0b00011
#define CHANNEL_ADC4				0b00100
#define CHANNEL_ADC5				0b00101
#define CHANNEL_ADC6				0b00110
#define CHANNEL_ADC7				0b00111
/*This mask is used for the MUX bits settings of the ADC*/
#define MUX_MASK					0b11100000

#define 	IDLE			0
#define 	BUSY			1

#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
