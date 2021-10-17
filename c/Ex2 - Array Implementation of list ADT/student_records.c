/* ex 2
  Perform the following operations
1. Insert a record in the front of the list
2. Insert a record at the end of the list
3. Insert a record after a given Regno in the list
4. Search a given record in the list based on Name
5. Delete a given student record
6. Display all students’ record
7. Display the previous and next record of a given studen
*/
#include<stdio.h>
#include<string.h>
#include"structandfun.h"
#include"funprototypes.h"

int main()
{
   int i,size,choice,inreg,result,again;
   char sname[20];
   struct student srecord[50];
   struct student a[1];

   printf("enter how many student records you are going to give: ");
   scanf("%d",&size);
   for(i=0;i<size;i++)
   	input(srecord,i);
   while(1)
   {
   printf("1- Insert a record in the front of the list\n2- Insert a record at the end of the list\n3- Insert a record after a given Regno in the list\n4- Search a given record in the list based on Name\n5- Delete a given student record\n6- Display all students’ record\n7- Display the previous and next record of a given student\n ");
   scanf("%d",&choice);
   if(choice==1)
   { 
   	  input(a,0);
   	  insertfirst(srecord,a,size);
   	  size++;


   }
   else if(choice==2)
   {
   	input(a,0);
   	insertlast(srecord,a,size);
   	size++;
   }
   else if(choice==3)
   {
   	printf("enter regno  : ");
   	scanf("%d",&inreg);
   	input(a,0);
   	result=insert_regno(srecord,a,size,inreg);
   	if(result==-1)
   		printf("entered regno is not matched with any others\n ");
   	else 
   		size++;
   }
   else if(choice==4)
   {
   	printf("enter name : ");
   	scanf("%s",sname);
   	result=search_name(srecord,sname,size);
   	if(result==-1)
   		printf("entered name is not in the student records\n");
   	else
   		printf("yes  %s is in the record in position %d\n",sname,result+1);

   }
   else if(choice==5)
  {
  	printf("enter regno of the student whose record should deleted  : ");
   	scanf("%d",&inreg);
    result=delete_rec(srecord,size,inreg);
   if(result==-1)
    printf("the regno you entered is not available in the record\n");
   else
   {
   	size--;
   	printf("record has been deleted which is in the position %d\n",result+1);
   }
  }
  else if(choice==6)
  {
  	displayall(srecord,size);
  }
  else if(choice==7)
  {
  	printf("enter regno of the student to next and previous student detials: ");
   	scanf("%d",&inreg);
   	result=previous_next(srecord,size,inreg);
   	if(result==-1)
    printf("the regno you entered is not available in the record\n");
   else
   {
   	printf("record of previous and next student are : \n");
   	if(result==0)
   	    display(srecord,size,result+1);
    else if(result==size)
    	display(srecord,size,result+1);
    else
    {
    	display(srecord,size,result-1);
    	display(srecord,size,result+1);
    }

   }


  }
  if(choice<0||choice>7)
  {
  	printf("enter correct choice \n");
  	continue;
  }
  printf("press 1 to continue use other operations with given input else press some other number\n");
  scanf("%d",&again);
  if(again!=1)

  	break;

}   
}


   
    
   
/*
SAMPLE I/O : 

aswin@aswin-HP-Pavilion-Laptop-15-cs2xxx:~/Desktop$ cd data\ structures/
aswin@aswin-HP-Pavilion-Laptop-15-cs2xxx:~/Desktop/data structures$ ./2
enter how many student records you are going to give: 3
enter name of student 1 : aswin
enter regno of aswin : 27
enter mark subject  1 : 56
enter mark subject  2 : 67
enter mark subject  3 : 78
enter mark subject  4 : 89
enter mark subject  5 : 90
enter name of student 2 : arthick
enter regno of arthick : 23
enter mark subject  1 : 89
enter mark subject  2 : 78
enter mark subject  3 : 56
enter mark subject  4 : 78
enter mark subject  5 : 89
enter name of student 3 : praveen
enter regno of praveen : 56
enter mark subject  1 : 90
enter mark subject  2 : 78
enter mark subject  3 : 67
enter mark subject  4 : 67
enter mark subject  5 : 78
1- Insert a record in the front of the list
2- Insert a record at the end of the list
3- Insert a record after a given Regno in the list
4- Search a given record in the list based on Name
5- Delete a given student record
6- Display all students’ record
7- Display the previous and next record of a given student
 2
enter name of student 1 : bala
enter regno of bala : 34
enter mark subject  1 : 56
enter mark subject  2 : 67
enter mark subject  3 : 78
enter mark subject  4 : 90
enter mark subject  5 : 67
press 1 to continue use other operations with given input else press some other number
1
1- Insert a record in the front of the list
2- Insert a record at the end of the list
3- Insert a record after a given Regno in the list
4- Search a given record in the list based on Name
5- Delete a given student record
6- Display all students’ record
7- Display the previous and next record of a given student
 1
enter name of student 1 : nanthan
enter regno of nanthan : 78
enter mark subject  1 : 79
enter mark subject  2 : 67
enter mark subject  3 : 89
enter mark subject  4 : 100
enter mark subject  5 : 89
press 1 to continue use other operations with given input else press some other number
1
1- Insert a record in the front of the list
2- Insert a record at the end of the list
3- Insert a record after a given Regno in the list
4- Search a given record in the list based on Name
5- Delete a given student record
6- Display all students’ record
7- Display the previous and next record of a given student
 7
enter regno of the student to next and previous student detials: 027
record of previous and next student are : 
student 1 : nanthan
regno : 78
marks : 79  67  89  100  89  
student 3 : arthick
regno : 23
marks : 89  78  56  78  89  
press 1 to continue use other operations with given input else press some other number
1
1- Insert a record in the front of the list
2- Insert a record at the end of the list
3- Insert a record after a given Regno in the list
4- Search a given record in the list based on Name
5- Delete a given student record
6- Display all students’ record
7- Display the previous and next record of a given student
 6
     student 1 : nanthan
     regno : 78
     marks : 79  67  89  100  89  
     student 2 : aswin
     regno : 27
     marks : 56  67  78  89  90  
     student 3 : arthick
     regno : 23
     marks : 89  78  56  78  89  
     student 4 : praveen
     regno : 56
     marks : 90  78  67  67  78  
     student 5 : bala
     regno : 34
     marks : 56  67  78  90  67  
press 1 to continue use other operations with given input else press some other number
2
*/

