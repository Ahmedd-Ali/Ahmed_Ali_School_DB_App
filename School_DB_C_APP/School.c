/******************************************************************************/
/*****************************************************************************/
/****************    Author    : Ahmed Ali             **********************/
/****************    SWC       : C App - School DB     *********************/
/****************    version   : 1.0.0                 ********************/
/*************************************************************************/
/************************************************************************/


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "Config.h"
#include "School.h"
#include "String.h"


static void setColor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
    SetConsoleTextAttribute(hStdOut, wColor);
}


ErrorState_t  List_create(List_t* pl)
{
    ErrorState_t ret= SUCCESS;
    if(pl == NULL)
    {
        ret= NULL_PTR;
    }
    else
    {
        pl->pHead= NULL;
        pl->pTail= NULL;
        pl->ListSize= 0;
    }
    return ret;
}


ErrorState_t  List_scanStudent(ListEntry_t * pe)
{
    ErrorState_t ret= SUCCESS;
    u32 readDecValue= 0;

    if(pe == NULL)
    {
        ret= NULL_PTR;
    }
    else
    {
        system("cls");
        setColor(9);
        printf("\n    Insert new student :");
        printf("\n    ====================\n\n");
        setColor(11);
        printf(">> Enter Student Name :");
        setColor(7);
        string_scan(pe->Name, NAMESIZE);
        fflush(stdin);
        setColor(11);
        printf(">> Enter Student ID :");
        setColor(7);
        scanf("%d", &readDecValue);
        pe->ID= (u8)readDecValue;
        setColor(11);
        printf(">> Enter Student Age :");
        setColor(7);
        scanf("%d", &readDecValue);
        pe->age= (u8)readDecValue;
        setColor(11);
        printf(">> Enter Student Phone :");
        setColor(7);
        scanf("%d", &pe->data.phone);
        setColor(11);
        printf(">> Enter Student Address :");
        setColor(7);
        string_scan(pe->data.address, ADRESSSIZE);
        fflush(stdin);
        setColor(11);
        pe->degress.math_deg= 0;
        pe->degress.english_deg= 0;
        pe->degress.arabic_deg= 0;
    }
    return ret;
}


ErrorState_t  List_insertStudent( List_t* pl, const ListEntry_t * pe)
{
    ErrorState_t ret= SUCCESS;

    if(pl == NULL || pe == NULL)
    {
        ret= NULL_PTR;
    }
    else
    {
        ListNode_t * temp= pl->pHead;
        ListNode_t * Entry_Object= (ListNode_t *)malloc(sizeof(ListNode_t));

        if(Entry_Object == NULL)
        {
#if ENABLE_DEBUGGING == ENABLE
            printf("\nDebug==> Not available space, DA -> NULL_PTR\n");
            Sleep(3000);
#endif
            ret= NULL_PTR;
        }
        else
        {

            Entry_Object->entry= *pe;

            if(pl->ListSize == 0) /** Empty List **/
            {
#if ENABLE_DEBUGGING == ENABLE
                printf("\nDebug==> Empty List, Insert @ Head\n");
                Sleep(3000);
#endif
                pl->pHead= Entry_Object;
                pl->pTail= Entry_Object;
                Entry_Object->pNext= NULL;
                Entry_Object->pPrev= NULL;
                (pl->ListSize)++;
            }
            else
            {
                while((temp != NULL) && (string_compare((temp->entry.Name), (u8 *)(pe->Name)) == -1))
                {
                    temp= temp->pNext;
                }

                if(temp == (pl->pHead))  /** Insert @ Head **/
                {
#if ENABLE_DEBUGGING == ENABLE
                    printf("\nDebug==> Insert @ Head\n");
                    Sleep(3000);
#endif
                    pl->pHead->pPrev= Entry_Object;
                    Entry_Object->pNext= pl->pHead;
                    Entry_Object->pPrev= NULL;
                    pl->pHead= Entry_Object;
                    (pl->ListSize)++;
                }
                else if(temp == NULL)  /** Insert @ Tail **/
                {
#if ENABLE_DEBUGGING == ENABLE
                    printf("\nDebug==> Insert @ Tail\n");
                    Sleep(3000);
#endif
                    Entry_Object->pPrev= pl->pTail;
                    Entry_Object->pPrev->pNext= Entry_Object;
                    pl->pTail= Entry_Object;
                    pl->pTail->pNext= NULL;
                    (pl->ListSize)++;
                }
                else
                {
#if ENABLE_DEBUGGING == ENABLE
                    printf("\nDebug==> Insert @ Middle\n");
                    Sleep(3000);
#endif
                    temp->pPrev->pNext= Entry_Object;
                    Entry_Object->pPrev= temp->pPrev;
                    temp->pPrev= Entry_Object;
                    Entry_Object->pNext= temp;
                    (pl->ListSize)++;
                }
            }
        }
    }

    return ret;
}



