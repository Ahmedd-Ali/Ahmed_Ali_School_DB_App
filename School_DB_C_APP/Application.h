/******************************************************************************/
/*****************************************************************************/
/****************    Author    : Ahmed Ali             **********************/
/****************    SWC       : C App - School DB     *********************/
/****************    version   : 1.0.0                 ********************/
/*************************************************************************/
/************************************************************************/


#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include "STD_TYPES.h"
#include "ErrorState.h"

/** we can update an algorithm to generate student ID according to year, class, and number of students **/

typedef enum{
    RETURN_HOME= 0,
    CURRUNT_TAB= 1
}tabState_t;

typedef enum{
    SCHOOL_RUN_STATE= 0,
    SCHOOL_EXIT_STATE= 1
}schoolState_t;

typedef enum{
    INSERT_STUDENT= 1,
    EDIT_STUDENT= 2,
    PRINT_STUDENT= 3,
    DELETE_STUDENT= 4,
    CALL_STUDENT= 5,
    CLASS_PRINT= 6,
    CLASS_FREE= 7,
    SCHOOL_SIZE= 8,
    SCHOOL_EXIT=9
}appMenuOptions_t;

typedef enum{
    CLASS_A= 0,
    CLASS_B= 1,
    CLASS_C= 2,
    CLASS_D= 3
}schoolClass_t;



ErrorState_t schoolApp(void);



#endif // _APPLICATION_H_
