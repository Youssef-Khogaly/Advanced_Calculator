/*
 * Bit_Math.h
 *
 *  Created on: Aug 10, 2023
 *      Author: yosse
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_



#define Set_Bit(var,BitNo)  (var |= (1 << BitNo))

#define Clr_Bit(var,BitNo)  (var &= (~(1 << BitNo)))

#define Toggle_Bit(var,BitNo) (var ^= (1 << BitNo))

#define Get_Bit(var,BitNo)		((var>>BitNo) & 0x01)


#endif /* LIB_BIT_MATH_H_ */
