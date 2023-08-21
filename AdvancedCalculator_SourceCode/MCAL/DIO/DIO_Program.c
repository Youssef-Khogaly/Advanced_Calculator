/*
 * DIO_Program.c

 *
 *  Created on: Aug 10, 2023
 *      Author: yosse
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/Bit_Math.h"
#include "DIO_Private.h"
#include "DIO_Interface.h"



static volatile u8* DIO_ARR_PORT[4] = {DIO_PORTA_REG,DIO_PORTB_REG,DIO_PORTC_REG,DIO_PORTD_REG};

static volatile u8* DIO_ARR_DDR[4] = {DIO_DDRA_REG,DIO_DDRB_REG,DIO_DDRC_REG,DIO_DDRD_REG};

static volatile u8* DIO_ARR_PIN[4] = {DIO_PINA_REG,DIO_PINB_REG,DIO_PINC_REG,DIO_PIND_REG};



void DIO_VoidSetPinDirection(u8 Copy_u8port,u8 Copy_u8pin,u8 Copy_u8direction)
{
	if(Copy_u8port <= DIO_PORTD_IDX  && Copy_u8pin <= DIO_PIN7 )
	{
		switch(Copy_u8direction)
		{
		case DIO_PIN_DIR_INPUT:
			Clr_Bit( (*DIO_ARR_DDR[Copy_u8port]) , Copy_u8pin);
			break;
		case DIO_PIN_DIR_OUTPUT:
			Set_Bit( (*DIO_ARR_DDR[Copy_u8port]) , Copy_u8pin);
			break;
		default: break;
		}
	}
	else
	{
		// nothing
	}
	return;
}

void DIO_VoidSetPinValue(u8 Copy_u8port,u8 Copy_u8pin,u8 Copy_u8value)
{
	if(Copy_u8port <= DIO_PORTD_IDX  && Copy_u8pin <= DIO_PIN7 )
	{
		switch(Copy_u8value)
		{
		case DIO_PIN_LOGIC_LOW:
			Clr_Bit((*DIO_ARR_PORT[Copy_u8port]) , Copy_u8pin);
			break;
		case DIO_PIN_LOGIC_HIGH:
			Set_Bit((*DIO_ARR_PORT[Copy_u8port]) , Copy_u8pin);
			break;
		default: break;
		}
	}
	else
	{/*nothing*/}
	return;
}
void DIO_VoidTogglePinValue(u8 Copy_u8port,u8 Copy_u8pin)
{
	if(Copy_u8port <= DIO_PORTD_IDX  && Copy_u8pin <= DIO_PIN7 )
	{
		Toggle_Bit((*DIO_ARR_PORT[Copy_u8port]) , Copy_u8pin);
	}
	else
	{/*nothing*/}
	return;
}
void DIO_VoidGetPinValue(u8 Copy_u8port,u8 Copy_u8pin,u8 *Copy_pu8Return)
{
	if(Copy_u8port <= DIO_PORTD_IDX  && Copy_u8pin <= DIO_PIN7 && Copy_pu8Return )
	{
		*Copy_pu8Return = Get_Bit(*(DIO_ARR_PIN[Copy_u8port]) , Copy_u8pin);
	}
	else
	{/*nothing*/}
	return;
}

void DIO_VoidSetPortDirection(u8 Copy_u8port,u8 Copy_u8direction)
{
	if(Copy_u8port <= DIO_PORTD_IDX)
	{
		*DIO_ARR_DDR[Copy_u8port] = Copy_u8direction;
	}
	else {/*nothing*/}
	return;
}
void DIO_VoidSetPortValue(u8 Copy_u8port,u8 Copy_u8value)
{
	if(Copy_u8port <= DIO_PORTD_IDX)
	{
		*DIO_ARR_PORT[Copy_u8port] = Copy_u8value;
	}
	else {/*nothing*/}
	return;
}

void DIO_VoidTogglePortValue(u8 Copy_u8port)
{
	if(Copy_u8port <= DIO_PORTD_IDX)
	{
		( *DIO_ARR_PORT[Copy_u8port] ) ^= (0xff);
	}
	else {/*nothing*/}
	return;
}
void DIO_VoidGetPortValue(u8 Copy_u8port,u8 *Copy_pu8Return)
{
	if(Copy_u8port <= DIO_PORTD_IDX && Copy_pu8Return)
	{
		*Copy_pu8Return = *DIO_ARR_PIN[Copy_u8port];
	}
	else {/*nothing*/}
	return;
}

void DIO_VoidSet4bitsValue(u8 Copy_u8port,u8 Copy_u8value,u8 Copy_u8Bitselection)
{
	if(Copy_u8port <= DIO_PORTD_IDX && Copy_u8value <= 15 && Copy_u8Bitselection <= DIO_PIN5 )
	{
		(*DIO_ARR_PORT[Copy_u8port]) &= ~(0x0f << Copy_u8Bitselection); // to delete old value
		(*DIO_ARR_PORT[Copy_u8port]) |=  (Copy_u8value << Copy_u8Bitselection); // write new value

	}
	else {/*nothing*/}
	return;
}

void DIO_VoidGet4bitsValue(u8 Copy_u8port,u8* Copy_u8value,u8 Copy_u8Bitselection)
{
	u8 l_copyOfPinVal = *DIO_ARR_PIN[Copy_u8port];
	if(Copy_u8port <= DIO_PORTD_IDX && Copy_u8value  && Copy_u8Bitselection <= DIO_PIN5 )
	{
		(*Copy_u8value) = (l_copyOfPinVal >> Copy_u8Bitselection) & 0x0f;

	}
	else {/*nothing*/}
	return;
}

void DIO_voidPortInit(u8 Copy_u8port , u8 Copy_u8direction , u8 Copy_u8value)
{
	if(Copy_u8port <= DIO_PORTD_IDX)
	{
		*DIO_ARR_DDR[Copy_u8port] = Copy_u8direction;
		*DIO_ARR_PORT[Copy_u8port] = Copy_u8value;
	}
	else {/*nothing*/}
	return;
}

void DIO_voidPinInit(u8 Copy_u8port ,u8 Copy_u8pin,u8 Copy_u8direction , u8 Copy_u8value)
{
	if(Copy_u8port <= DIO_PORTD_IDX  && Copy_u8pin <= DIO_PIN7 )
	{
		DIO_VoidSetPinValue(Copy_u8port,Copy_u8pin,Copy_u8value);
		DIO_VoidSetPinDirection(Copy_u8port,Copy_u8pin,Copy_u8direction);

	}
	else {/*nothing*/}
	return;
}



