/*
 * LCD_config.h
 *
 *  Created on: Aug 13, 2023
 *      Author: yosse
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_


/*********************Function Set Config Section***************/
/**
 * Options:
 * 			LCD_U8_4BITMODE_CONFIG -> 0x00
 * 			LCD_U8_8BITMODE_CONFIG -> 0x10
 */
#define LCD_U8_DataLen_Select				LCD_U8_8BITMODE_CONFIG
/**
 * Options:
 * 			LCD_U8_1Line_CONFIG -> 0x00
 * 			LCD_U8_2Line_CONFIG -> 0x08
 */
#define LCD_U8_NoOfLines_Select				LCD_U8_2Line_CONFIG

/**
 * Options:
 * 			LCD_U8_FONT_5x7_CONFIG -> 0x00
 * 			LCD_U8_FONT_5x10_CONFIG -> 0x04
 */
#define LCD_U8_FONT_Select					LCD_U8_FONT_5x7_CONFIG



/***************Display on\off  config section ********************/

/**
 * options:
 * 			LCD_U8DISPLAY_OFF
 * 			LCD_U8DISPLAY_ON
 */
#define LCD_U8DISPLAY_Select	LCD_U8DISPLAY_ON

/**
 * options:
 * 			LCD_U8NOTDISPLAY_CUR
 * 			LCD_U8DISPLAY_CUR
 */
#define LCD_U8CURSOR_Select		LCD_U8NOTDISPLAY_CUR

/**
 * options:
 * 			LCD_U8CURSOR_BLINK_OFF
 * 			LCD_U8CURSOR_BLINK_ON
 *
 */
#define LCD_U8Blink_Select		LCD_U8CURSOR_BLINK_OFF


/***************Entry Mode Set ********************/



/**
 * options:
 * 			LCD_U8Cursor_AutoMOV_LEFT
 * 			LCD_U8Cursor_AutoMOV_RIGHT
 */
#define LCD_U8_AutoMov_Select	LCD_U8Cursor_AutoMOV_RIGHT




/**
 * options:
 * 			LCD_U8_AutoShift_OFF
 * 			LCD_U8_AutoShift_ON
 */
#define LCD_U8_AutoShift_Select		LCD_U8_AutoShift_OFF










#endif /* HAL_LCD_LCD_CONFIG_H_ */
