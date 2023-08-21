/*
 * LCD_progam.c
 *
 *  Created on: Aug 13, 2023
 *      Author: yossef
 */

#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "LCD_private.h"
#include "LCD_interfacec.h"
#include "LCD_config.h"
#include <stdio.h>

#if LCD_U8_DataLen_Select == LCD_U8_8BITMODE_CONFIG
static void LCD_void8Bit_Init(LCD_stConfig* copy_pstConfig);
static void LCD_void8Bit_SendCommand(LCD_stConfig* copy_pstConfig , u8 copy_u8Command);
static void LCD_void8Bit_SendChar(LCD_stConfig* copy_pstConfig , u8 copy_u8Char);
#endif

#if LCD_U8_DataLen_Select == LCD_U8_4BITMODE_CONFIG
static void LCD_void4Bit_Init(LCD_stConfig* copy_pstConfig);
static void LCD_void4Bit_SendCommand(LCD_stConfig* copy_pstConfig , u8 copy_u8Command);
static void LCD_void4Bit_SendChar(LCD_stConfig* copy_pstConfig , u8 copy_u8Char);
#endif


void LCD_voidInit(LCD_stConfig* copy_pstConfig)
{
	if(copy_pstConfig)
	{
#if LCD_U8_DataLen_Select == LCD_U8_8BITMODE_CONFIG
		LCD_void8Bit_Init(copy_pstConfig);
#elif LCD_U8_DataLen_Select == LCD_U8_4BITMODE_CONFIG
		LCD_void4Bit_Init(copy_pstConfig);
#else
#error "Wrong LCD Configration!! Please Check LCD_config.h"
#endif
	}
	else {}

	return;
}


void LCD_voidSendCommand(LCD_stConfig* copy_pstConfig, u8 copy_u8Command)
{
	if(copy_pstConfig && copy_u8Command <=255 )
	{
#if LCD_U8_DataLen_Select == LCD_U8_8BITMODE_CONFIG
		LCD_void8Bit_SendCommand(copy_pstConfig,copy_u8Command);
#elif LCD_U8_DataLen_Select == LCD_U8_4BITMODE_CONFIG
		LCD_void4Bit_SendCommand(copy_pstConfig,copy_u8Command);
		_delay_ms(10);
#else
#error "Wrong LCD Configration!! Please Check LCD_config.h"
#endif
	}
	else
	{
		/*nothing*/
	}
	return;
}




void LCD_voidSendChar(LCD_stConfig* copy_pstConfig , u8 copy_u8Char)
{
	if(copy_pstConfig && copy_u8Char <=255)
	{
#if LCD_U8_DataLen_Select == LCD_U8_8BITMODE_CONFIG
		LCD_void8Bit_SendChar(copy_pstConfig,copy_u8Char);
#elif LCD_U8_DataLen_Select == LCD_U8_4BITMODE_CONFIG
		LCD_void4Bit_SendChar(copy_pstConfig,copy_u8Char);
#else
#error "Wrong LCD Configration!! Please Check LCD_config.h"
#endif
	}
	else
	{
		/*nothing*/
	}
	return;
}

void LCD_voidSetCursor(LCD_stConfig* copy_pstConfig , u8 copy_u8Row , u8 copy_u8Colum)
{
	if(copy_pstConfig && copy_u8Row <=LCD_U8ROW2 && copy_u8Colum <= LCD_U8COL16 )
	{
		LCD_voidSendCommand(copy_pstConfig ,  (LCD_U8DDRAM_OFFSET | (copy_u8Row + copy_u8Colum)) );
	}
	else
	{
		/*nothing*/
	}
	return;
}

void LCD_voidSendChar_Postion(LCD_stConfig* copy_pstConfig , u8 copy_u8Char , u8 copy_u8Row , u8 copy_u8Colum)
{
	LCD_voidSetCursor(copy_pstConfig,copy_u8Row,copy_u8Colum);
	LCD_voidSendChar(copy_pstConfig,copy_u8Char);
}

