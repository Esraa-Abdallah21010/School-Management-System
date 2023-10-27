#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD_TYPES.h"
#include "SchoolManagement.h"

/*This function displays the welcome screen and targeted activates.*/
void MAIN_MENU (void)
{
    printf("                             _________________________________________  \n");
    printf("                            |                                         | \n");
    printf("                            | Welcome to the School Management System | \n");
    printf("                            |_________________________________________| \n\n\n\n");
    
}


/*************************************************** End ********************************************************/




/*this function creates a new student account. it asks about details of the student such as name,
 date of birth, ID, address , phone number and score.*/

void NEW_STUDENT(Student_t **list )
{
    u8 flag = 1;
    Student_t *One_Student = NULL; 
    Student_t *temp = *list; 
    One_Student = (Student_t *)malloc(sizeof(Student_t));   /*Reserve a place in heap (78 bytes )*/



    /* Memory check to verify if there is One_Student reserved space in heap
     (if memory full One_Student == NULL  , else One_Student!= NULL )*/

    if(NULL == One_Student)
    {
        printf("\n                            ******* This new student is NOT created *********\n");
    }
    else
    {


        /* check if the student is created before */ 

        do
        {
            printf("                            Please Enter student's ID        : ");
            scanf("%i",&(One_Student->Data.StudentID));
            while (getchar() != '\n');
            while (NULL != temp)
            {
                /*if the student is created before ----> flag=0*/
                if( One_Student->Data.StudentID == temp->Data.StudentID)
                {
                    printf("                            There is another student with the same ID.\n ");
                    flag = 0;
                    break;
                }
                /*if the student isn't created before ---> flag=1*/
                else
                {
                    flag =1;
                }
                temp = temp->link;
            }
            /*if the student is created before ----> flag=0 ,it request agin create id */
        }while(0 == flag);
        /* Enter Data */
        if(1==flag)
        {
            /*Enter Student's Name*/
            printf("                            Please Enter Student's Name      : ");
            /* input string Name from user*/
            for (u16 i=0;i<30;i++)
            {
                scanf("%c",&(One_Student->Data.StudentName[i]));
                if ('\n'==One_Student->Data.StudentName[i])
                {
                    One_Student->Data.StudentName[i]='\0';
                    break;
                }
                else{}
            }

            /*Ask to Enter Birth*/
            printf("                            Please Enter Student Year Birth  : ");
            /* input string Birth from user*/
            for (u16 i=0;i<15;i++)
            {
                scanf("%c",&(One_Student->Data.StudentBirth[i]));
                if ('\n'==One_Student->Data.StudentBirth[i])
                {
                    One_Student->Data.StudentBirth[i]='\0';
                    break;
                }
                else{}
            }

            /*Ask to Enter Phone*/
            printf("                            please enter Student phone number: ");
            /* input string phone from user*/
            for (u16 i=0;i<12;i++)
            {
                scanf("%c",&(One_Student->Data.StudentPhone[i]));
                if ('\n'==One_Student->Data.StudentPhone[i])
                {
                    One_Student->Data.StudentPhone[i]='\0';
                    break;
                }
                else{}
            }

            /*Ask to enter the address */
            printf("                            please enter Student address     : ");
            /* input string address from user*/
            for (u16 i=0;i<10;i++)
            {
                scanf("%c",&(One_Student->Data.StudentAddress[i]));
                if ('\n'==One_Student->Data.StudentAddress[i])
                {
                    One_Student->Data.StudentAddress[i]='\0';
                    break;
                }
                else{}
            }

            /*Ask to enter the score */
            printf("                            please enter Student score       : ");
            scanf("%f", &(One_Student->Data.StudentScore));
            

            /*check if the list is empty or not */
            if (NULL == *list)
            {
                One_Student->link = NULL;
                *list = One_Student;
            }
            else
            {
                One_Student->link = *list;
                *list = One_Student;
            }
            printf("\n\n                            ****** Student added successfully ******\n");
        }
        else{}

     }
}


/*************************************************** End ********************************************************/



