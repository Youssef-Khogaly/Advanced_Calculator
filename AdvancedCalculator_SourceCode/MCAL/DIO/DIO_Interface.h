/*
 * DIO_Interface.h
 *
 *  Created on: Aug 10, 2023
 *      Author: yosse
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

/********************MACROS***********************/

/*PORT IDX*/
#define DIO_PORTA_IDX	0
#define DIO_PORTB_IDX	1
#define DIO_PORTC_IDX	2
#define DIO_PORTD_IDX	3
/*PINS IDX*/
#define DIO_PIN0		0
#define DIO_PIN1		1
#define DIO_PIN2		2
#define DIO_PIN3		3
#define DIO_PIN4		4
#define DIO_PIN5		5
#define DIO_PIN6		6
#define DIO_PIN7		7

// port directions
#define DIO_PORT_DIR_OUTPUT		0xff
#define DIO_PORT_DIR_INPUT		0x00

// pins direction
#define DIO_PIN_DIR_OUTPUT		0x01
#define DIO_PIN_DIR_INPUT		0x00

// ports logic
#define DIO_PORT_LOGIC_HIGH		0xff
#define DIO_PORT_LOGIC_LOW		0x00

// pins logic
#define DIO_PIN_LOGIC_HIGH		0x01
#define DIO_PIN_LOGIC_LOW		0x00

//4pin logic
#define DIO_4PIN_ALL_LOGIC_HIGH	 0x0F
#define DIO_4PIN_ALL_LOGIC_LOW	 0x00

/*********************************************/


/*****************Prototypes*****************/


/*
 * * Name: DIO_VoidSetPinDirection
 *
 * 	description: Set a  A pin direction
 * 	Parameters:
 * 		@u8 Copy_u8port : ex: DIO_PORTA_IDX , DIO_PORTB_IDX
 * 		@u8 Copy_u8pin : ex:DIO_PIN0
 * 		@u8 Copy_u8direction : DIO_PIN_DIR_OUTPUT
 *
 * 	return: Void
 * */
void DIO_VoidSetPinDirection(u8 Copy_u8port, u8 Copy_u8pin, u8 Copy_u8direction); // ddr
/*
 * * Name: DIO_VoidSetPinValue
 *
 * 	description: Set a  logic to a pin
 * 		Parameters:
 * 		@u8 Copy_u8port : ex: DIO_PORTA_IDX , DIO_PORTB_IDX
 * 		@u8 Copy_u8pin : ex:DIO_PIN0
 * 		@u8 Copy_u8direction : DIO_PORT_LOGIC_HIGH
 *
 * 	return: Void
 * */

void DIO_VoidSetPinValue(u8 Copy_u8port,u8 Copy_u8pin,u8 Copy_u8value); //PORT

/*
 * * Name: DIO_VoidTogglePinValue
 *
 * 	description: toggle   logic on  pin
 * 		Parameters:
 * 		@u8 Copy_u8port : ex: DIO_PORTA_IDX , DIO_PORTB_IDX
 * 		@u8 Copy_u8pin : ex:DIO_PIN0
 *
 * 	return: Void
 * */
void DIO_VoidTogglePinValue(u8 Copy_u8port,u8 Copy_u8pin); //PORT

/*
 * * Name: DIO_VoidSetPinValue
 *
 * 	description: read a logic from a pin and return it in a pointer
 * 		Parameters:
 * 		@u8 Copy_u8port : ex: DIO_PORTA_IDX , DIO_PORTB_IDX
 * 		@u8 Copy_u8pin : ex:DIO_PIN0
 * 		@u8* Copy_pu8Return : pointer to return a value
 *
 * 	return: Void
 * */
void DIO_VoidGetPinValue(u8 Copy_u8port,u8 Copy_u8pin,u8 *Copy_pu8Return);//PIN

/*
 * * Name: DIO_VoidSetPinValue
 *
 * 	description: set all port to a specific dirction
 * 		Parameters:
 * 		@u8 Copy_u8port : ex: DIO_PORTA_IDX , DIO_PORTB_IDX
		@u8 Copy_u8direction : ex : DIO_PORT_DIR_OUTPUT
 *
 * 	return: Void
 * */