void LCD_voidSendString(LCD_stConfig* copy_pstConfig , u8* copy_pu8str)
{
	if(copy_pstConfig && copy_pu8str)
	{
		u8 i = 0;
		while(copy_pu8str[i])
		{
			LCD_voidSendChar(copy_pstConfig,copy_pu8str[i++]);
		}
	}
	else
	{
		/*nothing*/
	}
	return;
}
void LCD_voidSendString_Postion(LCD_stConfig* copy_pstConfig , u8* copy_pu8str, u8 copy_u8Row , u8 copy_u8Colum)
{
	LCD_voidSetCursor(copy_pstConfig,copy_u8Row,copy_u8Colum);
	LCD_voidSendString(copy_pstConfig,copy_pu8str);
}

void LCD_voidShiftScreenLeft(LCD_stConfig* copy_pstConfig)
{
	LCD_voidSendCommand(copy_pstConfig , LCD_u8SHIFTALL_LEFT);
}
void LCD_voidShiftScreenRight(LCD_stConfig* copy_pstConfig)
{
	LCD_voidSendCommand(copy_pstConfig , LCD_u8SHIFTALL_RIGHT);
}

void LCD_voidShiftCursorLeft(LCD_stConfig* copy_pstConfig)
{
	LCD_voidSendCommand(copy_pstConfig , LCD_u8SHIFT_CUR_LEFT);
}
void LCD_voidShiftCursorRight(LCD_stConfig* copy_pstConfig)
{
	LCD_voidSendCommand(copy_pstConfig , LCD_u8SHIFT_CUR_RIGHT);
}

void LCD_voidClearDisplay(LCD_stConfig* copy_pstConfig)
{
	LCD_voidSendCommand(copy_pstConfig , LCD_u8ClEAR_DISPLAY);
}

#if LCD_U8_DataLen_Select == LCD_U8_8BITMODE_CONFIG

static void LCD_void8Bit_Init(LCD_stConfig* copy_pstConfig)
{
	/* init data port direction*/
	DIO_VoidSetPortDirection(copy_pstConfig->LCD_u8DataPort, DIO_PORT_DIR_OUTPUT);
	/*set direction for rs pin*/
	DIO_VoidSetPinDirection(copy_pstConfig->LCD_u8RsPort , copy_pstConfig->LCD_u8RsPin , DIO_PIN_DIR_OUTPUT);
	/*set direction for rw pin*/
	DIO_VoidSetPinDirection(copy_pstConfig->LCD_u8RwPort , copy_pstConfig->LCD_u8RwPin , DIO_PIN_DIR_OUTPUT);
	/*set direction for Enable pin*/
	DIO_VoidSetPinDirection(copy_pstConfig->LCD_u8EnablePort , copy_pstConfig->LCD_u8EnablePin , DIO_PIN_DIR_OUTPUT);
	_delay_ms(30);
	// send function set command
	LCD_voidSendCommand(copy_pstConfig , LCD_u8FUNCTION_SET);
	_delay_ms(1);
	// send diplay on off command
	LCD_voidSendCommand(copy_pstConfig , LCD_u8DISPLAY_ON_OFF_SET);
	_delay_ms(1);
	// send clear dipslay command
	LCD_voidSendCommand(copy_pstConfig , LCD_u8ClEAR_DISPLAY);
	_delay_ms(1);
	/* send enter mode set command*/
	LCD_voidSendCommand(copy_pstConfig , LCD_u8ENTRYMODE_SET);
}

static  void LCD_void8Bit_SendCommand(LCD_stConfig* copy_pstConfig , u8 copy_u8Command)
{
	//clear RS pin &  Clear RW pin
	DIO_VoidSetPinValue(copy_pstConfig->LCD_u8RsPort , copy_pstConfig->LCD_u8RsPin , DIO_PIN_LOGIC_LOW);
	DIO_VoidSetPinValue(copy_pstConfig->LCD_u8RwPort , copy_pstConfig->LCD_u8RwPin , DIO_PIN_LOGIC_LOW);

	// write command on data pins
	DIO_VoidSetPortValue(copy_pstConfig->LCD_u8DataPort , copy_u8Command);

	// send enable signal
	DIO_VoidSetPinValue(copy_pstConfig->LCD_u8EnablePort , copy_pstConfig->LCD_u8EnablePin , DIO_PIN_LOGIC_HIGH);
	_delay_ms(1);
	DIO_VoidSetPinValue(copy_pstConfig->LCD_u8EnablePort , copy_pstConfig->LCD_u8EnablePin , DIO_PIN_LOGIC_LOW);
	_delay_ms(10);
}

