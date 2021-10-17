#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"functionprototype.h"
#include"fundef.h"

int main()
{
   int flag=1;
  while(flag)
 {
    int choice;
    char exp[100],*res;
    printf("enter exp : ");
    	scanf("%s",exp);
    res=infixtopost(exp);
    if(res==NULL)
    	printf("given equation is invalied\n");
    else
     	printf("%s\n",res);
     	printf("if you want to continue with some other expression press 1 :");
     	scanf("%d",&choice);
      	if(choice!=1)
      		return 0;
   } 
     return 0;
}

/*

SAMPLE  I/O :
aswin@aswin-pavilion-15:~/Desktop/sem3/data structures in c/lab/programs/ex5$ ./inf
enter exp : (2+5)*(3-6)/(7*8)
25+36-*78*/
/*
if you want to continue with some other expression press 1 :1
enter exp : 7-(((3+2)*(6+1))/(5+6)
given equation is invalied
if you want to continue with some other expression press 1 :1
enter exp : (((3+2)*(2+5)
given equation is invalied
if you want to continue with some other expression press 1 :2

*/