/* The my_memcmp function is often used to compare strings */
s32 my_memcmp(const void *str1, const void *str2, u32 n)
{
    s32 returned = 0;
    u8 *s1 = (u8 *)str1;/* cast str1 */
    u8 *s2 = (u8 *)str2;
    if (str1 == str2)
    {
        returned = 0;
    }
    else
    {
        while ((NULL != s1) && (NULL != s2) && (n--))
        {
            if (*s1 > *s2)
            {
                returned = 1;

                break;
            }
            else if (*s1 < *s2)

            {

                returned = -1;
                break;
            }
            else
            {
                returned = 0;
            }
            s1++;
            s2++;
        }
    }
    return returned;
}
/* this function sort student name */
Student_t * Sort_Name (Student_t **list)
{
    Student_t  *temp1 = *list;
    Student_t  *temp2 = *list;
    s8 sp;
    /*check if the list is empty*/
    if (NULL == *list)
    {
        printf("                            the list is empty !!\n");
    }
    else
    {
        /* swap */
        while(NULL!=temp1)
        {
            temp2 = *list;
            while (NULL!=temp2)
            {
                sp = my_memcmp((temp1->Data.StudentName), (temp2->Data.StudentName), sizeof((temp1->Data.StudentName)));
                    if (sp < 0)
                    {
                        Data_t temp = temp1->Data;
                        temp1->Data = temp2->Data;
                        temp2->Data = temp;
                    }
                temp2=temp2->link;
            }
            temp1=temp1->link;
        }
    }
    return *list;
}


/*STUDENT_LIST() –this function, you can view the students information such as name, 
date of birth, ID, address and phone number in table form (alphabetically ascending).*/

void STUDENT_LIST(Student_t **list)
{
    Student_t  *temp = *list;
    
    /*check if the list is empty*/
    if (NULL == *list)
    {
        printf("                            the list is empty !!\n");
    }
    else
    {
        *list=Sort_Name (&temp);
        temp=*list;
        while (NULL != temp)
        {
            
            
            printf("                            ---------------------------------\n");
            printf("                            Student Name is    : %s \n", temp->Data.StudentName);
            printf("                            Student id is      : %d \n", temp->Data.StudentID);
            printf("                            Student birth is   : %s \n", temp->Data.StudentBirth);
            printf("                            Student phone is   : %s \n", temp->Data.StudentPhone);
            printf("                            Student address is : %s \n", temp->Data.StudentAddress);
            printf("                            Student score is   : %0.02f \n", temp->Data.StudentScore);
            printf("                            ---------------------------------\n");
            temp = temp->link;
        }
        printf("                            Operation completed successfully.\n");
    }
}


/*************************************************** End ********************************************************/


Student_t * Sort_Score (Student_t **list)
{
    Student_t *temp1 = *list;
    Student_t *temp2 = *list;
    while(NULL!=temp2)
        {
            temp1 = *list;
            while(NULL!=temp1)
            {
                if ((temp1->Data.StudentScore) <(temp2->Data.StudentScore))
                    {
                        Data_t temp = temp1->Data;
                        temp1->Data = temp2->Data;
                        temp2->Data = temp;
                    }
                    else{}
                temp1=temp1->link;
            }
            temp2=temp2->link;
        }

    return *list;
}

/* this function can sort all students according to computer science score. */
void RANK_STUDENT(Student_t **list)
{
    Student_t *temp = *list;

    /*check if the list is empty*/
    if (NULL == *list)
    {
        printf("                            the list is empty !!\n");
    }
    else
    {
        /*swap two node*/
        *list=Sort_Score (&temp);
        temp =*list;
        while (NULL != temp)
        {
            
            
            printf("                            ---------------------------------\n");
            printf("                            Student Name is    : %s \n", temp->Data.StudentName);
            printf("                            Student id is      : %d \n", temp->Data.StudentID);
            printf("                            Student birth is   : %s \n", temp->Data.StudentBirth);
            printf("                            Student phone is   : %s \n", temp->Data.StudentPhone);
            printf("                            Student address is : %s \n", temp->Data.StudentAddress);
            printf("                            Student score is   : %0.02f \n", temp->Data.StudentScore);
            printf("                            ---------------------------------\n");
            temp = temp->link;
        }

        
    }
    printf("\n                            sorted successfully \n");

}

/*************************************************** End ********************************************************/


