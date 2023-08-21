/*
 * main.h
 *
 *  Created on: Aug 17, 2023
 *      Author: yosse
 */

#ifndef MAIN_H_
#define MAIN_H_

/*define Clock freq for delay function*/
#define F_CPU	8000000UL
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../HAL/Keypad/KPD_config.h"
#include "../HAL/Keypad/KPD_interface.h"
#include "../HAL/LCD/LCD_config.h"
#include "../HAL/LCD/LCD_interfacec.h"
/*define Clock freq for delay function*/



#define OPERANT_SIZE		5U
#define OPERANTION_SIZE		5U

void swap_f32(f32* x , f32* y);
void swap_U8(u8* x , u8* y);


u8 IS_Input_Num(u8 a);
u8 IS_Input_Operation(u8 a);
u8 IS_Input_Equal(u8 a);
u8 IS_Input_Clear(u8 a);

void app_init(void);
void Clear_ALL(f32* op  , u8* operation , u8 op_ArrSize , u8 operation_ArrSize);
void welcomeScreen(void);
u8 Calcualtor(f32* operant , u8* operation ,u8 last_operIdx , u8 last_operationIdx ,f32* Ptr_ans);


#endif /* MAIN_H_ */
