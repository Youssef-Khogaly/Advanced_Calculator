/*
 * STD_TYPES.h
 *
 *  Created on: Aug 10, 2023
 *      Author: yosse
 */

#ifndef LIB_STD_TYPES_H_
#define LIB_STD_TYPES_H_


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef signed char s8;
typedef signed short int s16;
typedef signed int s32;
typedef float f32;
typedef double f64;

#define NULL ((void*)0x00)

typedef void (*ISR_FuncPtr_t)(void);

#endif /* LIB_STD_TYPES_H_ */
