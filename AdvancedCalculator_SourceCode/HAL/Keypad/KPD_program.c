/*
 * KPD_program.c
 *
 *  Created on: Aug 14, 2023
 *      Author: yosse
 */
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"

static u8 KPD_ArrROWS_PINS[ROWS_U8NUM] = KPD_ROW_PINS_ARR;
static u8 KPD_ArrCOLS_PINS[COLUMS_U8NUM] = KPD_COL_PINS_ARR;

void KPD_VoidInit(void)
{
	u8 i = 0;
	for(; i <ROWS_U8NUM ; ++i)
		DIO_voidPinInit(KEYPARD_PORT, KPD_ArrROWS_PINS[i], DIO_PIN_DIR_INPUT , DIO_PIN_LOGIC_HIGH);

	for(i = 0 ; i < COLUMS_U8NUM ; ++i)
		DIO_voidPinInit(KEYPARD_PORT, KPD_ArrCOLS_PINS[i], DIO_PIN_DIR_OUTPUT , DIO_PIN_LOGIC_HIGH);
	return;
}

u8 KPD_U8GetKey(void)
{
	u8 KPD_ARR_VAL[ROWS_U8NUM][COLUMS_U8NUM] =  KEYPAD_ARR_VALUES;
	u8 local_KPD_Stat = DIO_PIN_LOGIC_HIGH;
	u8 l_rows = 0 , l_colums = 0;

	for(;l_colums < COLUMS_U8NUM ; ++l_colums )
	{
		DIO_VoidSetPinValue(KEYPARD_PORT,KPD_ArrCOLS_PINS[l_colums],DIO_PIN_LOGIC_LOW);
		for(l_rows = 0 ; l_rows <ROWS_U8NUM ; ++l_rows )
		{
			DIO_VoidGetPinValue(KEYPARD_PORT,KPD_ArrROWS_PINS[l_rows] , &local_KPD_Stat);
			if(DIO_PIN_LOGIC_LOW == local_KPD_Stat)
			{
				while(DIO_PIN_LOGIC_LOW == local_KPD_Stat)
				{
					DIO_VoidGetPinValue(KEYPARD_PORT,KPD_ArrROWS_PINS[l_rows] , &local_KPD_Stat);
				}
				return KPD_ARR_VAL[l_rows][l_colums];
			}
		}
		DIO_VoidSetPinValue(KEYPARD_PORT,KPD_ArrCOLS_PINS[l_colums],DIO_PIN_LOGIC_HIGH);
	}
	return KEYPAD_U8NOTPRESSED;
}
