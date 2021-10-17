#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"functionproto.h"
#include"fundef.h"
 int main()
 {
   int choice,again,result;
   char stud[50];
  node*head=NULL;
  head=create_all(head);
  while(1)
  {
    printf("1-- Insert student name in the front of the list\n2--Insert student name at the end of the list\n3--Insert a record after a given name in the list\n4--Search a given student in the list\n5--Delete a given student\n6--Display all student names\n7--Display the students in alphabetical order\n");
    scanf("%d",&choice);
   if(choice==1)
      head=insertfirst(head);
   else if(choice==2)
      head=insertlast(head);
    else if(choice==3)
      head=insAfterName(head);
    else if(choice==4)
     { printf("enter name of student search : ");
       scanf("%s",stud);
       result=search_student(head,stud);
       if(result!=-1)
          printf("%s is present in the position %d\n",stud,result);
       else
          printf("%s is not present \n",stud);
     }  
    else if(choice==5)
    {
     printf("enter name of student to delete : ");
      scanf("%s",stud);
       
     head=delete_student(head,stud);
    }  
    else if(choice==6)
      display(head);
    else if(choice==7)
      {  displayInAlphabetical(head);
         display(head);
          }

   printf("do you want to continue operations with same input enter -1-  : ");
   scanf("%d",&again);
   if(again!=1)
    break;
 }
 }
/*
SAMPLE I/O:
aswin@aswin-pavilion-15:~/Desktop/sem3/data structures in c/lab/programs/ex4$ gcc stud-1.c -o 1
aswin@aswin-pavilion-15:~/Desktop/sem3/data structures in c/lab/programs/ex4$ ./1
enter size : 4
enter name of student 1 : aaaaaa
enter name of student 2 : ccccc
enter name of student 3 : bbbb
enter name of student 4 : aa
1-- Insert student name in the front of the list
2--Insert student name at the end of the list
3--Insert a record after a given name in the list
4--Search a given student in the list
5--Delete a given student
6--Display all student names
7--Display the students in alphabetical order
1
enter name to insert first in list: qqqqqqqqq
NAME ADDED IN FRONT 
do you want to continue operations with same input enter -1-  : 1
1-- Insert student name in the front of the list
2--Insert student name at the end of the list
3--Insert a record after a given name in the list
4--Search a given student in the list
5--Delete a given student
6--Display all student names
7--Display the students in alphabetical order
6
qqqqqqqqq
aaaaaa
ccccc
bbbb
aa
do you want to continue operations with same input enter -1-  : 1
1-- Insert student name in the front of the list
2--Insert student name at the end of the list
3--Insert a record after a given name in the list
4--Search a given student in the list
5--Delete a given student
6--Display all student names
7--Display the students in alphabetical order
7
16
97
14
2
15
14
aa
aaaaaa
bbbb
ccccc
qqqqqqqqq

*/