void DIO_VoidSetPortDirection(u8 Copy_u8port,u8 Copy_u8direction);//DDR

/*
 * * Name: DIO_VoidSetPortValue
 *
 * 	description: write a logic on port
 * 		Parameters:
 * 		@u8 Copy_u8port : ex:   DIO_PORTA_IDX , DIO_PORTB_IDX
		@u8 Copy_u8value : ex : DIO_PORT_LOGIC_HIGH
 *
 * 	return: Void
 * */
void DIO_VoidSetPortValue(u8 Copy_u8port,u8 Copy_u8value);//PORT


/*
 * * Name: DIO_VoidTogglePortValue
 *
 * 	description: toggle  logic on port
 * 		Parameters:
 * 		@u8 Copy_u8port : ex:   DIO_PORTA_IDX , DIO_PORTB_IDX
 *
 * 	return: Void
 * */
void DIO_VoidTogglePortValue(u8 Copy_u8port);//PORT

/*
 * * Name: DIO_VoidSetPinValue
 *
 * 	description: read the logic form a port and return it in pointer
 * 		Parameters:
 * 		@u8 Copy_u8port : ex:   DIO_PORTA_IDX , DIO_PORTB_IDX
		@u8* Copy_pu8Return : pointer to return the value
 *
 * 	return: Void
 * */
void DIO_VoidGetPortValue(u8 Copy_u8port,u8 *Copy_pu8Return);//PIN

/**
 * Name: DIO_VoidSet4bitsValue
 *
 * description: write value to 4 pins on same port!!
 * 				!! IMPORTANT NOTE Pins must be in row and first pin less than 5
 *
 * 			Parameters:
 * 			@u8 Copy_u8port : example: DIO_PORTA_IDX
 * 			@u8 Copy_u8value: Value to write it on 4 pins example 0x00 , 0x05 MUST BE 8bit value or use DIO_4PIN_ALL_LOGIC_HIGH
 * 			@u8 Copy_u8Bitselection: first bit to write on it "LSB" EX: DIO_PIN3
 *
 *			return void
 * */
void DIO_VoidSet4bitsValue(u8 Copy_u8port,u8 Copy_u8value,u8 Copy_u8Bitselection);

/**
 * Name: DIO_VoidGet4bitsValue
 *
 * description: read value from 4 pins on same port!!
 * 				!! IMPORTANT NOTE Pins must be in row and first pin less than 5
 *				and value return in  pointer
 * 			Parameters:
 * 			@u8 Copy_u8port : example: DIO_PORTA_IDX
 * 			@u8* Copy_u8value: to return value
 * 			@u8 Copy_u8Bitselection: first bit to Read from it "LSB" EX: DIO_PIN3 it return the value on pin6'MSB' ..... , pin4  ,  pin3"LSB"
 *
 *			return void
 * */
void DIO_VoidGet4bitsValue(u8 Copy_u8port,u8* Copy_u8value,u8 Copy_u8Bitselection);

/**
 * Name: DIO_voidPortInit
 * description:
 * 				Init port direction and logic;
 * 	Parameters:
 * 		@u8 Copy_u8port : example: DIO_PORTA_IDX
 * 		@u8 Copy_u8direction: example: DIO_PORT_DIR_OUTPUT
 * 		@u8 u8 Copy_u8value: example: DIO_PORT_LOGIC_HIGH
 * */
void DIO_voidPortInit(u8 Copy_u8port , u8 Copy_u8direction , u8 Copy_u8value);


/**
 * Name: DIO_voidPortInit
 * description:
 * 				Init pin direction and logic;
 * 	Parameters:
 * 		@u8 Copy_u8port : example: DIO_PORTA_IDX
 * 		@u8 Copy_u8pin: example DIO_PIN0
 * 		@u8 Copy_u8direction: example: DIO_PIN_DIR_OUTPUT
 * 		@u8 u8 Copy_u8value: example: DIO_PIN_LOGIC_HIGH
 * */
void DIO_voidPinInit(u8 Copy_u8port ,u8 Copy_u8pin,u8 Copy_u8direction , u8 Copy_u8value);
/********************************************/

#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