static void LCD_void8Bit_SendChar(LCD_stConfig* copy_pstConfig , u8 copy_u8Char)
{
	// set RS pin &  Clear RW pin
	DIO_VoidSetPinValue(copy_pstConfig->LCD_u8RsPort , copy_pstConfig->LCD_u8RsPin , DIO_PIN_LOGIC_HIGH);
	DIO_VoidSetPinValue(copy_pstConfig->LCD_u8RwPort , copy_pstConfig->LCD_u8RwPin , DIO_PIN_LOGIC_LOW);

	DIO_VoidSetPortValue(copy_pstConfig->LCD_u8DataPort , copy_u8Char);

	// send enable signal
	DIO_VoidSetPinValue(copy_pstConfig->LCD_u8EnablePort , copy_pstConfig->LCD_u8EnablePin , DIO_PIN_LOGIC_HIGH);
	_delay_ms(1);
	DIO_VoidSetPinValue(copy_pstConfig->LCD_u8EnablePort , copy_pstConfig->LCD_u8EnablePin , DIO_PIN_LOGIC_LOW);
	return;
}


#endif

#if LCD_U8_DataLen_Select == LCD_U8_4BITMODE_CONFIG

static void LCD_void4Bit_Init(LCD_stConfig* copy_pstConfig)
{
	u8 pinsCount = copy_pstConfig->LCD_u8FirstPin;
	u8 lastpin = copy_pstConfig->LCD_u8FirstPin+4;
	// init data pins
	for(;pinsCount < lastpin ; ++pinsCount )
	{
		DIO_VoidSetPinDirection(copy_pstConfig->LCD_u8DataPort , pinsCount , DIO_PIN_DIR_OUTPUT);
	}
	/*set direction for rs pin*/
	DIO_VoidSetPinDirection(copy_pstConfig->LCD_u8RsPort , copy_pstConfig->LCD_u8RsPin , DIO_PIN_DIR_OUTPUT);
	/*set direction for rw pin*/
	DIO_VoidSetPinDirection(copy_pstConfig->LCD_u8RwPort , copy_pstConfig->LCD_u8RwPin , DIO_PIN_DIR_OUTPUT);
	/*set direction for Enable pin*/
	DIO_VoidSetPinDirection(copy_pstConfig->LCD_u8EnablePort , copy_pstConfig->LCD_u8EnablePin , DIO_PIN_DIR_OUTPUT);

	_delay_ms(30);

	// send function set command
	LCD_voidSendCommand(copy_pstConfig , 0x02);
	LCD_voidSendCommand(copy_pstConfig , LCD_u8FUNCTION_SET);
	_delay_ms(1);
	// send diplay on off command
	LCD_voidSendCommand(copy_pstConfig , LCD_u8DISPLAY_ON_OFF_SET);
	_delay_ms(1);
	// send clear dipslay command
	LCD_voidSendCommand(copy_pstConfig , LCD_u8ClEAR_DISPLAY);
	_delay_ms(1);
	/* send enter mode set command*/
	LCD_voidSendCommand(copy_pstConfig , LCD_u8ENTRYMODE_SET);
	_delay_ms(1);
}



static void LCD_void4Bit_SendCommand(LCD_stConfig* copy_pstConfig , u8 copy_u8Command)
{
	// clear RS pin &  Clear RW pin
	DIO_VoidSetPinValue(copy_pstConfig->LCD_u8RsPort , copy_pstConfig->LCD_u8RsPin , DIO_PIN_LOGIC_LOW);
	DIO_VoidSetPinValue(copy_pstConfig->LCD_u8RwPort , copy_pstConfig->LCD_u8RwPin , DIO_PIN_LOGIC_LOW);

	// send high 4 bit
	DIO_VoidSet4bitsValue(copy_pstConfig->LCD_u8DataPort, (copy_u8Command>>4)&0x0F , copy_pstConfig->LCD_u8FirstPin );

	// send enable signal
	DIO_VoidSetPinValue(copy_pstConfig->LCD_u8EnablePort , copy_pstConfig->LCD_u8EnablePin , DIO_PIN_LOGIC_HIGH);
	_delay_ms(1);
	DIO_VoidSetPinValue(copy_pstConfig->LCD_u8EnablePort , copy_pstConfig->LCD_u8EnablePin , DIO_PIN_LOGIC_LOW);
	_delay_ms(5);
	// send low 4 bit
	DIO_VoidSet4bitsValue(copy_pstConfig->LCD_u8DataPort,  copy_u8Command & 0x0F , copy_pstConfig->LCD_u8FirstPin );


	// send enable signal
	DIO_VoidSetPinValue(copy_pstConfig->LCD_u8EnablePort , copy_pstConfig->LCD_u8EnablePin , DIO_PIN_LOGIC_HIGH);
	_delay_ms(1);
	DIO_VoidSetPinValue(copy_pstConfig->LCD_u8EnablePort , copy_pstConfig->LCD_u8EnablePin , DIO_PIN_LOGIC_LOW);

	_delay_ms(5);

}

