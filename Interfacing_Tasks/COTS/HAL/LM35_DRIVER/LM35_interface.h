/*
 * LM35_interface.h
 *
 *  Created on: Jul 12, 2024
 *      Author: Mohammad Tamer
 */

#ifndef HAL_LM35_DRIVER_LM35_INTERFACE_H_
#define HAL_LM35_DRIVER_LM35_INTERFACE_H_

/**
 * @brief Retrieve the void temperature synchronously.
 * @return None.
 */
void Get_Void_Temp_Sync();

/**
 * @brief Retrieve the void temperature asynchronously.
 * @param Copy_pvNotificationFunc Callback function to notify completion.
 * @return None.
 */
void Get_Void_Temp_ASync(void (*Copy_pvNotificationFunc)(void));

/**
 * @brief Handle the completion of asynchronous temperature retrieval.
 * @return None.
 */
void Get_Void_Temp_ASync_Handle();

#endif /* HAL_LM35_DRIVER_LM35_INTERFACE_H_ */
