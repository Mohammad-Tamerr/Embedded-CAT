/*
 * ADC_interface.h
 *
 *  Created on: Jul 1, 2024
 *      Author: Mohammad Tamer
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

/**
 * @brief Initialize the ADC.
 */
void ADC_voidInit(void);

/**
 * @brief Start synchronous ADC conversion on the given channel.
 * @param Copy_u8Channel The ADC channel to convert.
 * @param Copy_p16Reading Pointer to store the conversion result.
 * @return Error status (OK/NOK).
 */
u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel, u16 *Copy_p16Reading);

/**
 * @brief Start asynchronous ADC conversion on the given channel.
 * @param Copy_u8Channel The ADC channel to convert.
 * @param Copy_p16Reading Pointer to store the conversion result.
 * @param Copy_pvNotificationFunc Callback function to call after conversion.
 * @return Error status (OK/NOK).
 */
u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel, u16 *Copy_p16Reading, void (*Copy_pvNotificationFunc)(void));


#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
