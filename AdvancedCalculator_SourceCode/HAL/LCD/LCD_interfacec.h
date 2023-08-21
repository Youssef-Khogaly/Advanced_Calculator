/*
 * LCD_interfacec.h
 *
 *  Created on: Aug 13, 2023
 *      Author: yosse
 */

#ifndef HAL_LCD_LCD_INTERFACEC_H_
#define HAL_LCD_LCD_INTERFACEC_H_

/*****Macros*******/



/* LCD PORT */
#define LCD_U8PORTA		0
#define LCD_U8PORTB		1
#define LCD_U8PORTC		2
#define LCD_U8PORTD		3
/* LCD PINS */
#define LCD_U8PIN0		0
#define LCD_U8PIN1		1
#define LCD_U8PIN2		2
#define LCD_U8PIN3		3
#define LCD_U8PIN4		4
#define LCD_U8PIN5		5
#define LCD_U8PIN6		6
#define LCD_U8PIN7		7


/*lcd rows*/
#define LCD_U8ROW1		0x00
#define LCD_U8ROW2		0x40

/*lcd colums*/
#define LCD_U8COL1		0
#define LCD_U8COL2		1
#define LCD_U8COL3		2
#define LCD_U8COL4		3
#define LCD_U8COL5		4
#define LCD_U8COL6		5
#define LCD_U8COL7		6
#define LCD_U8COL8		7
#define LCD_U8COL9		8
#define LCD_U8COL10		9
#define LCD_U8COL11		10
#define LCD_U8COL12		11
#define LCD_U8COL13		12
#define LCD_U8COL14		13
#define LCD_U8COL15		14
#define LCD_U8COL16		15

/********Macro func******/







/*******User Data Types******/

typedef struct{

	u8 LCD_u8DataPort :2 ;
	u8 LCD_u8RsPort : 2;
	u8 LCD_u8RwPort : 2;
	u8 LCD_u8EnablePort : 2;
	u8 LCD_u8RsPin : 3;
	u8 LCD_u8RwPin : 3;
	u8 LCD_u8EnablePin : 3;

#if LCD_U8_DataLen_Select == LCD_U8_4BITMODE_CONFIG

	/*First pin That connected to DB4
	 * Example: if Pin3 on port connected to DB4
	 * 			DB5,DB6,B7 MUST!! BE CONNECTED TO PIN4,PIN5,PIN6 Respectively!!
	 * */
	u8 LCD_u8FirstPin : 3;
#endif
}LCD_stConfig;





/***********Interfaces******/
void LCD_voidInit(LCD_stConfig* copy_pstConfig);
void LCD_voidSendCommand(LCD_stConfig* copy_pstConfig, u8 copy_u8Command);
void LCD_voidSendChar(LCD_stConfig* copy_pstConfig , u8 copy_u8Char);
void LCD_voidSetCursor(LCD_stConfig* copy_pstConfig , u8 copy_u8Row , u8 copy_u8Colum);
void LCD_voidSendChar_Postion(LCD_stConfig* copy_pstConfig , u8 copy_u8Char , u8 copy_u8Row , u8 copy_u8Colum);

void LCD_voidSendString(LCD_stConfig* copy_pstConfig , u8* copy_pu8str);
void LCD_voidSendString_Postion(LCD_stConfig* copy_pstConfig , u8* copy_pu8str, u8 copy_u8Row , u8 copy_u8Colum);

void LCD_voidClearDisplay(LCD_stConfig* copy_pstConfig);

void LCD_voidShiftScreenLeft(LCD_stConfig* copy_pstConfig);
void LCD_voidShiftScreenRight(LCD_stConfig* copy_pstConfig);

void LCD_voidShiftCursorLeft(LCD_stConfig* copy_pstConfig);
void LCD_voidShiftCursorRight(LCD_stConfig* copy_pstConfig);

void LCD_voidSendU32Digit(LCD_stConfig* copy_pstConfig , u32 num);

void LCD_voidSendU32Digit_Postion(LCD_stConfig* copy_pstConfig , u32 num, u8 copy_u8Row , u8 copy_u8Colum);

void LCD_voidSendf32Digit(LCD_stConfig* copy_pstConfig , f32 num);
void LCD_voidSendf32Digit_Postion(LCD_stConfig* copy_pstConfig , f32 num, u8 copy_u8Row , u8 copy_u8Colum);
/****************************/

#endif /* HAL_LCD_LCD_INTERFACEC_H_ */