ErrorState_t  List_searchStudent(const List_t* pl, u8 copy_u8ID,ListNode_t ** pFoundStudent )
{
    ErrorState_t ret= SUCCESS;
    if((pl == NULL) || (pFoundStudent == NULL))
    {
        ret= NULL_PTR;
    }
    else if(pl->ListSize == 0) /** Empty List **/
    {
        setColor(12);
        printf("\n\n  >> Class is Empty <<\n");
        setColor(7);
        ret= OUT_OF_RANGE_ERR;
    }
    else
    {
        ListNode_t * temp= pl->pHead;
        while((temp != NULL) && (temp->entry.ID != copy_u8ID))
        {
            temp= temp->pNext;
        }
        if(temp == NULL)
        {
#if ENABLE_DEBUGGING == ENABLE
            printf("Not Found\n");
#endif // ENABLE_DEBUGGING
            setColor(4);
            printf("\n\n  >> Student Not Found <<\n");
            setColor(7);
            *pFoundStudent= NULL;
            ret= OUT_OF_RANGE_ERR;
        }
        else
        {
            *pFoundStudent= temp;
        }
    }
    return ret;
}

ErrorState_t  List_deleteStudent(List_t* pl, u8 copy_u8ID)
{
    ErrorState_t ret= SUCCESS;
    if(pl == NULL)
    {
        ret= NULL_PTR;
    }
    else
    {
        u32 option;
        ListNode_t * temp= NULL;
        ret= List_searchStudent(pl, copy_u8ID, &temp);

        if(ret == SUCCESS)
        {
            setColor(14);
            printf("\n  > Name : %s\n", temp->entry.Name);
            printf("  > ID   : %d\n", temp->entry.ID);
            setColor(12);
            printf("\n > Are you sure to delete this student ?\n");
            setColor(11);
            printf("\n > Press 1 to delete, 0 to discard :");
            setColor(7);
            scanf("%d", &option);
            if(option == 1)
            {
                if((pl->ListSize == 1)) /*** Delete the lonely element ***/
                {
                    free(temp);
                    pl->pHead= NULL;
                    pl->pTail= NULL;
                    pl->ListSize= 0;
                }
                else if(temp->pPrev == NULL)          /*** Delete from the Head ***/
                {
                    //printf("Debug\n");
                    pl->pHead->pNext->pPrev= NULL;
                    pl->pHead= temp->pNext;
                    free(temp);
                    (pl->ListSize)--;
                }
                else if(temp->pNext == NULL)     /*** Delete from the Tail ***/
                {
                    temp->pPrev->pNext= NULL;
                    pl->pTail= temp->pPrev;
                    free(temp);
                    (pl->ListSize)--;
                }
                else                             /*** Delete from the Middle ***/
                {
                    temp->pNext->pPrev= temp->pPrev;
                    temp->pPrev->pNext= temp->pNext;
                    free(temp);
                    (pl->ListSize)--;
                }
            }
            else
            {
                ret= SUCCESS;
            }

        }
        else
        {
            ret= OUT_OF_RANGE_ERR;
        }
    }
    return ret;
}

ErrorState_t  List_updatePersonal(ListNode_t * pe)
{
    ErrorState_t ret= SUCCESS;
    u32 scanDecVal;

    if(pe == NULL)
    {
        ret= NULL_PTR;
    }
    else
    {
        updatePersonalState_t option;
        setColor(15);
        //printf("\n     1 > Edit Name.\n");
        // printf("     2 > Edit ID.\n");
        printf("\n     1 > Edit Age.\n");
        printf("     2 > Edit Phone.\n");
        printf("     3 > Edit Address.\n");
        setColor(11);
        printf("\n > Enter a number of operation that needed : ");
        setColor(7);
        scanf("%d", (u32 *)&option);

        switch(option)
        {
        /*
        case EDIT_NAME:
        setColor(6);
        printf("\nCurrent Name : %s\n", pe->entry.Name);
        setColor(11);
        printf("Enter new Name : ");
        setColor(7);
        string_scan(pe->entry.Name, NAMESIZE);
        break;

        case EDIT_ID:
        setColor(6);
        printf("\nCurrent ID : %d\n", pe->entry.ID);
        setColor(11);
        printf("Enter new ID : ");
        setColor(7);
        scanf("%d", &scanDecVal);
        pe->entry.ID= (u8)scanDecVal;
        break;
        */
        case EDIT_AGE:
            setColor(6);
            printf("\nCurrent Age : %d\n", pe->entry.age);
            setColor(11);
            printf("Enter new Age : ");
            setColor(7);
            scanf("%d", &scanDecVal);
            pe->entry.age= (u8)scanDecVal;
            break;

        case EDIT_PHONE:
            setColor(6);
            printf("\nCurrent Phone : %d\n", pe->entry.data.phone);
            setColor(11);
            printf("Enter new Phone : ");
            setColor(7);
            scanf("%d", &(pe->entry.data.phone));
            break;

        case EDIT_ADDRESS:
            setColor(6);
            printf("Current Address : %s\n", pe->entry.data.address);
            setColor(11);
            printf("Enter new Address : ");
            setColor(7);
            string_scan(pe->entry.data.address, ADRESSSIZE);
            break;

        default:
            ret= OUT_OF_RANGE_ERR;
            setColor(4);
            printf("\n    Wrong option, Try again!\n");
            break;
        }
    }

    return ret;
}