/* STUDENT_EDIT() – this function has been used for updating a particular student account. */

 void STUDENT_EDIT(Student_t **list)
 {
    Student_t *temp = *list;
    u32 id = 0;
    u32 op = 0;

    /* Check if the list is empty */
    if (NULL == temp)
    {
        printf("                            The student list is empty!\n");
    }
    else
    {
        /* Ask the user to input the student id */
        printf("                            Enter the student ID: ");
        scanf("%d", &id);

        while (NULL != temp)
        {
            if (id == temp->Data.StudentID)
            {
                break;
            }
            else{}
            temp = temp->link;
        }

        /* Check if the student ID is found */
        if (NULL == temp)
        {
            printf("                            Student ID not found.\n");
        }
        else
        {
            printf("                            Editing student with ID %d:\n", temp->Data.StudentID);
            do
            {
                printf("                            *********************************\n");
                printf("                            *        Options:               *\n");
                printf("                            * ------------------------------*\n");
                printf("                            * 1 -> Edit student name        *\n");
                printf("                            * 2 -> Edit student ID          *\n");
                printf("                            * 3 -> Edit student birth       *\n");
                printf("                            * 4 -> Edit student phone       *\n");
                printf("                            * 5 -> Edit student address     *\n");
                printf("                            * 6 -> Edit student score       *\n");
                printf("                            * 0 -> Exit                     *\n");
                printf("                            *********************************\n");
                printf("                            >> ");
                scanf("%d", &op);
                while (getchar() != '\n');
                /* updating data */
                switch (op)
                {
                case 1:
                    printf("                            Enter new student name: ");
                    /* fgets library function that reads a line of text from a stream */
                    fgets(temp->Data.StudentName, sizeof(temp->Data.StudentName), stdin);
                    printf("                            Name updated successfully.\n");
                    break;

                case 2:
                    printf("                            Enter new student ID: ");
                    scanf("%d", &(temp->Data.StudentID));
                    printf("                            ID updated successfully.\n");
                    break;

                case 3:
                    printf("                            please enter Student year birth (y/m/d): ");
                    for (int i=0;i<15;i++)
                    {
                        scanf("%c",&(temp->Data.StudentBirth[i]));
                        if ('\n'==temp->Data.StudentBirth[i])
                        {
                            temp->Data.StudentBirth[i]='\0';
                            break;
                        }
                    }
                    printf("                            Birthdate updated successfully.\n");
                    break;

                case 4:
                    printf("                            Enter new student phone: ");
                    scanf("%s", &(temp->Data.StudentPhone));
                    printf("                            Phone number updated successfully.\n");
                    break;

                case 5:
                    printf("                            Enter new student address: ");
                    fgets(temp->Data.StudentAddress, sizeof(temp->Data.StudentAddress), stdin);
                    printf("                            Address updated successfully.\n");
                    break;

                case 6:
                    printf("                            Enter new student score: ");
                    scanf("%f", &(temp->Data.StudentScore));
                    printf("                            Score updated successfully.\n");
                    break;

                case 0:
                    printf("                            Editing completed.\n");
                    break;

                default:
                    printf("                            Invalid operation. Please choose a valid option.\n");
                    break;
                }
            } while (op != 0);
        }
    }

 }
 /*************************************************** End ********************************************************/


/* STUDENT_SCORE() – this function has been used for updating score of all students.*/

void STUDENT_SCORE(Student_t **list)
{
    Student_t *temp = *list;
    u32 id = 0, op = 0;
    /*chek if the list is empty*/
    if (NULL == temp)
    {
        printf("                            the list is empty !!\n");
    }
    else
    {
        do
        {

            /*ask the user to input the student id*/
            printf("                            Enter student id : ");
            scanf("%d", &id);
            while (NULL != temp)
            {
                if (id == (temp->Data.StudentID))
                {
                    break;
                }
                else{}
                temp = temp->link;
            }
            /*check if student id is founded*/
            if (NULL == temp)
            {
                printf("                            this Student id is not founded \n");
            }
            else
            {
                /*ask the user to updata the score*/
                printf("                            enter new score \n");
                printf("                            >> ");
                scanf("%f", &(temp->Data.StudentScore));
                printf("                            *** Done ***\n");
            }

            /*ask the user to conitiue or exist  */
            printf("                            ************************\n");
            printf("                            *to continue enter : 1 *\n");
            printf("                            *to exist enter    : 0 *\n");
            printf("                            ************************\n");
            printf("                            >> ");
            scanf("%d", &op);
            /*return temp to the head*/
            temp = *list;

        } while (op != 0);
    }
}


 /*************************************************** End ********************************************************/


/* DELETE_STUDENT() – this function is for deleting a customer account. */

void DELETE_STUDENT(Student_t **list)
{
    u32 id = 0;
    u32 flag = 0;
    Student_t *temp = *list;
    Student_t *prev = NULL; // Pointer to the previous node

    /* Check if the list is empty */
    if (temp == NULL)
    {
        printf("                            List is empty !!\n");
        return;
    }

    /* Ask the user to input student id */
    printf("                            Enter student id to delete: ");
    scanf("%d", &id);
    /*check if student id is founded*/
    while (temp != NULL)
    {
        if (id == temp->Data.StudentID)
        {
            flag = 1;
            break;
        }
        else{}
        prev = temp;
        temp = temp->link;
    }

    if (flag == 1)
    {
        if (prev == NULL)
        {
            /* If the first node is to be deleted */
            *list = temp->link;
        }
        else
        {
            prev->link = temp->link;
        }
        free(temp); // Free the memory for the deleted node
        printf("                            Student with ID %d deleted successfully.\n", id);
    }
    else
    {
        printf("                            Student with ID %d not found in the list.\n", id);
    }
}
/*************************************************** End ********************************************************/




