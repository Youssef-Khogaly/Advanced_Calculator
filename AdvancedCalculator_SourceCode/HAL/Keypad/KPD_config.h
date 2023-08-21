/*
 * KPD_config.h
 *
 *  Created on: Aug 14, 2023
 *      Author: yosse
 */

#ifndef HAL_KEYPAD_KPD_CONFIG_H_
#define HAL_KEYPAD_KPD_CONFIG_H_


/* chose a u8 value to return it if no button pressed*/
#define KEYPAD_U8NOTPRESSED		0xff

#define  COLUMS_U8NUM	4
#define  ROWS_U8NUM		4

/**
*
* OPtions:
*
*	 DIO_PORTA_IDX
*	 DIO_PORTB_IDX
*	 DIO_PORTC_IDX
*	 DIO_PORTD_IDX
*
 */
#define KEYPARD_PORT	DIO_PORTD_IDX

/*
 * pins options:
 * 				DIO_PIN0
 * 				DIO_PIN1
 * 				DIO_PIN2
 * 				DIO_PIN3
 * 				DIO_PIN4
 * 				DIO_PIN5
 * 				DIO_PIN6
 * 				DIO_PIN7
 */

#define KPD_COL0_PIN	DIO_PIN4
#define KPD_COL1_PIN	DIO_PIN5
#define KPD_COL2_PIN	DIO_PIN6
#define KPD_COL3_PIN	DIO_PIN7

#define KPD_COL_PINS_ARR	{KPD_COL0_PIN,KPD_COL1_PIN,KPD_COL2_PIN,KPD_COL3_PIN}

#define KPD_ROW0_PIN	DIO_PIN0
#define KPD_ROW1_PIN	DIO_PIN1
#define KPD_ROW2_PIN	DIO_PIN2
#define KPD_ROW3_PIN	DIO_PIN3

#define KPD_ROW_PINS_ARR {KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN, KPD_ROW3_PIN}


#define KEYPAD_ARR_VALUES		{{'c',0,'=','+'},{1,2,3,'-'}, {4,5,6,'*'}, {7,8,9,'/'}}


#endif /* HAL_KEYPAD_KPD_CONFIG_H_ */