static void LCD_void4Bit_SendChar(LCD_stConfig* copy_pstConfig , u8 copy_u8Char)
{
	// set RS pin &  Clear RW pin
	DIO_VoidSetPinValue(copy_pstConfig->LCD_u8RsPort , copy_pstConfig->LCD_u8RsPin , DIO_PIN_LOGIC_HIGH);
	DIO_VoidSetPinValue(copy_pstConfig->LCD_u8RwPort , copy_pstConfig->LCD_u8RwPin , DIO_PIN_LOGIC_LOW);



	// send second 4 bit
	DIO_VoidSet4bitsValue(copy_pstConfig->LCD_u8DataPort , (copy_u8Char>>4)&0x0F , copy_pstConfig->LCD_u8FirstPin );

	// send enable signal
	DIO_VoidSetPinValue(copy_pstConfig->LCD_u8EnablePort , copy_pstConfig->LCD_u8EnablePin , DIO_PIN_LOGIC_HIGH);
	_delay_ms(1);
	DIO_VoidSetPinValue(copy_pstConfig->LCD_u8EnablePort , copy_pstConfig->LCD_u8EnablePin , DIO_PIN_LOGIC_LOW);

	_delay_ms(1);
	// send first 4 bit
	DIO_VoidSet4bitsValue(copy_pstConfig->LCD_u8DataPort , (copy_u8Char&0x0F) , copy_pstConfig->LCD_u8FirstPin );

	// send enable signal
	DIO_VoidSetPinValue(copy_pstConfig->LCD_u8EnablePort , copy_pstConfig->LCD_u8EnablePin , DIO_PIN_LOGIC_HIGH);
	_delay_ms(1);
	DIO_VoidSetPinValue(copy_pstConfig->LCD_u8EnablePort , copy_pstConfig->LCD_u8EnablePin , DIO_PIN_LOGIC_LOW);
	return;
}

#endif




void LCD_voidSendU32Digit(LCD_stConfig* copy_pstConfig , u32 num)
{
	// 32767
	u8 numStr[11];
	snprintf(numStr , 11 , "%lu" , num);
	LCD_voidSendString(copy_pstConfig , numStr );
	return;
}

void LCD_voidSendU32Digit_Postion(LCD_stConfig* copy_pstConfig , u32 num, u8 copy_u8Row , u8 copy_u8Colum)
{
	LCD_voidSendCommand(copy_pstConfig ,  (LCD_U8DDRAM_OFFSET | (copy_u8Row + copy_u8Colum)) );
	_delay_ms(35);
	LCD_voidSendU32Digit(copy_pstConfig,num);
	return;
}

void LCD_voidSendf32Digit(LCD_stConfig* copy_pstConfig , f32 num)
{
	u8 dot_point_location = 0;
	u8 numStr[11] = {0};

	s32 l_intPart = (s32)num;
	f32 l_floatPart =  num - l_intPart;

	snprintf(numStr , 6 , "%d" , l_intPart);

	while(numStr[dot_point_location] != '\0')
		++dot_point_location;

	numStr[dot_point_location++] = '.';



	numStr[dot_point_location++] = ((u32)(l_floatPart * 10) %10) + '0';
	numStr[dot_point_location] = ((u32)(l_floatPart * 100) %10) + '0';

	LCD_voidSendString(copy_pstConfig ,numStr);
	return;
}
void LCD_voidSendf32Digit_Postion(LCD_stConfig* copy_pstConfig , f32 num, u8 copy_u8Row , u8 copy_u8Colum)
{
	LCD_voidSendCommand(copy_pstConfig ,  (LCD_U8DDRAM_OFFSET | (copy_u8Row + copy_u8Colum)) );
	_delay_ms(35);
	LCD_voidSendf32Digit(copy_pstConfig,num);
	return;
}













