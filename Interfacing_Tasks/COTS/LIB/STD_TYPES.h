/*
 *
 STD_TYPES.h
 *
 *  	Created on: Mar 8, 2024
 *      Author: Mohammad Tamer
 */

#ifndef LIB_STD_TYPES_H_
#define LIB_STD_TYPES_H_

/* Boolean Values */
#ifndef FALSE
#define FALSE       (0)
#endif
#ifndef TRUE
#define TRUE        (1)
#endif


typedef unsigned char         u8;
typedef signed char           s8;
typedef unsigned short        u16;
typedef signed short          s16;
typedef unsigned long         u32;
typedef signed long           s32;
typedef unsigned long long    u64;
typedef signed long long      s64;
typedef float                 f32;
typedef double                f64;

#define  NULL 0
#define  OK   0
#define  NOK  1
#define  NULL_POINTER  2



#endif /* LIB_STD_TYPES_H_ */