ErrorState_t  List_updateScore(ListNode_t * pe)
{
    ErrorState_t ret= SUCCESS;
    u32 scanDecVal;

    if(pe == NULL)
    {
        ret= NULL_PTR;
    }
    else
    {
        updatePersonalState_t option;
        setColor(15);
        printf("\n     1 > Edit Math score.\n");
        printf("     2 > Edit English score.\n");
        printf("     3 > Edit Arabic score.\n");
        setColor(11);
        printf("\n > Enter a number of operation that needed : ");
        setColor(7);
        scanf("%d", (u32 *)&option);

        switch(option)
        {
        case EDIT_MATH:
            setColor(9);
            printf("\n  ==> Math :\n\n");
            setColor(6);
            printf("Current score : %d\n", pe->entry.degress.math_deg);
            setColor(11);
            printf("Enter new score : ");
            setColor(7);
            scanf("%d", &scanDecVal);
            pe->entry.degress.math_deg= (u8)scanDecVal;
            break;

        case EDIT_ENGLISH:
            setColor(9);
            printf("\n  ==> English :\n\n");
            setColor(6);
            printf("Current score : %d\n", pe->entry.degress.english_deg);
            setColor(11);
            printf("Enter new score : ");
            setColor(7);
            scanf("%d", &scanDecVal);
            pe->entry.degress.english_deg= (u8)scanDecVal;
            break;

        case EDIT_ARABIC:
            setColor(9);
            printf("\n  ==> Arabic :\n\n");
            setColor(6);
            printf("Current score : %d\n", pe->entry.degress.arabic_deg);
            setColor(11);
            printf("Enter new score : ");
            setColor(7);
            scanf("%d", &scanDecVal);
            pe->entry.degress.arabic_deg= (u8)scanDecVal;
            break;

        default:
            ret= OUT_OF_RANGE_ERR;
            setColor(4);
            printf("\n    Wrong option, Try again!\n");
            break;
        }
    }

    return ret;
}


ErrorState_t  List_editStudent(const List_t* pl, u8 copy_u8ID)
{
    ErrorState_t ret= SUCCESS;
    if(pl == NULL)
    {
        ret= NULL_PTR;
    }
    else
    {
        ListNode_t * temp= NULL;
        updateDataState_t update_data;

        ret= List_searchStudent(pl, copy_u8ID, &temp);

        if(ret == SUCCESS)
        {
            system("cls");
            setColor(9);
            printf("\n    Edit student :");
            printf("\n    ==============\n\n");
            setColor(15);
            printf("     1 > Update Personal Data.\n");
            printf("     2 > Update Subject Data.\n");
            setColor(11);
            printf("\n > Enter a number of operation that needed : ");
            setColor(7);
            scanf("%d", (u32 *)&update_data);

            switch(update_data)
            {
            case UPDATE_PERSONAL_DATA:
                ret= List_updatePersonal(temp);
                break;

            case UPDATE_SCORE_DATA:
                ret= List_updateScore(temp);

                break;

            default:
                ret= OUT_OF_RANGE_ERR;
                setColor(4);
                printf("\n    Wrong option, Try again!\n");
                break;
            }
        }
        else
        {
            ret= OUT_OF_RANGE_ERR;
        }
    }

    return ret;
}


