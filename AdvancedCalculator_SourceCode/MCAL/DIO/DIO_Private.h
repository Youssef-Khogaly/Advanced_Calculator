/*
 * DIO_Private.h
 *
 *  Created on: Aug 10, 2023
 *      Author: yosse
 */

#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_

#define HW_REG(ADDRESS)		((volatile u8*)ADDRESS)

/*Ports */
#define DIO_PORTA_REG			(HW_REG(0x3B))
#define DIO_PORTB_REG			(HW_REG(0x38))
#define DIO_PORTC_REG			(HW_REG(0x35))
#define DIO_PORTD_REG			(HW_REG(0x32))
/*DDR */
#define DIO_DDRA_REG			(HW_REG(0x3A))
#define DIO_DDRB_REG			(HW_REG(0x37))
#define DIO_DDRC_REG			(HW_REG(0x34))
#define DIO_DDRD_REG			(HW_REG(0x31))

/*PIN REG */
#define DIO_PINA_REG			(HW_REG(0x39))
#define DIO_PINB_REG			(HW_REG(0x36))
#define DIO_PINC_REG			(HW_REG(0x33))
#define DIO_PIND_REG			(HW_REG(0x30))


#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
