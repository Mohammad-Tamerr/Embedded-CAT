/*
 * Timers_register.h
 *
 *  Created on: Jul 19, 2024
 *      Author: Mohammad Tamer
 */

#ifndef MCAL_TIMERS_TIMERS_REGISTER_H_
#define MCAL_TIMERS_TIMERS_REGISTER_H_

/* Timer/Counter Control register */
#define 	TCCR0			*((volatile u8*)0x53)
#define 	TCCR0_FOC0			7  /* Bit 7 */
#define 	TCCR0_WGM00			6  /* Bit 6 */
#define 	TCCR0_WGM01			3  /* Bit 3 */
#define 	TCCR0_COM01 		5  /* Bit 5 */
#define 	TCCR0_COM00			4  /* Bit 4 */
#define 	TCCR0_CS02			2  /* Bit 2 */
#define 	TCCR0_CS01			1  /* Bit 1 */
#define 	TCCR0_CS00			0  /* Bit 0 */

/* Timer/Counter Register */
#define 	TCNT0			*((volatile u8*)0x52)

/* Output Compare Register */
#define 	OCR0			*((volatile u8*)0x5C)

/* Timer/Counter Interrupt Mask Register */
#define 	TIMSK			*((volatile u8*)0x59)
#define 	TIMSK_OCIE0 		1	/* Bit 1 */
#define 	TIMSK_TOIE0			0	/* Bit 0 */

/* Timer/Counter Interrupt Flag Register */
#define  	TIFR			*((volatile u8*)0x58)
#define 	TIFR_OCF0			1	/* Bit 1 */
#define		TIFR_TOV0			0	/* Bit 0 */

#endif /* MCAL_TIMERS_TIMERS_REGISTER_H_ */
