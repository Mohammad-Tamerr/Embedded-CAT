///*
// * ping_pong.c
// *
// *  Created on: Jul 3, 2024
// *      Author: Mohammad Tamer
// */
//
//#include "Ping_Pong.h"
//#include <util/delay.h>
//
//#include "../../LIB/STD_TYPES.h"
//#include "../../LIB/BIT_MATH.h"
//
///*Including MCAL Layer Drivers*/
//#include "../../MCAL/DIO/DIO_interface.h"
//#include "../../MCAL/PORT/PORT_interface.h"
//#include "../../MCAL/External_Interrupt/EXI_interface.h"
//#include "../../MCAL/GIE/GIE_interface.h"
//
///*Including HAL Layer Drivers*/
//#include "../../HAL/LCD_DRIVER/LCD_interface.h"
//#include "../../HAL/SWITCH_DRIVER/SWITCH_inerface.h"
//
//#include "Ping_Pong.h"
//#include <util/delay.h>
//
//#define		END_GAME_MESSAGE_ONE	"Player One Is"
//#define		END_GAME_MESSAGE_TWO	"Player Two Is"
//#define		WINNING_MESSAGE			"The Winner"
//
//u8 Player_One_Counter = 0 ;
//u8 Player_Two_Counter = 0 ;
//
//void INT0_ISR (void);
//void INT1_ISR (void);
//
//void main (void)
//{
//		PORT_voidInit();
//		Game_VoidIntialization();
//		EXI_voidInt0Init();
//
//		/*Initialize Sense control of Int0 */
//		EXI_voidInt0Init();
//		/*Initialize Sense control of Int1 */
//		EXI_voidInt1Init();
//
//		/*Enable global interrupt*/
//		GIE_Enable();
//
//		/*Enable Int0 pin specific interrupt*/
//		EXI_IntEnable(6);
//		/*Enable Int1 pin specific interrupt*/
//		EXI_IntEnable(7);
//
//	while(1)
//	{
//		if(Player_One_Counter > Player_Two_Counter)
//		{
//			View_u8Score(Player_One_Counter , Player_Two_Counter);
//			lcd_go_to_xy(0,2);
//			lcd_send_string(END_GAME_MESSAGE_ONE);
//			lcd_go_to_xy(1,4);
//			lcd_send_string(WINNING_MESSAGE);
//			_delay_ms(2000);
//			lcd_clear();
//			break;
//		}
//		else if (Player_One_Counter < Player_Two_Counter)
//		{
//			View_u8Score(Player_One_Counter , Player_Two_Counter);
//			lcd_go_to_xy(0,2);
//			lcd_send_string(END_GAME_MESSAGE_TWO);
//			lcd_go_to_xy(1,4);
//			lcd_send_string(WINNING_MESSAGE);
//			lcd_clear();
//			_delay_ms(2000);
//			break;
//		}
//		else
//		{
//			View_u8Score(Player_One_Counter , Player_Two_Counter);
//			lcd_clear();
//			_delay_ms(1000);
//		}
//
//		/*Call CallBack Function for INT0*/
//		EXI_SetCallBackINT0(INT0_ISR);
//		/*Call CallBack Fun for INT1*/
//		EXI_SetCallBackINT1(INT1_ISR);
//	}
//}
//
//void INT0_ISR (void)
//{
//	Ball_VoidMovingLeftToRight();
//	Player_One_Counter = Player_One_Counter + 1 ;
//}
//
//void INT1_ISR (void)
//{
//	Ball_VoidMovingRightToLeft();
//	Player_Two_Counter = Player_Two_Counter + 1 ;
//}
