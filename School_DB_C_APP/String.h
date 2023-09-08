/******************************************************************************/
/*****************************************************************************/
/****************    Author    : Ahmed Ali             **********************/
/****************    SWC       : C App - School DB     *********************/
/****************    version   : 1.0.0                 ********************/
/*************************************************************************/
/************************************************************************/



#ifndef _STRING_H_
#define _STRING_H_

/******************** Includes **********************/
#include "STD_TYPES.h"

/******************** Prototypes **********************/
u32 string_length(u8 *str);
s8 string_compare(u8 *str1, u8 *str2);
void string_copy(u8 *source, u8 *dest, u32 maxSize);
void string_scan(u8 *str, u32 maxSize);
void string_print(u8 *str);
void string_reverse(u8 *str);
void ItoA(s32 num, u8 *str);
u32 AtoI(u8 *str);



#endif // _STRING_H_
