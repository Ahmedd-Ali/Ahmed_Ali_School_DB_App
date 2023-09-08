/******************************************************************************/
/*****************************************************************************/
/****************    Author    : Ahmed Ali             **********************/
/****************    SWC       : C App - School DB     *********************/
/****************    version   : 1.0.0                 ********************/
/*************************************************************************/
/************************************************************************/


#ifndef STDTYPES_H_
#define STDTYPES_H_

typedef unsigned char  u8;
typedef signed char    s8;

typedef unsigned short  u16;
typedef signed short    s16;

typedef unsigned int  u32;
typedef signed int    s32;


typedef unsigned long long int u64;
typedef signed long long int   s64;

//#define NULL         ((void*)0)

#define MAX_U8      ((u8)0xff)
#define MAX_S8      ((s8)0x7f)
#define MIN_S8      ((s8)0x80)

#define MAX_U16     ((u16)0xffff)
#define MAX_S16     ((s16)0x7fff)
#define MIN_S16     ((s16)0x8000)

#define MAX_U32     ((u32)0xffffffff)
#define MAX_S32     ((s32)0x7fffffff)
#define MIN_S32     ((s32)0x80000000)

#define MAX_U64     ((u64)0xffffffffffffffff)
#define MAX_S64     ((s64)0x7fffffffffffffff)
#define MIN_S64     ((s64)0x8000000000000000)

#endif /* STDTYPES_H_ */
