/******************************************************************************/
/*****************************************************************************/
/****************    Author    : Ahmed Ali             **********************/
/****************    SWC       : C App - School DB     *********************/
/****************    version   : 1.0.0                 ********************/
/*************************************************************************/
/************************************************************************/


#include "stdio.h"
#include "STD_TYPES.h"
#include "String.h"


/*============= String compare =============*/
u32 string_length(u8 *str)
{
    int i;
    for(i=0; str[i]; i++);
    return i;
}


s8 string_compare(u8 *str1, u8 *str2)
{
    u32 i;
    u8 cmpFlag= 0;
    for(i=0; (str1[i] != 0) && (str2[i] != 0); i++)
    {
        if(str1[i] != str2[i])
        {
            if(str1[i] < str2[i])
            {
                cmpFlag= -1;
                break;
            }
            else
            {
                cmpFlag= 1;
                break;
            }
        }
    }
    return cmpFlag;
}

/*=========== String Copy & String Scan ===========*/

void string_copy(u8 *source, u8 *dest, u32 maxSize)
{
    u32 i;
    for(i=0; source[i] && i<(maxSize-1); i++)
    {
        dest[i] = source[i];
    }
    dest[i] = 0;
}


void string_scan(u8 *str, u32 maxSize)
{
    u32 i=0;
    scanf(" %c", &str[i]);
    for(; (str[i] != '\n') && (i < maxSize);)
    {
        i++;
		scanf("%c", &str[i]);
	}
	str[i] = 0;
}


void string_print(u8 *str)
{
    u32 i;
    for(i=0; str[i]; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}

/*============= AtoI & ItoA =============*/

void string_reverse(u8 *str)
{
    u32 i, j;
    u8 temp;
    j = string_length(str)-1;
    for(i=0; i<=j; i++)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        j--;
    }
}

void ItoA(s32 num, u8 *str)
{
    u32 i=0, flag=0, rem;
    if(num == 0)
    {
        str[i] = '0';
        str[i+1] = 0;
        return;
    }
    if(num < 0)
    {
        num = num *(-1);
        flag = 1;
    }
    while(num > 0)
    {
        rem = num % 10;
        rem = rem + '0';
        str[i] = rem;
        i++;
        num = num / 10;
    }
    if(flag == 1)
    {
        str[i] = '-';
        i++;
    }
    str[i] = 0;
    string_reverse(str);
}

u32 AtoI(u8 *str)
{
    u32 i=0, num=0;

    for( ; str[i]; i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            num = (num * 10) + (str[i] - '0');
        }
    }
    if(str[0] == '-')
    {
        num = num * (-1);
    }
    return num;
}


