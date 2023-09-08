
/******************************************************************************/
/*****************************************************************************/
/****************    Author    : Ahmed Ali             **********************/
/****************    SWC       : C App - School DB     *********************/
/****************    version   : 1.0.0                 ********************/
/*************************************************************************/
/************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "Config.h"
#include "School.h"
#include "String.h"
#include "Application.h"


static void setColor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
    SetConsoleTextAttribute(hStdOut, wColor);
}


static void school_panner(void)
{
    u8 jumpControlAtBottom = 0;
    u8 shiftControl = 0;
    u8 panner[] =
        "                                                                                       \n\
                        EE       EE EEEEE  E       EEEEE     EEEEE       EE   EE    EEEEE       \n\
                        EE   E   EE E      E     EE        EE     EE    EE E E EE   E           \n\
                        EE   E   EE EEEEE  E    EE        EE       EE  EE   E   EE  E EEE       \n\
                         EE E E EE  E      E     EE        EE     EE   EE   E   EE  E           \n\
                          EE   EE   EEEEE  EEEEE   EEEEE     EEEEE     EE       EE  EEEEE       \n\
                                                                                                \n\
                                                                                                \n\
                                           EEEEE     EE   EE  EE EEEE                           \n\
                                         EE     EE   EE   EE  EEE                               \n\
                                        EE       EE  EE   EE  EE                                \n\
                                         EE     EE   EE   EE  EE                                \n\
                                           EEEEE      EEEEE   EE                                \n\
                                                                                                \n\
                      Embedded systems                                                          \n\
                                                                                EE              \n\
                         EEEEE             EE                                   EE              \n\
                        EE                 EE                                   EE              \n\
                        EE          EEEEE  EE           EEEEE        EEEEE      EE              \n\
                         EEEEE    EE       EE         EE     EE    EE     EE    EE              \n\
                             EE  EE        EEEEEEEE  EE       EE  EE       EE   EE              \n\
                             EE   EE       EE    EE   EE     EE    EE     EE    EE              \n\
                         EEEEE      EEEEE  EE    EE     EEEEE        EEEEE      EEEEEEEE        \n\
                                                                                                \n\
                                                              Author : Eng. Ahmed Ali           \n\
";
    for (jumpControlAtBottom = 0; jumpControlAtBottom < 30; ++jumpControlAtBottom)
    {
        printf("\n");
    }
    setColor(9);
    //fputs(panner,stdout);
    string_print(panner);
    setColor(7);
    for (shiftControl = 0; shiftControl < 30; shiftControl++)
    {
        Sleep(200);
        printf("\n");
    }
}


static ErrorState_t homePage(appMenuOptions_t * option)
{
    ErrorState_t ret= SUCCESS;

    if(option == NULL)
    {
        ret= NULL_PTR;
    }
    else
    {
        u8 home[] =
            "     ============================\n\
    | Embedded Systems School DB |\n\
     ============================\n\
    ";
        setColor(3);
        printf("\n");
        string_print(home);
        setColor(15);
        printf("     1 > Insert Student.\n");
        printf("     2 > Edit Student.\n");
        printf("     3 > Print Student.\n");
        printf("     4 > Delete Student.\n");
        printf("     5 > Call Student.\n");
        printf("     6 > Class Print.\n");
        printf("     7 > Class Free.\n");
        printf("     8 > School Size.\n");
        printf("     9 > School Free & Exit.\n");
        setColor(11);
        printf("\n > Enter the number of operation : ");
        setColor(7);
        scanf("%d", (u32 *)option);
    }

    return ret;
}


static ErrorState_t insertStaticStudents(List_t * Classes)
{
    ErrorState_t ret= SUCCESS;

    if(Classes == NULL)
    {
        ret= NULL_PTR;
    }
    else
    {
        /**** These student variables are local and will be deleted after function returns ****/
        ListEntry_t static_student_1= {1, "Ahmed Ali", 26, {123456789, "NTI Automotive"}, {100, 99, 98}};
        ListEntry_t static_student_2= {2, "Abdallah Reda", 25, {123456789, "NTI Automotive"}, {97, 96, 95}};
        ListEntry_t static_student_3= {3, "Sherif Elsayed", 24, {123456789, "NTI Automotive"}, {94, 93, 92}};
        ListEntry_t static_student_4= {4, "Osama Hassan", 23, {123456789, "NTI Automotive"}, {91, 90, 89}};
        ListEntry_t static_student_5= {5, "Mahmoud Radwan", 25, {123456789, "NTI Automotive"}, {88, 87, 86}};
        ListEntry_t static_student_6= {6, "Amr Khaled", 22, {123456789, "NTI Automotive"}, {85, 84, 83}};
        ListEntry_t static_student_7= {7, "Bassel Osama", 24, {123456789, "NTI Automotive"}, {82, 81, 80}};
        ListEntry_t static_student_8= {8, "Mohamed Ehab", 26, {123456789, "NTI Automotive"}, {79, 78, 77}};
        ListEntry_t static_student_9= {9, "Belal Mohamed", 26, {123456789, "NTI Automotive"}, {100, 99, 98}};
        ListEntry_t static_student_10= {10, "Yousef Mohamed", 25, {123456789, "NTI Automotive"}, {97, 96, 95}};
        ListEntry_t static_student_11= {11, "Mina Samy", 24, {123456789, "NTI Automotive"}, {94, 93, 92}};
        ListEntry_t static_student_12= {12, "Ayman Emam", 23, {123456789, "NTI Automotive"}, {91, 90, 89}};
        ListEntry_t static_student_13= {13, "Amr Ahmed", 25, {123456789, "NTI Automotive"}, {88, 87, 86}};
        ListEntry_t static_student_14= {14, "Mariam Melad", 22, {123456789, "NTI Automotive"}, {85, 84, 83}};
        ListEntry_t static_student_15= {15, "Hassan Gamal", 24, {123456789, "NTI Automotive"}, {82, 81, 80}};
        ListEntry_t static_student_16= {16, "Mina Ashraf", 26, {123456789, "NTI Automotive"}, {79, 78, 77}};
        ListEntry_t static_student_17= {17, "Mohamed Hossam", 25, {123456789, "NTI Automotive"}, {88, 87, 86}};
        ListEntry_t static_student_18= {18, "Fatima Elzahraa", 22, {123456789, "NTI Automotive"}, {85, 84, 83}};
        ListEntry_t static_student_19= {19, "Ahmed Zaki", 24, {123456789, "NTI Automotive"}, {82, 81, 80}};
        ListEntry_t static_student_20= {20, "Ebraheem Ali", 26, {123456789, "NTI Automotive"}, {79, 78, 77}};
        ret= List_insertStudent(&Classes[CLASS_A], &static_student_1);
        ret= List_insertStudent(&Classes[CLASS_A], &static_student_2);
        ret= List_insertStudent(&Classes[CLASS_A], &static_student_3);
        ret= List_insertStudent(&Classes[CLASS_A], &static_student_4);
        ret= List_insertStudent(&Classes[CLASS_A], &static_student_5);
        ret= List_insertStudent(&Classes[CLASS_A], &static_student_6);
        ret= List_insertStudent(&Classes[CLASS_A], &static_student_7);
        ret= List_insertStudent(&Classes[CLASS_B], &static_student_8);
        ret= List_insertStudent(&Classes[CLASS_B], &static_student_9);
        ret= List_insertStudent(&Classes[CLASS_B], &static_student_10);
        ret= List_insertStudent(&Classes[CLASS_B], &static_student_11);
        ret= List_insertStudent(&Classes[CLASS_B], &static_student_12);
        ret= List_insertStudent(&Classes[CLASS_C], &static_student_13);
        ret= List_insertStudent(&Classes[CLASS_C], &static_student_14);
        ret= List_insertStudent(&Classes[CLASS_C], &static_student_15);
        ret= List_insertStudent(&Classes[CLASS_C], &static_student_16);
        ret= List_insertStudent(&Classes[CLASS_D], &static_student_17);
        ret= List_insertStudent(&Classes[CLASS_D], &static_student_18);
        ret= List_insertStudent(&Classes[CLASS_D], &static_student_19);
        ret= List_insertStudent(&Classes[CLASS_D], &static_student_20);
    }

    return ret;
}


