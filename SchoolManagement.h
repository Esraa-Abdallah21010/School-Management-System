#ifndef SCHOOL_MANAGEMENT_H
#define SCHOOL_MANAGEMENT_H

#include "STD_TYPES.h"

/***************************************************** Start Struct ********************************************************/


 /* Data --> details of the student such as name, date of birth, ID, address , phone number and score .*/
typedef struct {
    u8 StudentName[30];     /* To store the student's name.*/
    u8 StudentBirth[15];    /* To store the student's birth.*/
    u32 StudentID;          /* To store the student's ID. */
    u8 StudentAddress[10]; /* To store the student's address.*/
    u8 StudentPhone[12];    /* To store the student's phone.*/
    f32 StudentScore;       /* To store the student's computer science score */
}Data_t;

/* Node for single linked list */
typedef struct Student{
    Data_t Data;           /* Node Data */
    struct Student *link;  /* Node Link is carry address next node*/
}Student_t;

/************************************************************* End *************************************************************/

/************************************************* Start Function Declarations *************************************************/

 void MAIN_MENU (void);
 void NEW_STUDENT (Student_t **list);
s32 my_memcmp(const void *str1, const void *str2, u32 n);
Student_t * Sort_Name (Student_t **list);
 void STUDENT_LIST(Student_t **list);
 void STUDENT_EDIT(Student_t **list);
 void STUDENT_SCORE(Student_t **list);
 void DELETE_STUDENT(Student_t **list);
 Student_t * Sort_Score (Student_t **list);
 void RANK_STUDENT (Student_t **list);
/************************************************************** End ************************************************************/


#endif