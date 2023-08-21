/*
 * LCD_private.h
 *
 *  Created on: Aug 13, 2023
 *      Author: yosse
 */

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_


#define LCD_U8DDRAM_OFFSET						0x80

#define LCD_U8_4BITMODE_CONFIG					0x00
#define LCD_U8_8BITMODE_CONFIG					0x10

#define LCD_U8_1Line_CONFIG						0x00
#define LCD_U8_2Line_CONFIG						0x08

#define LCD_U8_FONT_5x7_CONFIG					0x00
#define LCD_U8_FONT_5x10_CONFIG					0x04


#define LCD_U8DISPLAY_OFF						0x00
#define LCD_U8DISPLAY_ON 						0x04


#define LCD_U8NOTDISPLAY_CUR					0x00
#define LCD_U8DISPLAY_CUR						0x02


#define LCD_U8CURSOR_BLINK_OFF					0x00
#define LCD_U8CURSOR_BLINK_ON					0x01

#define LCD_U8Cursor_AutoMOV_RIGHT				0x02
#define LCD_U8Cursor_AutoMOV_LEFT				0x00

#define LCD_U8_AutoShift_OFF					0x00
#define LCD_U8_AutoShift_ON						0x01


#define LCD_u8ClEAR_DISPLAY						0x01
#define LCD_u8ReturnHome						0x02

#define LCD_u8SHIFT_CUR_RIGHT					0x10
#define LCD_u8SHIFT_CUR_LEFT					0x14

#define LCD_u8SHIFTALL_RIGHT					0x18
#define LCD_u8SHIFTALL_LEFT						0x1C


#define LCD_u8ENTRYMODE_SET					((0x04 | LCD_U8_AutoMov_Select | LCD_U8_AutoShift_Select))

#define LCD_u8DISPLAY_ON_OFF_SET			((0x08 | LCD_U8DISPLAY_Select | LCD_U8CURSOR_Select | LCD_U8Blink_Select))

#define LCD_u8FUNCTION_SET					((0x20 |LCD_U8_DataLen_Select | LCD_U8_NoOfLines_Select | LCD_U8_FONT_Select))





#endif /* HAL_LCD_LCD_PRIVATE_H_ */