static ErrorState_t classSelect(schoolClass_t * Class_state)
{
    ErrorState_t ret= SUCCESS;

    if(Class_state == NULL)
    {
        ret= NULL_PTR;
    }
    else
    {
        setColor(3);
        printf("\n    Select Class :");
        printf("\n    ==============\n\n");
        setColor(15);
        printf("     1 > Class A.\n");
        printf("     2 > Class B.\n");
        printf("     3 > Class C.\n");
        printf("     4 > Class D.\n");
        setColor(11);
        printf("\n > Enter Number of Class, (0 -> back to main menu) : ");
        setColor(7);
        scanf("%d", (u32 *)Class_state);
        if((*Class_state < 0) || (*Class_state > 4))
        {
            ret= OUT_OF_RANGE_ERR;
        }
        else
        {
            /* Do Nothing */
        }
    }

    return ret;
}


static ErrorState_t exitAppScreen(void)
{
    ErrorState_t ret= SUCCESS;

    setColor(14);
    printf("\n     ");
    printf("> Author : Eng. Ahmed Ali <");
    Sleep(500);
    printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
    printf("> Author : Eng. Ahmed Ali <");
    Sleep(500);
    printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
    printf("> Author : Eng. Ahmed Ali <");
    Sleep(500);
    printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
    printf("> Author : Eng. Ahmed Ali <");
    Sleep(500);
    printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
    printf("> Author : Eng. Ahmed Ali <");
    Sleep(500);
    printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
    printf("> Author : Eng. Ahmed Ali <");
    Sleep(500);
    printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
    printf("> Author : Eng. Ahmed Ali <");
    Sleep(500);
    printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
    printf("> Author : Eng. Ahmed Ali <");
    Sleep(500);
    printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
    printf("> Author : Eng. Ahmed Ali <");
    Sleep(2000);
    setColor(13);
    printf("\n\n            BYE BYE ^_^\n");
    Sleep(2000);
    setColor(7);

    return ret;
}



