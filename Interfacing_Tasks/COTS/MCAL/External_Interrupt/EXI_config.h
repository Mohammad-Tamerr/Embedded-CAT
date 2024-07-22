/*
 * EXI_config.h
 *
 *  Created on: Jun 20, 2024
 *      Author: Mohammad Tamer
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_EXI_CONFIG_H_
#define MCAL_EXTERNAL_INTERRUPT_EXI_CONFIG_H_


#define     low_level        1
#define		on_change        2
#define		falling_edge     3
#define		rising_edge      4


#define     ENABLED          1
#define     DISABLED         2

/* Options:
		 1- low_level
		 2- on_change
		 3- falling_edge
		 4- rising_edge
*/
#define INT0_SENSE   falling_edge

/* Options:
		 1- ENABLED
		 2- DISABLED
*/

#define INT0_INITIAL_STATE  ENABLED

/* Options:
		 1- low_level
		 2- on_change
		 3- falling_edge
		 4- rising_edge
*/
#define INT1_SENSE   falling_edge

/* Options:
		 1- ENABLED
		 2- DISABLED
*/

#define INT1_INITIAL_STATE  ENABLED

/* Options:
		 1- falling_edge
		 2- rising_edge
*/
#define INT2_SENSE   falling_edge

/* Options:
		 1- ENABLED
		 2- DISABLED
*/

#define INT2_INITIAL_STATE  ENABLED

#endif /* MCAL_EXTERNAL_INTERRUPT_EXI_CONFIG_H_ */
