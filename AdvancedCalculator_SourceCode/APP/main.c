/*
 * main.c
 *
 *  Created on: Aug 10, 2023
 *      Author: yosse
 */

#include "main.h"

LCD_stConfig _lcd = {
		.LCD_u8DataPort = LCD_U8PORTC,
		.LCD_u8RsPort = LCD_U8PORTB,
		.LCD_u8RwPort = LCD_U8PORTB,
		.LCD_u8EnablePort = LCD_U8PORTB,
		.LCD_u8RsPin = LCD_U8PIN0,
		.LCD_u8RwPin =LCD_U8PIN1,
		.LCD_u8EnablePin = LCD_U8PIN2
};

u8 MultiDiv_Flag = 0;
u8 PlusMinus_Flag = 0;

u8 operation_idx = 0;
u8 op_idx = 0;
u8 colCounter = 0; // counter to count curr col in lcd

void main()
{
	u8 operation_ArrSize = OPERANTION_SIZE;
	u8 operant_ArrSize = OPERANT_SIZE;
	u8* operation = (u8*)calloc(operation_ArrSize,sizeof(u8));
	f32* op = (f32*)calloc(operant_ArrSize,sizeof(f32));

	u8 ret = 0;
	f32 ans = 0; // to save the answer
	u8 KPD_value = KEYPAD_U8NOTPRESSED;
	app_init();
	welcomeScreen();
	while(1)
	{
		KPD_value = KPD_U8GetKey();
		if(IS_Input_Num(KPD_value))
		{
			++colCounter;
			if(colCounter>16)
			{
				LCD_voidShiftScreenRight(&_lcd);
			}
			else {/*nothing*/}
			if(op_idx == operant_ArrSize)
			{
				op = (f32*)realloc(op , (++operant_ArrSize) * sizeof(f32));
			}
			else {/*nothing*/}
			op[op_idx] = (op[op_idx] * 10.0) + KPD_value;

			LCD_voidSendU32Digit(&_lcd , KPD_value);
		}
		else if( IS_Input_Operation(KPD_value) )
		{
			++colCounter;
			if(colCounter>=16)
			{
				LCD_voidShiftScreenRight(&_lcd);
			}
			else {/*nothing*/}
			if(operation_idx == operation_ArrSize)
			{
				operation = (u8*)realloc(operation , (++operation_ArrSize) * sizeof(u8));
			}
			else {/*nothing*/}

			MultiDiv_Flag = (KPD_value == '*' || KPD_value == '/' ) ? 1 :MultiDiv_Flag;
			PlusMinus_Flag = (KPD_value == '+' || KPD_value == '-' ) ? 1 :PlusMinus_Flag;
			LCD_voidSendChar(&_lcd ,KPD_value );
			operation[operation_idx++] = KPD_value;
			++op_idx;

		}
		else if( IS_Input_Equal(KPD_value) )
		{

			ret = Calcualtor(op , operation , op_idx ,operation_idx, &ans);
			if (ret)
			{
				if(colCounter > 16)
					LCD_voidSetCursor(&_lcd,LCD_U8ROW2 , LCD_U8COL1+(colCounter-15));
				else
					LCD_voidSetCursor(&_lcd,LCD_U8ROW2 , LCD_U8COL1);

				LCD_voidSendChar(&_lcd ,KPD_value );
				LCD_voidSendf32Digit(&_lcd , ans);
			}
			else
			{
				LCD_voidClearDisplay(&_lcd);
				LCD_voidSendString(&_lcd , "Invaild Equation");
				_delay_ms(500);
				Clear_ALL(op, operation,operant_ArrSize,operation_ArrSize);
			}

		}
		else if ( IS_Input_Clear(KPD_value) )
		{

			Clear_ALL(op, operation,operant_ArrSize,operation_ArrSize);

		}


	}
	return;
}


void Clear_ALL(f32* op  , u8* operation , u8 op_ArrSize , u8 operation_ArrSize)
{
	u8 i = 0;
	LCD_voidClearDisplay(&_lcd);
	PlusMinus_Flag = MultiDiv_Flag = 0;
	op_idx = operation_idx = colCounter=  0;
	for(; i < op_ArrSize ; ++i)
		op[i] = 0;
	for(i = 0; i < operation_ArrSize ; ++i)
		operation[i] = 0;

}

