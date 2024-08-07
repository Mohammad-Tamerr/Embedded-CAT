/*
 * Ping_Pong.h
 *
 *  Created on: Jul 3, 2024
 *      Author: Mohammad Tamer
 */


#ifndef APP_PING_PONG_PING_PONG_H_
#define APP_PING_PONG_PING_PONG_H_
#include "../../LIB/STD_TYPES.h"

/**
 * @brief Initializes the game environment.
 */
void Game_VoidIntialization();

/**
 * @brief Handles the ball movement from left to right.
 */
void Ball_VoidMovingLeftToRight();

/**
 * @brief Handles the ball movement from right to left.
 */
void Ball_VoidMovingRightToLeft();

/**
 * @brief Displays the scores of Player One and Player Two.
 * @param Player_One_u8Score_Copy The score of Player One.
 * @param Player_Two_u8Score_Copy The score of Player Two.
 */
void View_u8Score(u8 Player_One_u8Score_Copy, u8 Player_Two_u8Score_Copy);

#endif /* APP_PING_PONG_PING_PONG_H_ */
