/******************************************************************************/
/*****************************************************************************/
/****************    Author    : Ahmed Ali             **********************/
/****************    SWC       : C App - School DB     *********************/
/****************    version   : 1.0.0                 ********************/
/*************************************************************************/
/************************************************************************/


#ifndef _SCHOOL_H_
#define _SCHOOL_H_


#include "STD_TYPES.h"
#include "Config.h"
#include "ErrorState.h"




typedef enum{
    UPDATE_PERSONAL_DATA= 1,
    UPDATE_SCORE_DATA= 2
}updateDataState_t;

typedef enum{
   // EDIT_NAME= 1,
   // EDIT_ID= 2,
    EDIT_AGE= 1,
    EDIT_PHONE= 2,
    EDIT_ADDRESS= 3
}updatePersonalState_t;

typedef enum{
    EDIT_MATH= 1,
    EDIT_ENGLISH= 2,
    EDIT_ARABIC= 3
}updateScoreState_t;


/****************************/

typedef struct {
	u8  math_deg;
	u8  english_deg;
	u8  arabic_deg;
}Subject_t;

typedef struct{
	u32  phone;
	u8   address[ADRESSSIZE];
}Personal_t;

typedef struct myStudent{
	u8 ID;
	u8 Name[NAMESIZE];
	u8 age;
	Personal_t  data;
	Subject_t   degress;
}Student_t;

typedef Student_t ListEntry_t;

typedef struct Node{
	struct Node *pNext;
    struct Node *pPrev;
    ListEntry_t   entry;
}ListNode_t;

typedef struct myList{
	ListNode_t * pHead;
	ListNode_t * pTail;
	int ListSize;
}List_t;

ErrorState_t  List_create(List_t* pl);
ErrorState_t  List_scanStudent(ListEntry_t * pe);       /** Added **/
ErrorState_t  List_insertStudent( List_t* pl , const ListEntry_t * pe);
ErrorState_t  List_searchStudent(const List_t* pl , u8 copy_u8ID,ListNode_t ** pFoundStudent );
ErrorState_t  List_deleteStudent(List_t* pl , u8 copy_u8ID);
ErrorState_t  List_printStudent(const List_t* pl , u8 copy_u8ID);       /** Added **/
ErrorState_t  List_callStudent(const List_t* pl , u8 copy_u8ID);       /** Added **/

ErrorState_t  List_editStudent(const List_t* pl , u8 copy_u8ID);
ErrorState_t  List_updatePersonal(ListNode_t * pe);     /** Added **/
ErrorState_t  List_updateScore(ListNode_t * pe);        /** Added **/

ErrorState_t  List_printList(const List_t* pl );
ErrorState_t  List_listSize(const List_t* pl ,u32 * pSize);
ErrorState_t  List_freeList(List_t* pl);

#endif
