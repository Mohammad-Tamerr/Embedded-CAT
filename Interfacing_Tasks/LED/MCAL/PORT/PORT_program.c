/*
 * PORT_program.c
 *
 *  Created on: Apr 23, 2024
 *      Author: Mohammad Tamer
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "PORT_config.h"
#include "PORT_private.h"
#include "PORT_interface.h"
#include "PORT_register.h"

void port_void_init(void)
{
		DDR_A=PORTA_DIR;
		DDR_B=PORTB_DIR;
		DDR_C=PORTC_DIR;
		DDR_D=PORTD_DIR;

		PORT_A=PORTA_INIT_VALUE;
		PORT_B=PORTB_INIT_VALUE;
		PORT_C=PORTD_INIT_VALUE;
		PORT_D=PORTC_INIT_VALUE;
}
