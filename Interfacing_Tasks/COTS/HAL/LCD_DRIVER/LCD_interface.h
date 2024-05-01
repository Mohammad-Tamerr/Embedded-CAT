/*
 * LCD_interface.h
 *
 *  Created on: Apr 21, 2024
 *      Author: Mohammad Tamer
 */

#ifndef HAL_LCD_DRIVER_LCD_INTERFACE_H_
#define HAL_LCD_DRIVER_LCD_INTERFACE_H_

void lcd_send_command (u8 command_copy);

void lcd_send_data (u8 data_copy);

void lcd_initialization (void);

u8 lcd_send_string (const char* string_copy);

u8 lcd_go_to_xy (u8 x_dimension_copy , u8 y_dimension_copy);

u8 lcd_store_special_character  (u8* pattern_copy, u8 location_number);

void lcd_show_special_character (u8 location_number,u8 x_dimension_copy, u8 y_dimension_copy);

void lcd_show_number(s32 number_copy);

void lcd_show_float(float number);

void lcd_clear (void);

#endif /* HAL_LCD_DRIVER_LCD_INTERFACE_H_ */