ErrorState_t  List_printStudent(const List_t* pl, u8 copy_u8ID)
{
    ErrorState_t ret= SUCCESS;
    if(pl == NULL)
    {
        ret= NULL_PTR;
    }
    else
    {
        ListNode_t * temp= NULL;

        ret= List_searchStudent(pl, copy_u8ID, &temp);

        if(ret == SUCCESS)
        {
            setColor(9);
            printf("\n   ========== Student Data  ==========\n");
            setColor(15);
            printf("    - Name    : %s\n", temp->entry.Name);
            printf("    - ID      : %d\n", temp->entry.ID);
            printf("    - Age     : %d\n", temp->entry.age);
            setColor(9);
            printf("   ========== Personal Data ==========\n");
            setColor(15);
            printf("    - Phone   : %d\n", temp->entry.data.phone);
            printf("    - Address : %s\n", temp->entry.data.address);
            setColor(9);
            printf("   ==========  Score Data   ==========\n");
            setColor(15);
            printf("    - Math    : %d\n", temp->entry.degress.math_deg);
            printf("    - English : %d\n", temp->entry.degress.english_deg);
            printf("    - Arabic  : %d\n", temp->entry.degress.arabic_deg);
            setColor(9);
            printf("   ===================================\n");
            setColor(7);

        }
        else
        {
            ret= OUT_OF_RANGE_ERR;
        }
    }
    return ret;
}


ErrorState_t  List_callStudent(const List_t* pl, u8 copy_u8ID)
{
    ErrorState_t ret= SUCCESS;
    if(pl == NULL)
    {
        ret= NULL_PTR;
    }
    else
    {
        ListNode_t * temp= NULL;

        ret= List_searchStudent(pl, copy_u8ID, &temp);

        if(ret == SUCCESS)
        {
            setColor(9);
            printf("\n========== Call Student ==========\n");
            setColor(15);
            printf("Name    : %s\n", temp->entry.Name);
            printf("Phone   : %d\n", temp->entry.data.phone);
            setColor(7);
            for(int i=0; i<10; i++)
            {
                setColor(i+1);
                printf(",,");
                Sleep(100);
                printf(",,");
                Sleep(100);
                printf(",,");
                Sleep(100);
                printf(",,");
                Sleep(100);
                printf(",,");
                Sleep(100);
                printf("\b \b\b \b");
                Sleep(100);
                printf("\b \b\b \b");
                Sleep(100);
                printf("\b \b\b \b");
                Sleep(100);
                printf("\b \b\b \b");
                Sleep(100);
            }
            setColor(4);
            printf("     No answer.");
            setColor(7);
        }
        else
        {
            ret= OUT_OF_RANGE_ERR;
        }
    }

    return ret;
}


ErrorState_t  List_printList(const List_t* pl )
{
    ErrorState_t ret= SUCCESS;
    if(pl == NULL)
    {
        ret= NULL_PTR;
    }
    else
    {
        if(pl->ListSize == 0)
        {
            setColor(12);
            printf("\n   >> Class is Empty <<\n");
        }
        else
        {
            system("cls");
            setColor(9);
            printf("\n  > Class size / Max size : %d / %d", pl->ListSize, CLASSSIZE);
            printf("\n  ==================================\n");
            ListNode_t *temp= pl->pHead;
            setColor(6);
            printf("   =====+======================\n");
            printf("  | ID  |        Name          |\n");
            printf("   =====+======================\n");
            setColor(14);
            while(temp != NULL)
            {
                printf("  | %-4d|  %-20s|\n", temp->entry.ID, temp->entry.Name);
                printf("   -----+----------------------\n");
                temp= temp->pNext;
            }
        }
    }
    return ret;
}

ErrorState_t  List_listSize(const List_t* pl,u32 * pSize)
{
    ErrorState_t ret= SUCCESS;
    if((pl == NULL) || (pSize == NULL))
    {
        ret= NULL_PTR;
    }
    else
    {
        *pSize= pl->ListSize;
    }
    return ret;
}

ErrorState_t  List_freeList(List_t* pl)
{
    ErrorState_t ret= SUCCESS;

    if(pl == NULL)
    {
        ret= NULL_PTR;
    }
    else
    {
        if(pl->pHead == NULL)
        {
            ret= OUT_OF_RANGE_ERR;
        }
        else
        {
            u32 option;
            setColor(12);
            printf("\n > Are you sure to Free this Class ?\n");
            setColor(11);
            printf("\n > Press 1 to Free, 0 to discard :");
            setColor(7);
            scanf("%d", &option);
            if(option == 1)
            {
                ListNode_t * temp= pl->pHead;
                ListNode_t * ptr;
                while(temp != NULL)
                {
                    ptr= temp->pNext;
                    free(temp);
                    temp= ptr;
                }
                pl->pHead= NULL;
                pl->pTail= NULL;
                pl->ListSize= 0;
            }
            else
            {
                ret= SUCCESS;
            }
        }
    }

    return ret;
}

