/*
 * Temp.h
 *
 *  Created on: Jul 12, 2024
 *      Author: Mohammad Tamer
 */

#ifndef APP_TEMP_TEMP_H_
#define APP_TEMP_TEMP_H_

/*ADC Mood Selection*/
#define SYNC		0
#define ASYNCH		1

/*Select the the mood for ADC :
*	Options :  	1-SYNC
*			   	2-ASYNCH
*/
#define ADC_MOOD	SYNC

/**
 * @brief Retrieve the void temperature based on the ADC mode.
 * If the ADC mode is synchronous, it retrieves the temperature synchronously.
 * If the ADC mode is asynchronous, it retrieves the temperature asynchronously with a callback.
 * @return None.
 */
void Get_Void_ADC_Mood();

#endif /* APP_TEMP_TEMP_H_ */