void app_init(void)
{
	LCD_voidInit(&_lcd);
	KPD_VoidInit();
}
void welcomeScreen(void)
{
	LCD_voidSendString_Postion(&_lcd , "Welcome" , LCD_U8ROW1 , LCD_U8COL5);
	LCD_voidSendString_Postion(&_lcd , "to Calculator" , LCD_U8ROW2 , LCD_U8COL3);
	_delay_ms(1000);
	LCD_voidClearDisplay(&_lcd);
}
u8 IS_Input_Num(u8 a)
{
	if(a != KEYPAD_U8NOTPRESSED && a != 'c' && a != '=' && a != '*' && a != '/' && a != '+' && a != '-')
	{
		return 1;
	}
	else
		return 0;
}

u8 IS_Input_Operation(u8 a)
{
	if(a != KEYPAD_U8NOTPRESSED && a != '=' && a != 'c' )
	{
		return 1;
	}
	else
		return 0;
}
u8 IS_Input_Equal(u8 a)
{
	if(a != KEYPAD_U8NOTPRESSED && a == '=' && a != 'c')
	{
		return 1;
	}
	else
		return 0;
}

u8 IS_Input_Clear(u8 a)
{
	if(a != KEYPAD_U8NOTPRESSED  && a == 'c')
	{
		return 1;
	}
	else
		return 0;
}
void swap_f32(f32* x , f32* y)
{
	f32 temp = *x;
	*x = *y;
	*y = temp;
}
void swap_U8(u8* x , u8* y)
{
	u8 temp = *x;
	*x = *y;
	*y = temp;
}
void delete_elementArr(f32* operant ,u8 elementIdx ,u8*last_operIdx)
{
	u8 i = elementIdx;
	/*O(N)*/
	for(; i < *last_operIdx ; ++i)
		swap_f32(&operant[i] , &operant[i+1]);
	(*last_operIdx) -= 1;
}

void delete_elementu8Arr(u8* operation ,u8 elementIdx ,u8*last_operationIdx)
{
	u8 i = elementIdx;
	/*O(N)*/
	for(; i < *last_operationIdx ; ++i)
		swap_U8(&operation[i] , &operation[i+1]);
	(*last_operationIdx) -= 1;
}

u8 Calcualtor(f32* operant , u8* operation ,u8 last_operIdx , u8 last_operationIdx ,f32* Ptr_ans)
{
	u8 ret = 0;
	u8 operantCounter = 0;
	u8 operationCounter = 0;
	*Ptr_ans = 0;
	/*O(N^2) */
	for(; operantCounter < last_operIdx && MultiDiv_Flag ;)
	{
		if(operation[operationCounter] == '*')
		{
			operant[operantCounter] *= operant[operantCounter+1];
			delete_elementArr(operant ,operantCounter+1,&last_operIdx);
			delete_elementu8Arr(operation,operationCounter,&last_operationIdx);
		}
		else if (operation[operationCounter] == '/')
		{
			if(operant[operantCounter+1] == 0)
			{
				*Ptr_ans = 0;
				ret = 0;
				return ret;
			}
			operant[operantCounter] /= operant[operantCounter+1];
			delete_elementArr(operant ,operantCounter+1,&last_operIdx);
			delete_elementu8Arr(operation,operationCounter,&last_operationIdx);
		}
		else
		{
				++operantCounter;
				++operationCounter;
		}
	}
	if(PlusMinus_Flag == 0)
	{
		ret = 1;
		*Ptr_ans = operant[operantCounter];
		return ret;
	}
	else{
		/*nothing*/
	}
	/*O(N)*/
	for(operantCounter = 0 , operationCounter = 0; operantCounter < last_operIdx ;)
	{
		if(operation[operationCounter] == '+')
		{
			operant[operantCounter+1] +=  operant[operantCounter];

			++operantCounter;
			++operationCounter;
			ret = 1;
		}
		else if (operation[operationCounter] == '-')
		{
			operant[operantCounter+1] =  (operant[operantCounter] - operant[operantCounter+1]);
			++operantCounter;
			++operationCounter;
			ret = 1;
		}
		else
		{
			ret = 0;
			break;
		}
	}
	*Ptr_ans = operant[operantCounter];

	return ret;
}






















