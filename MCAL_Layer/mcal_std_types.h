/* 
 * File:   mcal_std_types.h
 * Author: star
 *
 * Created on 18 ?????, 2023, 12:41 ?
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H
/*Includes Section*/
#include "std_libiraries.h"
#include "compiler.h"
#include <string.h>
/*Data types declaration Section*/
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;

typedef uint8 Std_ReturnType;

/*Macro declaration Section*/
#define STD_HIGH      0x01
#define STD_LOW       0x00

#define STD_ON        0x01
#define STD_OFF       0x00
 
#define STD_ACTIVE    0x01
#define STD_IDLE      0x00

#define E_NOT_OK       (Std_ReturnType) 0x01
#define E_OK          (Std_ReturnType) 0x00

#define ZERO_INIT   0x00




#endif	/* MCAL_STD_TYPES_H */