ErrorState_t schoolApp(void)
{
    ErrorState_t ret= SUCCESS;
    /************************* Local Variables ****************************/
    List_t Classes[NUMOFCLASSES]= {0};
    appMenuOptions_t option_state;
    schoolClass_t class_state;
    schoolState_t school_state= SCHOOL_RUN_STATE;
    tabState_t tab_state= RETURN_HOME;
    u32 ID;
    u32 List_Size;
    u32 School_Size= 0;

    /********************* Welcome Screen Animation ***********************/
    school_panner();

    /************* Create a Doubly linked list for every Class ************/
    for(class_state= CLASS_A; class_state<NUMOFCLASSES; class_state++)
    {
        ret= List_create(&Classes[class_state]);
    }

    /********************** Insert Static Students ************************/
    ret= insertStaticStudents(Classes);

    /*********** School Application Loop - Infinite state Loop ************/
    while(school_state == SCHOOL_RUN_STATE)
    {
        if(tab_state == RETURN_HOME)
        {
            system("cls");
            ret= homePage(&option_state);
            tab_state= CURRUNT_TAB;
        }
        else
        {
            /* Do Nothing */
        }
        /**************** Switch on Tabs ********************/
        switch(option_state)
        {
        /**************** INSERT_STUDENT ********************/
        case INSERT_STUDENT:

            system("cls");
            ret= classSelect(&class_state);
            if(ret == OUT_OF_RANGE_ERR)
            {
                setColor(4);
                printf("\n     > Wrong Option, Try again !");
                setColor(7);
                Sleep(2000);
            }
            else if(class_state == 0)
            {
                tab_state= RETURN_HOME;
            }
            else if(Classes[class_state-1].ListSize == CLASSSIZE)
            {
                setColor(12);
                printf("\n\n                ==========================\n");
                printf("             >>>  This Class is Complete  <<<\n");
                printf("                ==========================\n");
                Sleep(2000);
                setColor(7);
                tab_state= RETURN_HOME;
            }
            else
            {
                ListEntry_t * entry_student= (ListEntry_t *)malloc(sizeof(ListEntry_t));
                ret= List_scanStudent(entry_student);
                ret= List_insertStudent(&Classes[class_state-1], entry_student);
                free(entry_student);
                system("cls");
                setColor(10);
                printf("\n\n  >>> Student Inserted successfully <<< \n");
                setColor(11);
                printf("\n > Press 1 to insert new student , (0 -> back to main menu) : ");
                setColor(7);
                scanf("%d", (u32 *)&tab_state);
            }

            break;
        /**************** EDIT_STUDENT ********************/
        case EDIT_STUDENT:

            system("cls");
            ret= classSelect(&class_state);
            if(ret == OUT_OF_RANGE_ERR)
            {
                setColor(4);
                printf("\n     > Wrong Option, Try again !");
                setColor(7);
                Sleep(2000);
            }
            else if(class_state == 0)
            {
                tab_state= RETURN_HOME;
            }
            else
            {
                setColor(11);
                printf("\n Enter Student ID : ");
                setColor(7);
                scanf("%d", &ID);
                ret= List_editStudent(&Classes[class_state-1], ID);
                //system("cls");
                if(ret == SUCCESS)
                {
                    setColor(10);
                    printf("\n\n  >>> Student Edited successfully <<< \n");
                }
                else
                {
                    /* Do Nothing */
                }
                setColor(11);
                printf("\n > press 0 to back, 1 to edit new student : ");
                setColor(7);
                scanf("%d", (u32 *)&tab_state);
            }

            break;
        /**************** PRINT_STUDENT ********************/
        case PRINT_STUDENT:

            system("cls");
            ret= classSelect(&class_state);
            if(ret == OUT_OF_RANGE_ERR)
            {
                setColor(4);
                printf("\n     > Wrong Option, Try again !");
                setColor(7);
                Sleep(2000);
            }
            else if(class_state == 0)
            {
                tab_state= RETURN_HOME;
            }
            else
            {
                system("cls");
                setColor(11);
                printf("\n Enter Student ID : ");
                setColor(7);
                scanf("%d", &ID);
                ret= List_printStudent(&Classes[class_state-1], ID);
                setColor(11);
                printf("\n > press 0 to back, 1 to print new student : ");
                setColor(7);
                scanf("%d", (u32 *)&tab_state);
            }
            break;
        /**************** DELETE_STUDENT ********************/
        case DELETE_STUDENT:

            system("cls");
            ret= classSelect(&class_state);
            if(ret == OUT_OF_RANGE_ERR)
            {
                setColor(4);
                printf("\n     > Wrong Option, Try again !");
                setColor(7);
                Sleep(2000);
            }
            else if(class_state == 0)
            {
                tab_state= RETURN_HOME;
            }
            else
            {
                system("cls");
                setColor(11);
                printf("\n Enter Student ID : ");
                setColor(7);
                scanf("%d", &ID);
                ret= List_deleteStudent(&Classes[class_state-1], ID);
                if(ret == SUCCESS)
                {
                    setColor(10);
                    printf("\n >> Operation completed successfully <<\n");
                }
                else
                {
                    /* Do Nothing */
                }
                setColor(11);
                printf("\n > press 0 to back, 1 to Delete another student : ");
                setColor(7);
                scanf("%d", (u32 *)&tab_state);
            }

            break;
        /**************** CALL_STUDENT ********************/
        case CALL_STUDENT:

            system("cls");
            ret= classSelect(&class_state);
            if(ret == OUT_OF_RANGE_ERR)
            {
                setColor(4);
                printf("\n     > Wrong Option, Try again !");
                setColor(7);
                Sleep(2000);
            }
            else if(class_state == 0)
            {
                tab_state= RETURN_HOME;
            }
            else
            {
                system("cls");
                setColor(11);
                printf("\n Enter Student ID : ");
                setColor(7);
                scanf("%d", &ID);
                ret= List_callStudent(&Classes[class_state-1], ID);
                setColor(11);
                printf("\n\n > press 0 to back , 1 to call new student : ");
                setColor(7);
                scanf("%d", (u32 *)&tab_state);
            }
            break;
        /**************** CLASS_PRINT ********************/
        case CLASS_PRINT:

            system("cls");
            ret= classSelect(&class_state);
            if(ret == OUT_OF_RANGE_ERR)
            {
                setColor(4);
                printf("\n     > Wrong Option, Try again !");
                setColor(7);
                Sleep(2000);
            }
            else if(class_state == 0)
            {
                tab_state= RETURN_HOME;
            }
            else
            {
                ret= List_printList(&Classes[class_state-1]);
                setColor(11);
                printf("\n\n > press 0 to back , 1 to Print another class : ");
                setColor(7);
                scanf("%d", (u32 *)&tab_state);
            }

            break;

        /**************** CLASS_FREE ********************/
        case CLASS_FREE:

            system("cls");
            ret= classSelect(&class_state);
            if(ret == OUT_OF_RANGE_ERR)
            {
                setColor(4);
                printf("\n     > Wrong Option, Try again !");
                setColor(7);
                Sleep(2000);
            }
            else if(class_state == 0)
            {
                tab_state= RETURN_HOME;
            }
            else
            {
                system("cls");
                ret= List_freeList(&Classes[class_state-1]);
                if(ret == OUT_OF_RANGE_ERR)
                {
                    setColor(12);
                    printf("\n   Class is Empty\n");
                }
                else
                {
                    setColor(10);
                    printf("\n >> Operation completed successfully <<\n");
                }
                setColor(11);
                printf("\n\n > press 0 to back , 1 to Free another class : ");
                setColor(7);
                scanf("%d", (u32 *)&tab_state);
            }

            break;
        /**************** SCHOOL_SIZE ********************/
        case SCHOOL_SIZE:

            system("cls");
            setColor(9);
            printf("\n======== School Size ========\n");
            setColor(14);
            ret= List_listSize(&Classes[CLASS_A], &List_Size);
            School_Size+= List_Size;
            printf("\n  > Class A Size : %d / %d\n", List_Size, CLASSSIZE);
            ret= List_listSize(&Classes[CLASS_B], &List_Size);
            School_Size+= List_Size;
            printf("\n  > Class B Size : %d / %d\n", List_Size, CLASSSIZE);
            ret= List_listSize(&Classes[CLASS_C], &List_Size);
            School_Size+= List_Size;
            printf("\n  > Class C Size : %d / %d\n", List_Size, CLASSSIZE);
            ret= List_listSize(&Classes[CLASS_D], &List_Size);
            School_Size+= List_Size;
            printf("\n  > Class D Size : %d / %d\n", List_Size, CLASSSIZE);
            setColor(6);
            printf("\n  > School Size  : %d / %d\n", School_Size, SCHOOLSIZE);
            School_Size= 0;
            setColor(11);
            printf("\n\n > press 0 to back : ");
            setColor(7);
            scanf("%d", (u32 *)&tab_state);

            break;
        /**************** SCHOOL_FREE ********************/
        case SCHOOL_EXIT:

            setColor(12);
            printf("\n > Are you sure to Exit ?\n");
            setColor(11);
            printf("\n > Press 1 to Exit, 0 to discard : ");
            setColor(7);
            scanf("%d", (u32 *)&school_state);
            if(school_state != SCHOOL_EXIT_STATE)
            {
                ret= SCHOOL_RUN_STATE;
            }
            else
            {
                /* Do Nothing */
            }

            break;
        /**************** Default ********************/
        default:
            setColor(4);
            printf("\n     > Wrong Option, Try again !");
            setColor(7);
            tab_state= RETURN_HOME;
            Sleep(2000);
            break;

        }
    }

    /******** Exit Screen & Animation *********/
    ret= exitAppScreen();

    return ret;
}
