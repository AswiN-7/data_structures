#include<stdio.h>
#include<stdlib.h>
#include"polyprototypes.h"
#include"polyfuns.h"
int main()
{ char var;

 printf("enter variable : ");
 scanf("%c",&var);
while(1)
{
 int choice,repeats,repeatd;
node*p1=NULL;
node*p2=NULL;
node*add=NULL;
node*multiply=NULL;

 printf("enter first polynomial :\n");
 p1=insertlast(p1);
 printf("enter second polynomial :\n");
 p2=insertlast(p2);
     while(1)
     {
        printf("choice 1-addition\n       2-multipilcation\nenter : ");
 	scanf("%d",&choice);
 		if(choice==1)
  		{
  		  add=add_polynomial(p1,p2);
 		   add=sumEqualpow(add);
 		   display(add,var);
 		 }
		else if(choice==2)
 		 {

  		  multiply=multiply_polynomial(p1,p2);
  		  multiply=sumEqualpow(multiply);
                  multiply=sort(multiply);
   		  display(multiply,var);
 		 }
     printf("\nif you want to do other manipliation with above given input \nenter(press) 1 : ");
     scanf("%d",&repeats);
     if(repeats!=1)
      { break;}
    }
printf("if you want opeartions with different inputs\nenter(press) 7 : ");
scanf("%d",&repeatd);
if(repeatd!=7)
  { break;
  }
}

}
/*
 SAMPLE I/O:
aswin@aswin-pavilion-15:~/Desktop/sem3/data structures in c/lab/programs/ex3$ gcc poly.c -o 1
aswin@aswin-pavilion-15:~/Desktop/sem3/data structures in c/lab/programs/ex3$ ./1
enter variable : x
enter first polynomial :
enter how many variabels are going to in this equation 1 : 2
enter coefficient variable 1 : -2
enter exponent of variable 1 : 4
enter coefficient variable 2 : 3
enter exponent of variable 2 : 2
enter second polynomial :
enter how many variabels are going to in this equation 2 : 2
enter coefficient variable 1 : 2
enter exponent of variable 1 : 3
enter coefficient variable 2 : 1
enter exponent of variable 2 : 3
choice 1-addition
       2-multipilcation
enter : 1
-2x^4  + 3x^3  + 3x^2 
if you want to do other manipliation with above given input 
enter(press) 1 : 2
if you want opeartions with different inputs
enter(press) 7 : 7
enter first polynomial :
enter how many variabels are going to in this equation 3 : 5
enter coefficient variable 1 : 3
enter exponent of variable 1 : 12
enter coefficient variable 2 : 8
enter exponent of variable 2 : 8
enter coefficient variable 3 : -22
enter exponent of variable 3 : 4
enter coefficient variable 4 : 3
enter exponent of variable 4 : 1
enter coefficient variable 5 : -7
enter exponent of variable 5 : 0
enter second polynomial :
enter how many variabels are going to in this equation 4 : 5
enter coefficient variable 1 : 7
enter exponent of variable 1 : 14
enter coefficient variable 2 : -10
enter exponent of variable 2 : 9
enter coefficient variable 3 : -8
enter exponent of variable 3 : 8
enter coefficient variable 4 : 6
enter exponent of variable 4 : 5
enter coefficient variable 5 : -9
enter exponent of variable 5 : 1
choice 1-addition
       2-multipilcation
enter : 1
7x^14  + 3x^12  + -10x^9  + 6x^5  + -22x^4  + -6x^1  + -7x^0 
if you want to do other manipliation with above given input 
enter(press) 1 : 1
choice 1-addition
       2-multipilcation
enter : 2
21x^26  + 56x^22  + -30x^21  + -24x^20  + -154x^18  + -62x^17  + -64x^16  + 21x^15  + -49x^14  + 241x^13  + 176x^12  + -30x^10  + -158x^9  + 56x^8  + 18x^6  + 156x^5  + -27x^2  + 63x^1 
if you want to do other manipliation with above given input 
enter(press) 1 : 2
if you want opeartions with different inputs
enter(press) 7 : 2
*/
